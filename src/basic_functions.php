<?php

/**
* Basic functions | src/basic_functions.php
*
* @package     QuasR.io
* @subpackage  Functions
* @author      Fabien Sabatié <fsabatie@student.42.fr>
* @version     v.1.0 (24/10/2017)
* @copyright   Copyright (c) 2017, QuasR.io
*/

  require_once 'src/includes.php';

  /* ft_var_dump - Adds the HTML <pre> tags to php var_dump function */

  function ft_var_dump($var)
  {
    echo '<pre>';
    var_dump($var);
    echo '</pre>';
  }

?>
