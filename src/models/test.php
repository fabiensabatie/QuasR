<?php

  namespace InterestSpace;
  set_include_path('/home/quasr/QuasR/');

  require_once 'src/includes.php';


  $art               = new cl_interest(new \MongoDB\BSON\ObjectID());
  $art->name         = 'Art';
  $art->parent       = true;
  $sport             = new cl_interest(new \MongoDB\BSON\ObjectID());
  $sport->name       = 'Sport';
  $physics           = new cl_interest(new \MongoDB\BSON\ObjectID());
  $physics->name     = 'Physics';
  $maths             = new cl_interest(new \MongoDB\BSON\ObjectID());
  $maths->name       = 'Maths';

  $art->children[0] = array(
    'name'           => $sport->name,
    '_id'            => $sport->_id
  );

  $sport->roots[0] = array(
    'name'           => $art->name,
    '_id'            => $art->_id
  );


  $physics->roots[0] = array(
      'name'           => $sport->name,
      '_id'            => $sport->_id
    );

    $art->insert_interest();
    $sport->insert_interest();

  $array = array($art, $sport);
  \ft_var_dump(locate_last_child($array));


?>