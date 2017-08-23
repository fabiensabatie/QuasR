<?php
  set_include_path('/Users/aidenpearce/QuasR/');
  require_once 'src/includes.php';
?>
<html>
<body>
  <form    id="register_form" method="POST"     action ="register.php">
    <input type="text"        name="first_name" placeholder="First name"><br>
    <input type="text"        name="surname"    placeholder="Surname"><br>
    <input type="text"        name="username"   placeholder="Username"><br>
    <input type="text"        name="email"      placeholder="Email"><br>
    <input type="password"    name="password"   placeholder="Password"><br>
    <input type="hidden" name="submit" value="true">
    <input type="submit"      value="REGISTER">
  </form>
  <?php
    if ($_POST && ft_check_entries($_POST))
    {
        $user                        = new cl_user();
        $user->main_info             = $_POST;
        $user->main_info['password'] = password_hash($_POST['password'], PASSWORD_BCRYPT);
        if ($user->ft_check_user_integrity() && ft_check_user($user))
        {
          $user->ft_insert_user();
          ft_echo("You are now registered", "green");
        }
    }
    else if (isset($_POST['submit']))
        ft_echo("Please fill in all the fields", "red");
  ?>
</body>
</html>
