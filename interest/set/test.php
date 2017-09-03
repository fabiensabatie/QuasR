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

  $array = array();

  $array[0] = $physics;
  $array[1] = $sport;
  $array[2] = $art;

  ft_generate_array($array);
?>
