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
    $dbname        = DBNAME;
    $users         = USERSCOLLECTION;
    $client        = ft_mongo_get_client();
    $users         = $client->$dbname->users;
    return $users;
  }

  function ft_mongo_get_interestcollection()
  {
    $dbname        = DBNAME;
    $interests     = INTERESTSCOLLECTION;
    $client        = ft_mongo_get_client();
    $interests     = $client->$dbname->interests;
    return $interests;
  }

  //Basic functions.

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
      ft_echo("<br>Session on : ", "green");
      ft_var_dump($_SESSION);
    }
    if (isset($_SESSION["isConnected"]) && $_SESSION["isConnected"])
    {
      if (isset($_GET['disconnect']))
      {
        ft_echo("<br>Session destroyed", "green");
        session_destroy();
      }
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
?>
