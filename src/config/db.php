<?php

  require_once 'src/includes.php';

  function getUsersCollection() {
    $connection = new MongoDB\Client(MONGODBSERVER);
    $db = DBNAME;
    $collection = USERCOLLECTION;
    return $connection->$db->$collection;
  }

  ft_var_dump(getUsersCollection()->insertOne(['name' => 'Aiden']));

?>
