<?php

  require_once 'src/includes.php';

  class cl_interest_list
  {
    public $name = NULL;

    function ft_insert_interestlist()
    {
      $interests = ft_mongo_get_interestlist();
      if ($this->name == NULL)
      {
        echo "The interest doesn't have a name";
        return false;
      }
      else
        $interest  = $interests->insertOne($this);
      return true;
    }
  }

  class cl_interest Extends cl_interest_list
  {
    public $_id      = NULL;
    public $parent   = false;
    public $roots    = array();
    public $children = array();
    public $users    = array();
    public $scope    = ALL;

    function __construct($_id)
    {
      $this->_id = $_id;
    }

    function ft_interest_is_listed()
    {
      $interest_list = ft_mongo_get_interestlist();
      if (!$listed_interest = findOne(['name' => $this->name]))
        $interest_list->insertOne(['name' => $this->name]);
      return true;
    }
  }
?>
