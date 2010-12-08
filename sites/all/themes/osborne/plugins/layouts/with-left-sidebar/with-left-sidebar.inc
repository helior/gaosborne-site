<?php

// Plugin definition
$plugin = array(
  'title' => t('With Left Sidebar'),
  'category' => t('Columns: 2'),
  'icon' => 'with-left-sidebar.png',
  'theme' => 'with_left_sidebar',
  'css' => 'with-left-sidebar.css',
  'admin css' => 'with-left-sidebar-admin.css',
  'panels' => array(
    'left' => t('Left side'),
    'content' => t('Content'),
  ),
);

function template_preprocess_with_left_sidebar(&$vars){
  $attr['class']  = 'with-left-sidebar';
  $attr['class'] .= ' panel-display';
  if (!empty($vars['css_id'])) {
    $attr['id'] = $vars['css_id'];
  }
  $vars['attributes'] = drupal_attributes($attr);
}