

var expect = require("chai").expect;
var stack  = require("./stack.js");

describe("stack", function() {
    it ("should accept items", function(){
    	stack.push(1);
    	stack.push(2);
    	stack.push(3);
   	});

   	it ("should remove in LIFO", function() {
   		expect(stack.pop()).to.equal(3);
   		expect(stack.pop()).to.equal(2);
   		expect(stack.pop()).to.equal(1);
   	});
});
