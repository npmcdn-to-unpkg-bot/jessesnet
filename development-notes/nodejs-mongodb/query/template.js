// http://mongodb.github.io/node-mongodb-native/2.0/overview/quickstart/

var MongoClient = require('mongodb').MongoClient;

MongoClient.connect('mongodb://localhost:27017/weather', function(err, db) {
    if(err) throw err;

    /** DB CALLS GO HERE **/

    /** ================ **/
});
