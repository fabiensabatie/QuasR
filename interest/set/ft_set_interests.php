<?php

  set_include_path('/home/quasr/QuasR');
  require_once 'src/includes.php';

  function ft_insert_child($parent_id, $child)
  {
    $interest_collection = ft_mongo_get_interestcollection();
    $interest            = $interest_collection->findOne(['_id' => $parent_id]);
    $children            = array(
      'name' => $child->name,
      '_id'  => $child->_id
    );

    $interest['children'] = iterator_to_array($interest['children']);
    for ($i = 0 ; $i < count($interest['children']) ; $i++)
      $interest['children'][$i] = iterator_to_array($interest['children'][$i]);
    array_push($interest['children'], $children);
    $to_insert = array(
      'children' => $interest['children']
    );

    $inserted             = $interest_collection->updateOne(array('_id' => $parent_id), ['$set' => $to_insert]);
  }

  function ft_locate_last_child($interests)
  {
    $interest_collection = ft_mongo_get_interestcollection();
    $last                = null;
    $parent              = array('name' => $interests[0]->name, 'parent' => true);

    if (!($last          = $interest_collection->findOne(['name' => $interests[0]->name, 'parent' => true])))
      return null;
    array_shift($interests);

    foreach ($interests as $key => $interest) {
      $parent = $last;
      foreach ($last['children'] as $child) {
        if ($child['name'] == $interest->name) {
          $last = $interest_collection->findOne(['_id' => $child['_id']]);
          break;
        }
      }
      if ($last == $parent)
        break;
    }

    return $last;
  }

  function ft_generate_array($interests)
  {
    sort($interests);
    $interest_collection = ft_mongo_get_interestcollection();
    if (!($last_info     = ft_locate_last_child($interests)))
    {
      $last_info         = new cl_interest(ft_mongo_get_objectid());
      $last_info->name   = $interests[0]->name;
      $last_info->parent = true;
      $last_id           = $last_info->_id;
      $last_info         = $interest_collection->insertOne($last_info);
      $last_info         = $interest_collection->findOne(['_id' => $last_id]);
    }

    foreach ($interests as $interest) {
      array_shift($interests);
      if ($interest->name == $last_info['name'])
        break;
    }

    foreach($interests as $interest) {
      $root = array(
        'name' => $last_info['name'],
        '_id'  => $last_info['_id']
      );

      $last_info['roots'] = iterator_to_array($last_info['roots']);
      array_push($last_info['roots'], $root);
      $current            = new cl_interest(ft_mongo_get_objectid());
      $current->name      = $interest->name;
      $current->roots     = $last_info['roots'];
      ft_insert_child($last_info['_id'], $current);
      $last_info          = $interest_collection->insertOne($current);
      $last_info          = $interest_collection->findOne(['_id' => $current->_id]);
    }
  }
?>
