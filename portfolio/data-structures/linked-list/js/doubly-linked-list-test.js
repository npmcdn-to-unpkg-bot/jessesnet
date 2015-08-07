
var expect = require("chai").expect;
var list   = require("./doubly-linked-list.js");

describe("queue", function() {
    it ("should accept items at head", function(){
    	list.push(123);
    	list.push(345);
    	list.push(835);
    	list.push(543);
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

    it ("should be able to pop values", function () {
        expect(list.pop()).to.equal(543);
        expect(list.pop()).to.equal(835);
        expect(list.pop()).to.equal(345);
        expect(list.pop()).to.equal(123);
        expect(list.pop()).to.equal(false);
    });

    it ("should accept items at tail", function(){
        list.reset();
        list.unshift(123);
        list.unshift(345);
        list.unshift(835);
        list.unshift(543);
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

    it ("should be able to shift values", function () {
        expect(list.shift()).to.equal(543);
        expect(list.shift()).to.equal(835);
        expect(list.shift()).to.equal(345);
        expect(list.shift()).to.equal(123);
        expect(list.shift()).to.equal(false);
    });

    it ("should accept items at head or tail", function(){
        list.reset();
        list.unshift(123);
        list.push(345);
        list.push(835);
        list.unshift(543);
    });
   	
    it ("should iterate head to tail or tail to head", function(){

        var i = 0;

        while (list.iterate()) {
            
            switch (i) {
                case 0:
                    expect(list.read()).to.equal(543);
                    break;
                case 1:
                    expect(list.read()).to.equal(123);
                    break;
                case 2:
                    expect(list.read()).to.equal(345);
                    break;
                case 3:
                    expect(list.read()).to.equal(835);
                    break;
            }

            i++;
        }

        i = 0;

        while (list.reverse()) {
            
            switch (i) {
                case 0:
                    expect(list.read()).to.equal(835);
                    break;
                case 1:
                    expect(list.read()).to.equal(345);
                    break;
                case 2:
                    expect(list.read()).to.equal(123);
                    break;
                case 3:
                    expect(list.read()).to.equal(543);
                    break;
            }

            i++;
        }
    });
});
