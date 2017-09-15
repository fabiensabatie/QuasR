<?php

  set_include_path('/home/quasr/QuasR');
  require 'src/includes.php';

?>

<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>jQuery UI Autocomplete - Default functionality</title>
  <link rel="stylesheet" type="text/css" href="/assets/css/dropdown.css">
  <link rel="stylesheet" type="text/css" href="/assets/css/semantic.css">
  <script
  src="https://code.jquery.com/jquery-3.1.1.min.js"
  integrity="sha256-hVVnYaiADRTO2PzUGmuLJr8BLUSjGIZsDYGmIJLv2b8="
  crossorigin="anonymous">
  $('.ui.dropdown')
  .dropdown()
;
  </script>
<script src="semantic/dist/semantic.min.js"></script>
</head>
<body>
  <div class="ui dropdown">
    <input name="gender" type="hidden">
    <i class="dropdown icon"></i>
    <div class="default text">Gender</div>
    <div class="menu">
      <div class="item" data-value="male">Male</div>
      <div class="item" data-value="female">Female</div>
    </div>
  </div>
  <select name="skills" multiple="" class="ui fluid dropdown">
    <option value="">Skills</option>
  <option value="angular">Angular</option>
  <option value="css">CSS</option>
  <option value="design">Graphic Design</option>
  <option value="ember">Ember</option>
  <option value="html">HTML</option>
  <option value="ia">Information Architecture</option>
  <option value="javascript">Javascript</option>
  <option value="mech">Mechanical Engineering</option>
  <option value="meteor">Meteor</option>
  <option value="node">NodeJS</option>
  <option value="plumbing">Plumbing</option>
  <option value="python">Python</option>
  <option value="rails">Rails</option>
  <option value="react">React</option>
  <option value="repair">Kitchen Repair</option>
  <option value="ruby">Ruby</option>
  <option value="ui">UI Design</option>
  <option value="ux">User Experience</option>
  </select>


</body>
</html>
