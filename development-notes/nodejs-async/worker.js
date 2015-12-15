
var iteration = 5000000000;


// handled after the for loop

/* -- keeps it alive
process.on('message', function(m) {
  console.log('CHILD got message:', m);
});
*/

for (var i=0; i<iteration; i++) {

}

console.log('math...');
process.send(78);
