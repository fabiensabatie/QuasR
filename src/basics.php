<?php

  require_once 'src/includes.php';
  session_start();

  //MongoDB functions.

  function ft_mongo_get_client()
  {
    $client = new MongoDB\Client(MONGOSERVER);
    return $client;
  }

  function ft_mongo_get_usercollection()
  {
    $dbname = DBNAME;
    $users  = USERSCOLLECTION;
    $client = ft_mongo_get_client();
    $users  = $client->$dbname->users;
    return $users;
  }

  function ft_mongo_get_interestcollection()
  {
    $dbname    = DBNAME;
    $interests = INTERESTSCOLLECTION;
    $client    = ft_mongo_get_client();
    $interests = $client->$dbname->$interests;
    return $interests;
  }

  function ft_mongo_get_postscollection()
  {
    $dbname = DBNAME;
    $posts  = POSTSCOLLECTION;
    $client = ft_mongo_get_client();
    $posts  = $client->$dbname->$posts;
    return $posts;
  }

  function ft_mongo_get_interestlist()
  {
    $dbname    = DBNAME;
    $interests = INTERESTLIST;
    $client    = ft_mongo_get_client();
    $interests = $client->$dbname->$interests;
    return $interests;
  }

  function ft_mongo_get_objectid()
  {
    return new MongoDB\BSON\ObjectID();
  }

  function ft_convert_M2C($mongo_object, $class_object)
  {
    foreach ($mongo_object as $property_name => $value)
      $class_object->{$property_name} = $value;
    return $class_object;
  }

  //Basic functions.

  function ft_pretty_json($json)
  {
    header('Content-Type: application/json');
    echo json_encode($json);
  }

  function ft_var_dump($var)
  {
    echo '<pre>';
    var_dump($var);
    echo '</pre>';
  }

  function ft_echo($string, $color = "#000")
  {
    echo '<font color="' . $color . '">';
    echo $string;
    echo '</font>';
  }

  //Behaviour management.

  function ft_disconnect()
  {
    if (isset($_SESSION["isConnected"]) && $_SESSION["isConnected"])
    {
      if (isset($_GET['disconnect']))
        session_destroy();
    }
  }

  function ft_check_if_logged()
  {
    if(!($_SESSION['isConnected']))
    {
      header("Location: http://localhost");
      die();
    }
  }

  ft_disconnect();
?>
