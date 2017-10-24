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

  /* User class */

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

  function checkRegistrationForm($post_values) {
    foreach ($post_values as $field) {
      if (!is_string($field))
        return (false); // The form is invalid.
    }
    return (true); // The form is valid.
  }

  /** Create a new user and assign the $_POST values to it,
  * the function then inserts the user into the database.
  */

  function registerUser($_POST) {
    $user             = new cl_user(new \MongoDB\BSON\ObjectID());
    $user->first_name = $_POST['first_name'];
    $user->surname    = $_POST['last_name'];
    $user->email      = $_POST['email'];
    $user->username   = $_POST['username'];
    $user->password   = $_POST['password'];
    $user->insert_user(); // Registers the user
    return (true);
  }

?>