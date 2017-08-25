<?php
  set_include_path('/home/quasr/QuasR');
  require_once 'src/includes.php';
  ft_check_if_logged();
?>

<html>
<body>
  <form name ="create_interest" method="POST" action="set_interests.php">
    <?php ft_create_interestlist(); ?>
    <br>Can't find an interest in the list ?<br>
    <a href="propose_interest.php">Propose an interest !</a><br>
  </form>
  <?php
    if (isset($_POST['submit']) && $_POST['submit'] == true)

  ?>
</body>
</html>
