<?php

function theme_osborne_helper_user_login($user) {
  if ($user->uid) {
    return 'Hello '. $user->name;
  } else {
    return l('Login', 'user/login', array('attributes' => array('class' => 'login')));
  }
}