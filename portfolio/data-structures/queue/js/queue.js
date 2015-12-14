
// FIFO
(function () {

	var exports = module.exports = {};

	var data = [];
   var size = i = 0;

   // O(1)
	exports.enqueue = function (item) {
      data.push(item);
	   size++;  
   };

   // O(1)
   exports.dequeue = function () {

      if (exports.isEmpty()) {
         return undefined;
      }

      // re-indexes after data.shift(), dont use
      var item = data[i];
      delete data[i]; // free memory

      i++;
      size--;

      return item;
	};

   // O(1)
	exports.isEmpty = function () {
		return size == 0 ? true : false;
	};

   // O(1)
	exports.size = function () {
		return size;
	};

   // O(1)
	exports.reset = function () {
		data = [];
      size = i = 0;
	}

   // O(1)
   exports.peek = function () {
      return !exports.isEmpty() ? data[i] : undefined;
   }
   
})();
