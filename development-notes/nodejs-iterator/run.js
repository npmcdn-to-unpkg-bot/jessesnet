
let SimpleBook = require('./SimpleBook');
let simplebook = new SimpleBook();

console.log("SIMPLE BOOK");

for (let person of simplebook) {
  console.log("person:", person.name);
  console.log("info:", `${person.info.city}, ${person.info.state}`);
}

console.log("\nADDRESS BOOK");

let AdressBook = require('./AdressBook');
let adressbook = new AdressBook();

for (let person of adressbook) {
  console.log("person:", person.name);
  console.log("info:", `${person.info.city}, ${person.info.state}`);
}