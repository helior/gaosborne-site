<?php

// Plugin definition
$plugin = array(
  'title' => t('Store Catalog'),
  'category' => t('Columns: 2'),
  'icon' => 'store-catalog.png',
  'theme' => 'store_catalog',
  'css' => 'store-catalog.css',
  'admin css' => 'store-catalog-admin.css',
  'panels' => array(
    'left' => t('Left side'),
    'content' => t('Content'),
  ),
);

function template_preprocess_store_catalog(&$vars){
  // Add empty text when no content is available in the $content panel
  if (empty($vars['content']['content'])) {
    $vars['content']['content'] = '<h2 id="store-catalog-empty-text">' . t('Sorry, we don\'t have any of our products listed under this category yet!') . '</h2>';
  }
  
  $attr['class']  = 'store-catalog';
  $attr['class'] .= ' panel-display';
  if (!empty($vars['css_id'])) {
    $attr['id'] = $vars['css_id'];
  }
  $vars['attributes'] = drupal_attributes($attr);
}