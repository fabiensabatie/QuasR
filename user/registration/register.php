<?php
  set_include_path('/home/quasr/QuasR/');
  require_once 'src/includes.php';
?>
<html>
<body>
  <form    id="register_form" method="POST"     action ="user/registration/register.php">
    <input type="text"        name="first_name" placeholder="First name" required><br>
    <input type="text"        name="surname"    placeholder="Surname" required><br>
    <input type="text"        name="username"
    <?php
      if (isset($_GET['error']) && $_GET['error'] === 'used_username')
        echo 'class="error" placeholder="Already taken"';
      else
        echo 'placeholder="Username"';
    ?>
    required><br>
    <input type="text"        name="email"
    <?php
      if (isset($_GET['error']) && $_GET['error'] === 'used_email')
        echo 'class="error" placeholder="Already used"';
      else
        echo 'placeholder="Email"';
    ?>
    required><br>
    <input type="password"    name="password"   placeholder="Password" required><br>
    <input type="hidden" name="submit" value="true">
    <input type="submit"      value="REGISTER">
  </form>
  <?php
    if ($_POST && ft_check_entries($_POST))
    {
        $user                        = new cl_user();
        $user->main_info             = $_POST;
        $user->main_info['password'] = password_hash($_POST['password'], PASSWORD_BCRYPT);
        array_pop($user->main_info);
        if ($user->ft_check_user_integrity() && ft_check_user($user))
        {
          $user->ft_insert_user();
          header("Location: /?registered");
        }
    }
  ?>
</body>
</html>
