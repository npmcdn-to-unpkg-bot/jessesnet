
// FIFO
(function () {

	var exports = module.exports = {};

	var data = [];

   	exports.queue = function (item) {
   		data.push(item);
   	}

   	exports.dequeue = function () {
   		return data.length ? data.shift() : false;
   	}
})();
