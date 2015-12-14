
let iteration = 5000000000;

async function work() {
  for (let i=0; i<iteration; i++) {

  }
  console.log('math...');
}

/**
 * 1
 */
work();
console.log('done...');

/**
 *
 */
// setTimeout(work, 0);
// console.log('done...');

/**
 *
 */
// setTimeout(work, 0);
// setTimeout(work, 0);
// console.log('done...');

/**
 *
 */
/*
let async = require('async')

let q = async.queue(function (callback) {
  callback();
}, 5);

q.push(work); // still singled
q.push(work);

console.log('done...');
*/

/**
 *
 */
/*
let process = require('child_process');

process.fork(__dirname+"/worker.js");
process.fork(__dirname+"/worker.js");

console.log('done');
*/

// require('os').cpus().length;