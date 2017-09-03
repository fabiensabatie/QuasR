<?php
# @Author: aidenpearce
# @Date:   2017-08-11T23:06:12+02:00
# @Last modified by:   aidenpearce
# @Last modified time: 2017-08-11T23:06:16+02:00
# This document sets the user's class and methods.

  require 'src/includes.php';

  class cl_user
  {
    public $main_info  = array(
      'first_name' => NULL,
      'surname'    => NULL,
      'username'   => NULL,
      'email'      => NULL,
      'password'   => NULL
    );

    public $profile = array(
      'profile' => array (
        'cover_image' => NULL,
        'profile_image' => NULL
      )
    );

    public $user_rank = NULL;

    function ft_check_user_integrity()
    {
      $user_info = $this->main_info;
      foreach ($user_info as $property) {
        if ($property == NULL)
          return false;
      }
      return true;
    }

    function ft_insert_user()
    {
      $users         = ft_mongo_get_usercollection();
      $inserted_user = $users->insertOne($this->main_info);
      return $inserted_user;
    }
  }

  function ft_find_by_username($username)
  {
    $users = ft_mongo_get_usercollection();
    $user  = $users->findOne(['username' => $username]);
    return $user;
  }

  function ft_find_by_email($email)
  {
    $users = ft_mongo_get_usercollection();
    $user  = $users->findOne(['email' => $email]);
    return $user;
  }

?>
