
require('babel/register')({
    // optional: ['bluebirdCoroutines'] 
    optional: ['es7.asyncFunctions']
});

require("./run.js");