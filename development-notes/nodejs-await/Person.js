
var request = require('request');

class Person
{
  
  /**
   * @var string
   */
  name;

  constructor(name)
  {
    this.name = name;
  }

  setname(name)
  {
    this.name = name;
  }

  getName() 
  {
    return this.name;
  }

  worklong()
  {
    var self = this;

    console.log(self.name+" is working long...");

    return new Promise(function (resolve, reject) {

      request({
        method: 'GET',
        uri: 'https://google.com'
      }, function(error, response, body){
        console.log(self.name+" is working long (DONE)...");

        resolve();
      });

    });

  }

  async workshort()
  {
    console.log(this.name+" is working short...");
  }
}

module.exports = Person;