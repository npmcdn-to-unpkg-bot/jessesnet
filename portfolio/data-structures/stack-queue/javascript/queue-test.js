
var q = require("./queue.js");

q.queue(1);
q.queue(2);
q.queue(3);

console.log(q.dequeue());
console.log(q.dequeue());

q.queue(1);

console.log(q.dequeue());
console.log(q.dequeue());