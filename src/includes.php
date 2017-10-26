<?php

/**
* Includes | src/includes.php
*
* @package     QuasR.io
* @subpackage  Includes
* @author      Fabien Sabatié <fsabatie@student.42.fr>
* @version     v.1.0 (24/10/2017)
* @copyright   Copyright (c) 2017, QuasR.io
*/

  @session_start();

  require_once 'vendor/autoload.php'; // Composer autoload

  /** Global usage */

  require_once 'src/basic_functions.php';
  require_once 'src/config/defines.php';

  /** MongoDB */

  require_once 'src/config/db.php';

  /** Classes */

  require_once 'src/models/user.php';
  require_once 'src/models/interest.php';

?>
