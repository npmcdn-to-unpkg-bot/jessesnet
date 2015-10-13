
require('babel/register')({
    optional: ['bluebirdCoroutines']
});

// mock a api call
var controller = require('./src/services/controller.js');
controller.action();

