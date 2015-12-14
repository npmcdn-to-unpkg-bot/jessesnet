
class Service
{

  constructor() {
    this.obj = function(parms, callback) {
      callback();
    };
  }

  work(val) {
    let params = {Val:val};

    this.obj(params, function(x,y) {
      return x+y;
    });
  }

  complex() {
    let out = this.classer({});

    return out + 7;
  }
}

module.exports = Service;