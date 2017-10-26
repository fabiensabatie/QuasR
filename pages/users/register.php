<?php

/**
* Registration page | pages/users/register.php
*
* @package     QuasR.io
* @subpackage  Pages
* @author      Fabien Sabatié <fsabatie@student.42.fr>
* @version     v.1.0 (24/10/2017)
* @copyright   Copyright (c) 2017, QuasR.io
*/

  namespace UserSpace;
  set_include_path('/home/quasr/QuasR');
  require 'src/includes.php';

?>

<HTML>
  <body>
    <form action="register.php" method="post">
      <input type="text" name="first_name" placeholder="First name" required><br>
      <input type="text" name="surname" placeholder="Last name" required><br>
      <input type="text" name="username" placeholder="Username" required><br>
      <input type="text" name="email" placeholder="Email" required><br>
      <input type="password" name="password" placeholder="Password" required><br>
      <input type="submit" value="Send"><br>
    </form>
  </body>
</HTML>

<?php
  if (!empty($_POST)) {
    if (check_registration_form($_POST)) { // If the form is valid.
      register_user($_POST);
      echo 'You are now registered';
    }
    else { // The form is invalid.
    }
  }
?>
