<?php

class Investigation
{
	/**
	 * @var Graph
	 */
    private $graph;

    /**
     * @var array
     */
    private $timelines = [];

    /**
     * @param Graph
     */
    public function __construct(Graph $graph)
    {
        $this->graph = $graph;
    }

    /**
     * @param Witness
     */
    public function interrogate(Witness $witness)
    {
    	$timeline = [];
    	$events   = $witness->events();

        foreach ($events as $k => $event) {

            // always have to look back with first event
            if ($k == 0) {
                $timeline = $this->validatePastEvent($event);
            }

            // include what witness saw
            $timeline[] = $event;

            // see if events diverge moving forward
            $diverge = $this->validateFutureEvent($event, isset($events[($k+1)])?$events[($k+1)]:null);

            // track the timeline
            $timeline = array_merge($timeline, $diverge);
        }

        $this->timelines[] = json_encode($timeline);
    }

    /**
     * @return array
     */
    public function prosecute()
    {
    	return array_unique($this->timelines);
    }

     /**
     * Validate timeline with past events
     * @param  string
     * @return array
     */
    private function validatePastEvent($event)
    {
    	$t  = [];
    	$in = $this->graph->edgesIn($event);

    	// can only use vertexes is at most two versions of story
    	while (count($in) == 1 || count($in) == 2) {
    		// if a single preceding event, can use it, unless connects somewhere else
    	    if (count($in) == 1 && count($this->graph->edgesOut($in[0])) == 1) {
    	        array_unshift($t, $in[0]);
    	        $in = $this->graph->edgesIn($in[0]);

    	    // if two preceding events, can use if connected
    	    } else {

    	        // see if nodes are connectd
    	        if ($this->graph->isConnected($in[0], $in[1]) && count($this->graph->edgesIn($in[1])) == 1) {
    	            array_unshift($t, $in[1]);
    	            array_unshift($t, $in[0]);
    	            $in  = $this->graph->edgesIn($in[0]);
    	            continue;
    	        }
    	        if ($this->graph->isConnected($in[1], $in[0]) && count($this->graph->edgesIn($in[0])) == 1) {
    	            array_unshift($t, $in[0]);
    	            array_unshift($t, $in[1]);
    	            $in  = $this->graph->edgesIn($in[1]);
    	            continue;
    	        }

    	        // no more options
    	        return $t;
    	    }
    	}

    	// if there are multiple accounts can only use if they all match
    	if (count($in) > 2 && $this->graph->match($in)) {
    		array_unshift($t, $in[0]);
    	}

    	return $t;
    }

    /**
     * Validate timeline with future events
     * @param  string
     * @param  string
     * @return array
     */
    private function validateFutureEvent($event, $future=null)
    {
    	$t   = [];
    	$out = $this->graph->edgesOut($event);
    	
    	// with only one or two divergences, can make assumptions
    	while (count($out) == 1 || count($out) == 2) {
    	    
    	    // for two choices
    	    if (!is_null($future) && count($out) == 2) {

    	        // dont check self, verify connection, can only be one fork
    	        if ($future != $out[1] && $this->graph->isConnected($out[1], $future) && count($this->graph->edgesOut($out[1])) == 1) {
    	            array_push($t, $out[1]);
    	            $out  = $this->graph->edgesOut($out[1]);
    	            continue;
    	        }
    	        if ($future != $out[0] && $this->graph->isConnected($out[0], $future) && count($this->graph->edgesOut($out[0])) == 1) {
    	            array_push($t, $out[0]);
    	            $out  = $this->graph->edgesOut($out[0]);
    	            continue;
    	        }

    	        // no options
    	        return $t;
    	    }

    	    // for a single choice
    	    if (!is_null($future) && count($out) == 1) {
    	    	// can use it if its connected to next element at some point
    	    	if ($this->graph->isConnected($out[0], $future)) {
    	    		array_push($t, $out[0]);
    	    		$out  = $this->graph->edgesOut($out[0]);
    	            continue;
    	    	}
    	    }

    	    // end of current timeline, can still use single event
    	    if (is_null($future) && count($out) == 1) {
    	        array_push($t, $out[0]);
    	        $out = $this->graph->edgesOut($out[0]);
    	        continue;
    	    }

    	    // end of current timeline, multiple choices, use if end up in same location
    	    if (is_null($future) && count($out) == 2) {
    	    	if ($this->graph->isConnected($out[0], $out[1])) {
    	    		array_push($t, $out[0]);
    	            $out  = $this->graph->edgesOut($out[0]);
    	            continue;
    	    	}
    	    	if ($this->graph->isConnected($out[1], $out[0])) {
    	    		array_push($t, $out[1]);
    	            $out  = $this->graph->edgesOut($out[1]);
    	            continue;
    	    	}
    	    }

    	    // end of timeline, two paths, can use if they match exactly
    	    if (is_null($future) && count($out) == 2 && $this->graph->match($out)) {
    	    	array_push($t, $out[0]);
    	    	return $t;
    	    }    

    	    // no more checks
    	    return $t;
    	}

    	// if there are multiple accounts, can only use if they all match
    	if (is_null($future) && count($out) > 2 && $this->graph->match($out)) {
    		array_push($t, $out[0]);
    	}

    	return $t;
    }

}
