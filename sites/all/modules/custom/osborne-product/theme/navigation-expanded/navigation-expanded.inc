<?php
function theme_os_product_navigation_expanded() {
  $build = _os_product_product_navigation();
  _os_product_build_taxonomy_add_flag($build);
  return '<div id="navigation-expanded">' . theme('os_product_item_list', $build) . '</div>';
}