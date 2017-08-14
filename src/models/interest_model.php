<?php

  require_once 'src/includes.php';

  class cl_interest
  {
    private $name     = NULL;
    private $parent   = false;
    private $roots    = array();
    private $children = array();

    function ft_insert_interest()
    {
      $interests     = ft_mongo_get_interestcollection();
      $parents_count = count($this->parents);

      
    }
  }
?>
