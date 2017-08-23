<?php
  set_include_path('/Users/aidenpearce/QuasR/');
  require_once 'src/includes.php';
?>
<html>
<body>
  <form    id="login_form" method="POST"    action="login.php">
    <input type="text"     name="login"     placeholder="Login"><br>
    <input type="password" name="password"  placeholder="Password"><br>
    <input type="submit"   value="Login">
  </form>
  <?php

  if (ft_form_is_valid($_POST))
    ft_login($_POST);
  ?>
</body>
</html>
