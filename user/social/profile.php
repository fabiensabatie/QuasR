<?php
  set_include_path('/home/quasr/QuasR');
  require_once 'src/includes.php';
  if(!isset($_SESSION['isConnected']))
    header("Location: /");
?>

<html>
  <head>
    <title>QuasR | Social</title>
    <link rel="stylesheet" type="text/css" href="/assets/css/main_social.css">
    <link rel="stylesheet" type="text/css" href="/assets/css/side_menu_main.css">
  </head>
  <body>
    <div id="main_container">
      <?php require_once 'src/sidebar_menu.php'; ?>
      <div id="social_container">
        <?php
          echo 'Hello ' . $_SESSION["user_first_name"] . ', your username is ' . $_SESSION["username"] . '.<br>';
        ?>
        Click <a href="/?disconnect" class="disconnect">here</a> to disconnect.
      </div>
    </div>
  </body>
</html>
