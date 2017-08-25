<html>
  <head>
    <title>Welcome to QuasR.io !</title>
    <link rel="stylesheet" type="text/css" href="/assets/css/index_main.css">
  </head>
  <body>
    <div id="logo_container">
      <img class="logo" src="/assets/images/logo_200x200.png">
    </div>
    <?php
      require_once 'src/includes.php';
      if (isset($_GET['registered']))
	      ft_echo('<span class="registered">You are now registered !</span>', 'white');
      else if (isset($_SESSION['isConnected']))
	      ft_echo('<span class="connected">You are now connected !</span>', 'white');
      else {
        ?>
        <div id="forms_container">
          <div id="login">
            <?php include 'user/login/login.php'; ?>
          </div>
          <div id="registration">
            <?php include 'user/registration/register.php'; ?>
          </div>
        </div>
        <?php
      }
    ?>
  </body>
</html>
