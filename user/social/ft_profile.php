<?php

  set_include_path('/home/quasr/QuasR');
  require_once 'src/includes.php';

  function ft_get_cover_image()
  {
    /*$profile          = array(
      'profile'       => array(
        'cover_image' => '/assets/images/test.jpg',
        'profile_image' => '/assets/images/profile_image.png'
      )
    );*/

    $user_collection = ft_mongo_get_usercollection();
    //$user            = $user_collection->updateOne(array('_id' => $_SESSION['user_id']), ['$set' => $profile]);
    $user            = $user_collection->findOne(["_id" => $_SESSION['user_id']]);

    return $user['profile']['cover_image'];
  }

  function ft_get_profile_image()
  {
    $user_collection = ft_mongo_get_usercollection();
    $user            = $user_collection->findOne(["_id" => $_SESSION['user_id']]);
    return $user['profile']['profile_image'];
  }

?>
