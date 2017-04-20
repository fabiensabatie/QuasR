// =============================================================================
// BASE SETUP

var express = require('express');
var router = express.Router();
var UserModel  = require('../app/models/users');

// =============================================================================
// GET & POST ROUTES

router.get('/', function(req, res, next) {
    res.send('You have a GET handler');
});

router.post('/', function(req, res, next){

  var user = new UserModel();      // create a new instance of the user model
  user.name = req.body.name;
  user.surname = req.body.surname;
  user.email = req.body.email;
  user.password = req.body.password;
  user.age = req.body.age;
  user.IPaddress = req.body.IPaddress;

  // set the user info (comes from the register request)

  // save the user and check for errors

  user.save(function(err) {
      if (err)
          res.send(err);
      res.json({ message: 'User added!' });
  });
});

// =============================================================================
// PUT & DELETE ROUTES

router.put('/:user_id', function(req, res, next){

  // use our user model to find the user we want
  
  UserModel.findById(req.params.user_id, function(err, user) {

      if (err) res.send(err);

      // Update the user's info

      user.name = req.body.name;
      user.surname = req.body.surname;
      user.email = req.body.email;
      user.password = req.body.password;
      user.age = req.body.age;
      user.IPaddress = req.body.IPaddress;

      // save the user
      user.save(function(err) {
          if (err) res.send(err);

          res.json({ message: 'User data updated!' });
      });

  });
});

// delete the user with the id

router.delete('/:user_id', function(req, res) {
    UserModel.remove({
        _id: req.params.user_id
    },
    function(err, post) {
        if (err) res.send(err);
        res.json({ message: 'Successfully deleted' });
    });
});

// =============================================================================
// EXPORTS THE ROUTES

module.exports = router;
