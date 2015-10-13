
var Person = require('./Person.js');

class Controller
{
  action()
  {
    let lisa = new Person('lisa');
    
    lisa.worklong();
    lisa.workshort();

    console.log('continuing on....');
  }
}

module.exports = Controller;