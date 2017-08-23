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

  

?>
