
var Person = require('./Person.js');

class Controller
{
  async action()
  {
    let lisa = new Person('lisa');
    
    await lisa.worklong();
    lisa.workshort();

    console.log('continuing on....');
  }
}

module.exports = Controller;