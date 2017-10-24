<?php

  namespace UserSpace;
  set_include_path('/home/quasr/QuasR');
  require 'src/includes.php';

?>

<HTML>
  <body>
    <form action="register.php" method="post">
      <input type="text" name="first_name" placeholder="First name" required><br>
      <input type="text" name="last_name" placeholder="Last name" required><br>
      <input type="text" name="username" placeholder="Username" required><br>
      <input type="text" name="email" placeholder="Email" required><br>
      <input type="password" name="password" placeholder="Password" required><br>
      <input type="submit" value="Send"><br>
    </form>
  </body>
</HTML>

<?php
  if (!empty($_POST)) {
    if (checkRegistrationForm($_POST)) { // If the form is valid.
      // Create a new user and assign the $_POST values to it.
      $user             = new cl_user(new \MongoDB\BSON\ObjectID());
      $user->first_name = $_POST['first_name'];
      $user->surname    = $_POST['last_name'];
      $user->email      = $_POST['email'];
      $user->username   = $_POST['username'];
      $user->password   = $_POST['password'];
      $user->insert_user(); // Registers the user
      echo 'You are now registered';
    }
    else { // The form is invalid.
    }
  }
?>
