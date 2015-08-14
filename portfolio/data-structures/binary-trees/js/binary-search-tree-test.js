
var expect = require("chai").expect;
var tree   = require("./binary-search-tree.js");

describe("binary search tree", function() {

    it ("should accept items at head", function(){
    	tree.push(123);
    	tree.push(345);
    	tree.push(835);
    	tree.push(543);
    });

});
