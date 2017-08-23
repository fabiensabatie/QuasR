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

    function ft_find_child($child_name)
    {
      $interest_collection = ft_mongo_get_interestcollection();
      foreach ($this->children as $child)
      {
        if ($child['name'] === $child_name)
          return $interest_collection->findOne(['_id' => $child->_id]);
      }
      return false;
    }

    function ft_insert_child($child_interest)
    {
      $interest_collection = ft_mongo_get_interestcollection();
      $child               = array(
                    'name' => $child_interest->name,
                    '_id'  => $child_interest->_id
      );
      array_push($this->children, $child);
      $to_update = array(
        ['_id' => $this->_id],
        ['$set' => ['children' => $this->children]]
      );
      return $interest_collection->updateOne($to_update);
    }
  }

  function ft_get_interest_by_id($id)
  {
    $interest_collection = ft_mongo_get_interestcollection();
    if ($interest = $interest_collection->findOne(['_id' => $id]))
      return $interest;
    return false;
  }

  function ft_get_parent_interest($name)
  {
    $interest_collection = ft_mongo_get_interestcollection();
    if ($interest = $interest_collection->findOne(['name' => $name, 'parent' => true]))
      return $interest;
    return false;
  }

  function ft_get_last_existing_interest($interests)
  {
    if (!$parent = ft_get_parent_interest($interests[0]->name))
      return false;
    if (empty($interests))
        return $parent;

    $cl_interest = new cl_interest(ft_mongo_get_objectid());
    $parent      = ft_convert_M2C($parent, $cl_interest);
    $current     = $parent;

    array_shift($interests);
    foreach ($interests as $index => $interest)
    {
      if (!$child = $current->ft_find_child($interest->name))
        return $current;
      $current = ft_convert_M2C($child, $cl_interest);
    }
    return $current;
  }

  function ft_build_interests_array($interests, $parent = false)
  {
    $current = new cl_interest(ft_mongo_get_objectid());
    if ($parent)
      $$current->parent = true;
    
  }

?>
