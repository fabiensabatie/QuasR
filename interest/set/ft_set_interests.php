<?php

  require_once 'src/includes.php';

  function ft_check_interestentries($post)
  {
    array_pop($post);
    $null_count = 0;
    foreach ($post as $id => $checked)
      if ($checked != NULL)
        $null_count++;
    if (!$null_count)
    {
      ft_echo('<br>Please select an interest', 'red');
      return false;
    }
    ft_echo("<br>Interests added", "green");
    return true;
  }

  function ft_create_interestlist()
  {
    $interest_list = ft_mongo_get_interestlist();
    $interest_list = $interest_list->find([]);
    foreach($interest_list as $index => $interest)
      echo $interest->name . '<input type="checkbox" name="' . $interest->name
      . '" value="' . $interest->_id . '"><br>';
    echo '<input type="submit" value="Add interests">
          <input type="hidden" name="submit" value="true">';
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
