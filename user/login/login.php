<?php
  set_include_path('/home/quasr/QuasR');
  require_once 'src/includes.php';
?>
<html>
<body>
  <form    id="login_form" method="POST"    action="/user/login/login.php">
    <input type="text"     name="login"
    <?php
      if (isset($_GET['error']) && $_GET['error'] === 'unknown_user')
        echo 'class="error" placeholder="Unknown username"';
      else
        echo 'placeholder="Login"';
    ?>
    required><br>
    <input type="password" name="password"
    <?php
      if (isset($_GET['error']) && $_GET['error'] === 'incorrect_password')
        echo 'class="error" placeholder="Password is incorrect"';
      else
        echo 'placeholder="Password"';
    ?>
    required><br>
    <input type="submit"   class="button"   value="LOGIN">
  </form>
  <?php
  if (ft_form_is_valid($_POST))
    ft_login($_POST);
  ?>
</body>
</html>
