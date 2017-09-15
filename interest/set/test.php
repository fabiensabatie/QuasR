<?php
  set_include_path('/home/quasr/QuasR/');
  require_once 'src/includes.php';
  ft_check_if_logged();

  $interest_collection = ft_mongo_get_interestcollection();

  $art   = new cl_interest_list();
  $art->name = 'Art';
  $sport = new cl_interest_list();
  $sport->name = 'Sport';
  $physics = new cl_interest_list();
  $physics->name = 'Physics';
  $maths = new cl_interest_list();
  $maths->name = 'Maths';
  $computers = new cl_interest_list();
  $computers->name = 'Computers';

  $array = array();


  $array[0] = $computers;
  $array[1] = $maths;
  $array[2] = $sport;
  $array[3] = $physics;
  $array[4] = $art;
  ft_generate_array($array);
?>
