
(function () {

	var exports = module.exports = {};

	// object template
	var node    = {
		data: undefined,
		next: undefined,
		prev: undefined
	};

	var iterate = false;
	var active  = head = tail = undefined;

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

	//  0(1) - add to the "head", end of list
	exports.insertLast = function (data) {
		var item  = Object.create(node);
		item.data = data;

		if (typeof active != "undefined") {
			active.next = item;   // point current to this one
			item.prev   = active; // point backwards
		}

		active = item;
		head   = item;

		if (typeof tail == "undefined") {
			tail = item;
		}
	}

	// 0(1) - add to the "tail", front of list
	exports.insertFirst = function (e) {
		var item = Object.create(node);
		item.data = e;

		if (typeof active != "undefined") {
			active.prev = item;   // point current to this one
			item.next   = active; // point backwards
		}

		active = item;
		tail   = item;

		if (typeof head == "undefined") {
			head = item;
		}
	}

	exports.sort = function () {
		
	}

	// 0(1) - reset the list
	exports.reset = function () {
		iterate = false;
		active  = head = tail = undefined;
	}

})();


