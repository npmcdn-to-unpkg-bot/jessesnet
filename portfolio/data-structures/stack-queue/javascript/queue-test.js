
var expect = require("chai").expect;
var queue  = require("./queue.js");

describe("queue", function() {
    it ("should accept items", function(){
    	queue.queue(1);
    	queue.queue(2);
    	queue.queue(3);
   	});

   	it ("should remove in FIFO", function() {
   		expect(queue.dequeue()).to.equal(1);
   		expect(queue.dequeue()).to.equal(2);
   		expect(queue.dequeue()).to.equal(3);
   	});
});
