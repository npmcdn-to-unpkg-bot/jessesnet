<?php

namespace Broker;

use Proc\Factory;

/**
 * RabbitMQ Handler
 *
 * @package Development Notes
 * @author  Jesse Cascio <jessecascio@gmail.com>
 * @see     jessesnet.com/development-notes
 */
class RabbitHandler
{	
	/**
	 * @var PhpAmqpLib\Message\AMQPMessage
	 */
	private $AMQPMessage;

	/**
	 * Consume the RabbitMQ messages
	 * @param PhpAmqpLib\Message\AMQPMessage
	 */
	public function consume($AMQPMessage)
	{
		$this->AMQPMessage = $AMQPMessage;

		$body = json_decode($this->AMQPMessage->body, true);
		
		// make sure worker type is set
		if (isset($body['job_type'])) {
			// run the job, workers should never die
			try {
				$Worker = Factory::get($body['job_type'], $body);
				$Worker->run();	
			} catch (\Exception $e) {
				// log errors
				// @todo Use monolog
			}
			
		} else {
			// l og unable to process
		}

		// always acknowledge so jobs dont get stuck
		$this->acknowledge();
	}

	/**
	 * Acknowledge the message has been consumed
	 */
	public function acknowledge()
	{
		$this->AMQPMessage->delivery_info['channel']->basic_ack($this->AMQPMessage->delivery_info['delivery_tag']);
		unset($this->AMQPMessage); 
	}
}