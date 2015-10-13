
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

  async worklong()
  {
    var self = this;

    console.log(self.name+" is working long...");

    await request({
        method: 'GET',
        uri: 'https://google.com'
    }, async function(error, response, body){
      console.log(self.name+" is working long (DONE)...");
    });
  }

  async workshort()
  {
    console.log(this.name+" is working short...");
  }
}

module.exports = Person;