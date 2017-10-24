<?php

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

?>
