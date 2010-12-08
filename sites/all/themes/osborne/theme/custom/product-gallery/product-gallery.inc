<?php
function osborne_preprocess_osborne_product_gallery(&$vars) {
  $images = $vars['a1'];
  if (empty($images)) return;
  
  $items = array();
  foreach ($images as $image) {
    $large_image_path = imagecache_create_url('product-image-full', $image['filepath']);
    $thumbnail = theme('imagecache', 'product-image-preview', $image['filepath']);
    $items[] = l($thumbnail, $large_image_path, array('html' => TRUE));
  }
  $vars['list'] = theme('item_list', $items, NULL, 'ul', array('class' => 'ppy-imglist'));
}