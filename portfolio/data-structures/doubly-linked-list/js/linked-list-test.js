
var expect = require("chai").expect;
var list   = require("./linked-list.js");

describe("queue", function() {
    it ("should accept items at head", function(){
    	list.insertLast(123);
    	list.insertLast(345);
    	list.insertLast(835);
    	list.insertLast(543);
    });

    it ("should iterate tail to head", function(){
    	var i = 0;

    	while (list.iterate()) {
    		
    		switch (i) {
    			case 0:
    				expect(list.read()).to.equal(123);
    				break;
    			case 1:
    				expect(list.read()).to.equal(345);
    				break;
    			case 2:
    				expect(list.read()).to.equal(835);
    				break;
    			case 3:
    				expect(list.read()).to.equal(543);
    				break;
    		}

    		i++;
    	}
    });
   	
});
