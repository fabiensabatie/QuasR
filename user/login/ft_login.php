<?php

  require_once 'src/includes.php';

  function ft_form_is_valid($post_values)
  {
    if (isset($post_values['login']) &&
    isset($post_values['password']))
    {
      if (!empty($post_values['login']) &&
      !empty($post_values['password']))
        return true;
      else
        ft_echo("Please fill in all the fields", "red");
    }
    return false;
  }

  function ft_set_session_variables($user)
  {
    $_SESSION["isConnected"]     = true;
    $_SESSION["user_id"]         = $user->_id;
    $_SESSION["user_first_name"] = $user->first_name;
    $_SESSION["username"]        = $user->username;
  }

  function ft_compare_passwords($password, $user)
  {
    if (password_verify($password, $user->password))
    {
      ft_set_session_variables($user);
      ft_echo("Login successfull", "green");
      return true;
    }
    else
      ft_echo("Password incorrect.", "red");
    return false;
  }

  function ft_login($post_values)
  {
    if ($user = ft_find_by_username($post_values['login']))
      return ft_compare_passwords($post_values['password'], $user);
    elseif ($user = ft_find_by_email($post_values['login']))
      return ft_compare_passwords($post_values['password'], $user);
    else
      ft_echo("User not found.", "red");
    return false;
  }
?>
