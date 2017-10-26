<?php

/**
* User Class | src/models/user.php
*
* @package     QuasR.io
* @subpackage  Classes
* @author      Fabien Sabatié <fsabatie@student.42.fr>
* @version     v.1.0 (24/10/2017)
* @copyright   Copyright (c) 2017, QuasR.io
*/

  namespace UserSpace;
  require 'src/includes.php';

  /** User class */

  class cl_user {

    /** @var string The MongoDB id constant */
    public $_id        = NULL;
    /** @var string The user's name */
    public $first_name = NULL;
    /** @var string The user's surname */
    public $surname    = NULL;
    /** @var string The user's email. */
    public $email      = NULL;
    /** @var string The user's username. */
    public $username   = NULL;
    /** @var string The user's password. */
    public $password   = NULL;
    /** @var string The user's role. (REGULAR or ADMIN) */
    public $role       = REGULAR;
    /** @var array The user's interests ids. */
    public $interests  = array();

    /** Construct method */

    public function __construct($_id){
      $this->_id = $_id;
    }

    /** Hashes the users' password before inserting them
    * into the database */

    public function insert_user() {
      $usercollection = getUsersCollection();
      $this->password = password_hash($this->password, PASSWORD_BCRYPT);
      $usercollection->insertOne($this);
    }
  }

  /** Checks the user's data from the registration form */
  function check_registration_form(array $post_values) {
    foreach ($post_values as $field) {
      if (!is_string($field))
        return (false); // The form is invalid.
    }
    return (true); // The form is valid.
  }

  /** Create a new user and assign the $_POST values to it,
  * the function then inserts the user into the database.
  */
  function register_user(array $post_values) {
    $user             = new cl_user(new \MongoDB\BSON\ObjectID());
    $user->first_name = $post_values['first_name'];
    $user->surname    = $post_values['surname'];
    $user->email      = $post_values['email'];
    $user->username   = $post_values['username'];
    $user->password   = $post_values['password'];
    $user->insert_user(); // Registers the user
    return (true);
  }

  /** Sets the PHP session variables if login was succesfull .*/
  function set_session_variables(\MongoDB\Model\BSONDocument $user) {
    $user_info        = array(
      'id'            => $user['_id'],
      'username'      => $user['username'],
      'names'         => $user['first_name'] . ' ' . $user['surname'],
      'email'         => $user['email'],
      'role'          => $user['role']
    );
    $_SESSION['user'] = $user_info;
  }

  /** Checks the user's data from the login form. */
  function check_login_form(array $post_values) {
    $user = $post_values['login'];
    if (!$result = \getUsersCollection()->findOne(['username' => $user])) // Tries to find user by username
      if (!$result = \getUsersCollection()->findOne(['email' => $user])) // Tries to find user by email
        return (USERNOTFOUND);
    if (password_verify($post_values['password'], $result['password'])) // Passwords match
        set_session_variables($result); // Sets the session's variables
    else return (WRONGPASSWORD);
    return (LOGINSUCCESS); // The form is valid.
  }

?>
