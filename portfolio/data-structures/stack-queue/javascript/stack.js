
// LIFO
(function () {

	var exports = module.exports = {};

	var data = [];

   	exports.push = function (item) {
   		data.push(item);
   	}

   	exports.pop = function () {
   		return data.length ? data.pop() : false;
   	}
})();
