<?php

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
