<?php
function osborne_osborne_product_related_item($variables) {
  $image = theme('imagecache', 'product-related-thumbnail', $variables['item']['filepath']);

  $o  =   '';
  $o .=   '<span class="image">' . $image . '</span>';
  $o .=   '<strong class="title">' . $variables['item']['title'] . '</strong>';
  $o .=   '<span class="body">' . $variables['item']['body'] . '</span>';
  
  // Wrap a link around the content.
  $o = l($o, 'node/' . $variables['item']['nid'], array('html' => TRUE, 'attributes' => array('class' => 'related-product')));
  
  return $o;
}