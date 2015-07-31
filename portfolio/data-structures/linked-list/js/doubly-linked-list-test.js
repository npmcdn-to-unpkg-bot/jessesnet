
var expect = require("chai").expect;
var list   = require("./doubly-linked-list.js");

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

        list.reset();
    });

    it ("should accept items at tail", function(){
        list.insertFirst(123);
        list.insertFirst(345);
        list.insertFirst(835);
        list.insertFirst(543);
    });

    it ("should iterate head to tail", function(){
        var i = 0;

        while (list.reverse()) {
            
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

    it ("should accept items at head or tail", function(){
        list.insertFirst(123);
        list.insertLast(345);
        list.insertLast(835);
        list.insertFirst(543);
    });
   	
    it ("should iterate head to tail or tail to head", function(){
        var i = 0;

        while (list.iterate()) {
            
            switch (i) {
                case 0:
                    expect(list.read()).to.equal(543);
                    break;
                case 1:
                    expect(list.read()).to.equal(835);
                    break;
                case 2:
                    expect(list.read()).to.equal(345);
                    break;
                case 3:
                    expect(list.read()).to.equal(123);
                    break;
            }

            i++;
        }

        i = 0;

        while (list.reverse()) {
            
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
