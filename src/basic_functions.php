<?php

  require_once 'src/includes.php';

  /* ft_var_dump - Adds the HTML <pre> tags to php var_dump function */

  function ft_var_dump($var)
  {
    echo '<pre>';
    var_dump($var);
    echo '</pre>';
  }

?>
