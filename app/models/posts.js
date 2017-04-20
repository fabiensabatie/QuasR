// app/models/posts.js

var mongoose     = require('mongoose');
var Schema       = mongoose.Schema;

var PostSchema   = new Schema({
      author_id: String,
      content: {
        body: String,
        images: {
          url: [String]
        }
      },
      date: { type: Date, default: Date.now },
      comments: [{
        author_id: String,
        body: String
      }]
    });

module.exports = mongoose.model('Post', PostSchema);
