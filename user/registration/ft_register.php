<?php
// User registration functions

  require_once 'src/includes.php';

  function  ft_check_user($user)
  {
    $dbname = DBNAME;
    $users  = USERSCOLLECTION;
    $client = ft_mongo_get_client();
    $users  = $client->$dbname->$users;
    $username = $users->findOne(['username' => $user->main_info['username']]);
    if ($username == NULL)
    {
      $email = $users->findOne(['email' => $user->main_info['email']]);
      if ($email == NULL)
        return true;
      else
        ft_echo("Email is already used.", "red");
    }
    else
      ft_echo("Username already exists.", "red");
    return false;
  }

  function  ft_check_entries($post_values)
  {
    array_pop($post_values);
    $user = new cl_user();
    foreach ($user->main_info as $entry => $value) {
      if ($post_values[$entry] == NULL)
        return false;
    }
    return true;
  }


?>
