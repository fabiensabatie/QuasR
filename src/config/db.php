<?php

/**
* MongoDB Functions | src/config/db.php
*
* @package     QuasR.io
* @subpackage  Functions
* @author      Fabien Sabatié <fsabatie@student.42.fr>
* @version     v.1.0 (24/10/2017)
* @copyright   Copyright (c) 2017, QuasR.io
*/

  require_once 'src/includes.php';

  /** Returns the MongoDB users collection */

  function getUsersCollection() {
    $connection = new MongoDB\Client(MONGODBSERVER);
    $db = DBNAME;
    $collection = USERCOLLECTION;
    return $connection->$db->$collection;
  }

  /** Returns the MongoDB interests collection */

  function getInterestsCollection() {
    $connection = new MongoDB\Client(MONGODBSERVER);
    $db = DBNAME;
    $collection = INTERESTCOLLECTION;
    return $connection->$db->$collection;
  }

?>