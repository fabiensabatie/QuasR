<html>
  <body>
    <?php
      set_include_path('/Users/aidenpearce/QuasR/');
      require_once 'src/includes.php';
      if ($_SESSION['isConnected'])
        ft_var_dump($_SESSION);
    ?>
  </body>
</html>
