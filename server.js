// =============================================================================
// BASE SETUP

var express    = require('express');
var app        = express();
var bodyParser = require('body-parser');
var mongoose   = require('mongoose');


mongoose.connect('mongodb://localhost:27017/QuasR'); // connect to our database

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(express.static(__dirname + '/public'));

var port = process.env.PORT || 8080;

// =============================================================================
// BASIC ROUTES

app.get('/', function(req, res, next){
  res.sendFile(__dirname + '/pages/index.html')
});

// =============================================================================
// USERS ROUTES

var users      = require('./routes/users');
app.use('/api/users',  users);

// =============================================================================
// POSTS ROUTES

var posts      = require('./routes/posts');
app.use('/api/posts',  posts);

// =============================================================================
// START THE SERVER

app.listen(port);
console.log('Magic happens on port ' + port);
