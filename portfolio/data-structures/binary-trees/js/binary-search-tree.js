
(function () {

	// http://www.cprogramming.com/tutorial/lesson18.html
	var exports = module.exports = {};

	// node template
	var obj    = {
		data:  undefined,
		left:  undefined,
		right: undefined
	};

	var root = undefined;

	/**
	 * private -recursion
	 */
	var insert = function (leaf, node)
	{
		if (node.data < leaf.data) {

			if (typeof leaf.left !== "undefined") {
				insert(lead.left, node);
			}

			leaf.left = node;
		} else if (node.data > leaf.data) {
			if (typeof leaf.right !== "undefined") {
				insert(leaf.right, node);
			}

			leaf.right = node;
		} 
		
		return;
	}

	exports.push = function(data)
	{
		var node  = Object.create(this.obj);
		node.data = data;

		// see if tree has started
		if (typeof root === "undefined") {
			this.root = node;
			return;
		}

		// recursion
		insert(this.root, node);
	}

})();


