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
    <link rel="stylesheet" type="text/css" href="/assets/css/messages_sidebar.css">
  </head>
  <body>
    <div id="main_container">
      <?php require_once 'src/sidebar_menu.php'; ?>
      <div id="social_container">
        <div id="cover_image"><img src="<?php echo ft_get_cover_image(); ?>"/></div>
        <div id="profile_image"><img src="<?php echo ft_get_profile_image(); ?>"/></div>
        <div id="user_info">
          <span id="user_names_banner">
            <?php echo $_SESSION['user_first_name'] . ' ' . $_SESSION['user_surname']; ?>
          </span>
          <span id="username_banner">
            (@<?php echo $_SESSION['username']; ?>)
          </span>
        </div>
        <?php
          echo '<span class="social_content">Hello '
          . $_SESSION["user_first_name"] . ', welcome back to QuasR !<br><br>'
          . '<img src="/assets/images/rocks_and_rocket.png"></span>';
        ?>
      </div>

      <div id="messages_sidebar"></div>
    </div>
  </body>
</html>
