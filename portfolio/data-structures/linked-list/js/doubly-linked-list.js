
(function () {

	var exports = module.exports = {};

	// object template
	var node    = {
		data: undefined,
		next: undefined,
		prev: undefined
	};

	/**
	 * @todo - Test partial iterations, need for flags for different directions
	 */
	var iterate = false;	 
	var active  = undefined; // used with iterations
	var head    = undefined; // most recent
	var tail    = undefined; // oldest

	// 0(1) - read current node
	exports.read = function () {
		if (typeof active == "undefined") {
			return undefined;
		}

		return active.data;
	}

	//  0(n) - iterate tail to head
	exports.iterate = function () {
		
		// verify starting point
		if (typeof tail == "undefined") {
			return false;
		}

		// see if iteration has started
		if (!iterate) {
			active  = tail;
			iterate = true;
			return true;
		}

		// verify there is a next
		if (typeof active.next == "undefined") {
			iterate = false; // complete iteration, reset
			return false;
		}

		// update active node
		active = active.next;
		return true;
	}

	//  0(n) - iterate head to tail
	exports.reverse = function () {
		// verify starting point
		if (typeof head == "undefined") {
			return false;
		}

		// see if iteration has started
		if (!iterate) {
			active  = head;
			iterate = true;
			return true;
		}

		// verify there is a next
		if (typeof active.prev == "undefined") {
			iterate = false; // complete iteration, reset
			return false;
		}

		// update active node
		active = active.prev;
		return true;
	}

	//  0(1)
	exports.push = function (data) {
		var item  = Object.create(node);
		item.data = data;

		// if head exists, update links
		if (typeof head != "undefined") {
			head.next = item; // point current to this one
			item.prev = head; // point backwards
		}

		head = item;

		// single node is both head and tail
		if (typeof tail == "undefined") {
			tail = item;
		}
	}

	// 0(1)
	exports.pop = function (data) {
		if (typeof head == "undefined") {
			return false;
		}

		var current = head;

		// update previous node
		if (typeof head.prev !== "undefined") {
			head = head.prev;
			head.next = undefined;
		} else {
			// no previous, no head
			head = undefined;
		}

		return current.data;
	}

	// 0(1)
	exports.unshift = function (data) {
		var item = Object.create(node);
		item.data = data;

		if (typeof tail != "undefined") {
			tail.prev = item; // point current to this one
			item.next = tail; // point backwards
		}

		tail = item;

		// single node is both head and tail
		if (typeof head == "undefined") {
			head = item;
		}
	}

	// 0(1)
	exports.shift = function (data) {
		if (typeof tail == "undefined") {
			return false;
		}

		var current = tail;

		// update next node
		if (typeof tail.next !== "undefined") {
			tail = tail.next;
			tail.prev = undefined;
		} else {
			// no previous, no tail
			tail = undefined;
		}

		return current.data;
	}

	exports.sort = function () {
		
	}

	// 0(1) - reset the list
	exports.reset = function () {
		iterate = false;
		active  = head = tail = undefined;
	}

})();


