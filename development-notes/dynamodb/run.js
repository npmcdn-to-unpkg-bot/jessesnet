
// http://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html
console.log('letssss goo...');

let AWS = require('aws-sdk');

/*
AWS.config.update({
  "accessKeyId": "AKIAIHHQMKY3FYAO3QZA", 
  "secretAccessKey": "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", 
  "region": "us-west-2" 
});
*/

let dynamodb = new AWS.DynamoDB({
  apiVersion: 'latest',
  endpoint: 'http://localhost:8000'
});
