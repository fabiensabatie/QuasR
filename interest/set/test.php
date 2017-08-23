<?php
  set_include_path('/Users/aidenpearce/QuasR/');
  require_once 'src/includes.php';
  ft_check_if_logged();

/*  ft_echo('This is the interest :', 'green');
  $interest         = new cl_interest(ft_mongo_get_objectid());
  $interest->name   = 'Art';
  $interest->parent = true;
  ft_var_dump($interest);
  ft_echo('<br><br>This is the interest :', 'red');

  //$interest = $interest_collection->insertOne($interest);
  $interest = $interest_collection->findOne(['name' => 'Art']);
  ft_var_dump($interest);*/

$interest_collection = ft_mongo_get_interestcollection();
  $art = new cl_interest(ft_mongo_get_objectid());
  $art->name   = 'Art';
  $art->parent = true;

  $sport = new cl_interest(ft_mongo_get_objectid());
  $sport->name   = 'Sport';
  $sport->parent = false;
  $sport->roots[0] = [
    'name' => $art->name,
    '_id'  => $art->_id
  ];

  $maths = new cl_interest(ft_mongo_get_objectid());
  $maths->name   = 'Maths';
  $maths->parent = false;
  $maths->roots[0] = [
    'name' => $art->name,
    '_id'  => $art->_id
  ];

  $maths->roots[1] = [
    'name' => $sport->name,
    '_id'  => $sport->_id
  ];


  $art->children[0] = [
    'name' => $sport->name,
    '_id'  => $sport->_id
  ];

  $sport->children[0] = [
    'name' => $maths->name,
    '_id'  => $maths->_id
  ];
//  $interest = $interest_collection->insertOne($art);
//  $interest = $interest_collection->insertOne($maths);
//  $interest = $interest_collection->insertOne($sport);
  $array = array();
  $array[0] = $art;
  $array[1] = $sport;
  $array[2] = $maths;

  ft_pretty_json(ft_get_last_existing_interest($array));
?>
