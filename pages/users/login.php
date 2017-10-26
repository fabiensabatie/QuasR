<?php

/**
* Login page | pages/users/login.php
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
    <form action="login.php" method="post">
      <input type="text" name="login" placeholder="Email or Username" required><br>
      <input type="password" name="password" placeholder="Password" required><br>
      <input type="submit" value="Send"><br>
    </form>
  </body>
</HTML>

<?php
  if (!empty($_POST)) {
    $login = check_login_form($_POST);
    if ($login == USERNOTFOUND)
      echo 'User not found';
    else if ($login == WRONGPASSWORD)
      echo 'Wrong password';
    else if ($login == LOGINSUCCESS)
      echo 'Good';
  }
?>
