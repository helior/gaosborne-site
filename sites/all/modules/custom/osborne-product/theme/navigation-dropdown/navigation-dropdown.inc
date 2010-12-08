<?php
function theme_os_product_navigation_dropdown() {
  $build = _os_product_product_navigation();
  _os_product_build_taxonomy_add_images($build, 'product-category-navigation-preview');
  return '<div id="store-navigation">' . theme('os_product_item_list', $build) . '</div>';
}