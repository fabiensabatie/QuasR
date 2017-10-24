<?php

/**
* Project's defines | src/config/defines.php
*
* @package     QuasR.io
* @subpackage  Defines
* @author      Fabien Sabatié <fsabatie@student.42.fr>
* @version     v.1.0 (24/10/2017)
* @copyright   Copyright (c) 2017, QuasR.io
*/

  require_once 'src/includes.php';

  /** MongoDB */

  define('MONGODBSERVER', 'mongodb://127.0.0.1:27017');
  define('DBNAME', 'QuasR');
  define('USERCOLLECTION', 'users');
  define('INTERESTCOLLECTION', 'interests');

?>