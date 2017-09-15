<?php

  function ft_get_interests_list()
  {
    $interest_list = ft_mongo_get_interestlist();
    $interest_list = $interest_list->find();

    $interest_list = iterator_to_array($interest_list);
    $list = array();
    foreach ($interest_list as $key => $interest) {
      $list[$key] = $interest['name'];
    }
    echo json_encode($list);
    //return json_encode($interest_list);
  }

?>
