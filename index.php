<html>
  <body>
    <?php
      require_once 'src/includes.php';
      if (isset($_SESSION['isConnected']))
	      ft_var_dump($_SESSION);
      echo 'IT WORKS ! :)';
    ?>
  </body>
</html>
