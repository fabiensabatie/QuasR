<?php

  require 'src/includes.php';

  class cl_post
  {
    public $post_id         = NULL;
    public $date            = NULL;
    public $user_id         = NULL;
    public $user_name       = NULL;
    public $post_content    = NULL;
    public $interest_pos    = NULL;
    public $metas           = NULL;
    public $comments_ids    = NULL;
    public $loaded_comments = NULL;
    public $likes           = NULL;
    public $shares          = NULL;
    public $post_files_id   = NULL;

    function ft_insert()
    {
      $posts_collection = ft_mongo_get_postscollection();
      $posts_collection->insertOne($this);
      return true;
    }
  }

?>
