<?php
# @Author: aidenpearce
# @Date:   2017-08-11T18:34:25+02:00
# @Last modified by:   aidenpearce
# @Last modified time: 2017-08-11T18:34:34+02:00

  // Including basics
  require_once 'vendor/autoload.php'; // include Composer's autoloader
  require_once 'src/basics.php';

  // Including defines
  require_once 'config/defines.php';

  // Including models
  require_once 'src/models/user_model.php';
  require_once 'src/models/interest_model.php';

  // Including function files
  require_once 'user/registration/ft_register.php';
  require_once 'user/login/ft_login.php';
  require_once 'interest/set/ft_set_interests.php';


?>
