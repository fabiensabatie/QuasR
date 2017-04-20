// app/models/users.js

var mongoose     = require('mongoose');
var Schema       = mongoose.Schema;

var UserSchema   = new Schema({
      name: String,
      surname: String,
      email: String,
      password: String,
      age: Number,
      IPaddress: String
    });

module.exports = mongoose.model('User', UserSchema);
