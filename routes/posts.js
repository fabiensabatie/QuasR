// =============================================================================
// BASE SETUP

var express = require('express');
var router = express.Router();
var PostModel  = require('../app/models/posts');

// =============================================================================
// GET & POST ROUTES

router.get('/', function(req, res, next) {
    res.send('You have a GET handler');
});

router.post('/', function(req, res, next){

  var post = new PostModel();      // create a new instance of the post model

  post.author_id          = req.body.userID;
  post.content.body       = req.body.content.body;
  post.content.images.url = req.body.content.images.url;
  post.comment            = req.body.comments;

  // set the post info (comes from the register request)

  // save the post and check for errors

  post.save(function(err) {
      if (err)
          res.send(err);
      res.json({ message: 'Post added!' });
  });
});

// =============================================================================
// PUT & DELETE ROUTES

router.put('/:post_id', function(req, res, next){

  // use our post model to find the post we want
  PostModel.findById(req.params.post_id, function(err, post) {

      if (err) res.send(err);

      // Update the post's info

      post.author_id          = req.body.userID;
      post.content.body       = req.body.content.body;
      post.content.images.url = req.body.content.images.url;
      post.comment            = req.body.comments;

      // save the post
      post.save(function(err) {
          if (err) res.send(err);

          res.json({ message: 'Post data updated!' });
      });

  });
});

// delete the post with the id

router.delete('/:post_id', function(req, res) {
    PostModel.remove({
        _id: req.params.post_id
    },
    function(err, post) {
        if (err) res.send(err);
        res.json({ message: 'Successfully deleted' });
    });
});

// =============================================================================
// EXPORTS THE ROUTES

module.exports = router;
