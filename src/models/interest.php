<?php

/**
* Interest Class | src/models/interest.php
*
* @package     QuasR.io
* @subpackage  Classes
* @author      Fabien Sabatié <fsabatie@student.42.fr>
* @version     v.1.0 (24/10/2017)
* @copyright   Copyright (c) 2017, QuasR.io
*/

  namespace InterestSpace;
  require 'src/includes.php';

  /** Interest list class */
  class cl_interest_list {

    /** @var string The interest's name */
    public $name = NULL;

    /** Construct method */
    public function __construct($name){
      $this->name = $name;
    }

    /** Inserts the interest in the list collection */
    public function insert_list() {
       return (\getInterestsListCollection()->insertOne($this));
    }
  }

  /** Interest class */
  class cl_interest Extends cl_interest_list {

    /** @var string The MongoDB id constant */
    public $_id           = NULL;
    /** @var array The interest's roots */
    public $roots         = array();
    /** @var array The interest's children. */
    public $children      = array();
    /** @var boolean The interest's children. */
    public $parent        = false;

    /** Construct method */
    public function __construct($_id){
      $this->_id = $_id;
    }

    /** Insertion in DB method */
    public function insert_interest() {
      return (\getInterestsCollection()->insertOne($this));
    }
  }

  /** Returns the parent from the interests collection
  * if it exists. If not, returns false */
  function parent_exists(cl_interest $interest) {
    $search = array(
      'parent' => true,
      'name'   => $interest->name
    );
    if (!$result = \getInterestsCollection()->findOne($search))
      return (false);
    else
      return ($result);
  }

  /** Locates the last interest that is already in the
  * database collection, then allowing to know which
  * interests to insert */
  function locate_last_child(array $interests_array) {
    if (!$result = parent_exists($interests_array[0]))
      return (null);
    $result_idem = false;
    array_shift($interests_array);
    foreach ($interests_array as $interest) {
      foreach ($result['children'] as $child) {
        if ($child['name'] === $interest->name) {
          $result = \getInterestsCollection()->findOne(['_id' => $child['_id']]);
          break ;
        }
        $result_idem = true;
      }
      if ($result_idem)
        return ($result);
    }
    return ($result);
  }


  /** Updates the parent's children array with
  * the new child's _id and name */
  function insert_child(string $parent_id, cl_interest $child)
  {
    $interest            = \getInterestsCollection()->findOne(['_id' => $parent_id]);
    $children            = array(
      'name'             => $child->name,
      '_id'              => $child->_id
    );

    $interest['children'] = iterator_to_array($interest['children']);
    for ($i = 0 ; $i < count($interest['children']) ; $i++)
      $interest['children'][$i] = iterator_to_array($interest['children'][$i]);
    array_push($interest['children'], $children);
    $to_insert = array(
      'children' => $interest['children']
    );

    \getInterestsCollection()->updateOne(array(
                      '_id' => $parent_id),
                    ['$set' => $to_insert]);
  }

?>
