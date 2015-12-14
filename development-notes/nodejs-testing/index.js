
require('babel/register')({
    optional: ['bluebirdCoroutines']
});

var Service = require('./Service');
var service = new Service();

service.work();