<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function osborne_product_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function osborne_product_imagecache_default_presets() {
  $items = array(
    'product-category-category-thumbnail' => array(
      'presetname' => 'product-category-category-thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '163',
            'height' => '163',
          ),
        ),
      ),
    ),
    'product-category-navigation-preview' => array(
      'presetname' => 'product-category-navigation-preview',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '204',
            'height' => '98',
          ),
        ),
      ),
    ),
    'product-category-thumbnail' => array(
      'presetname' => 'product-category-thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '173',
            'height' => '132',
          ),
        ),
      ),
    ),
    'product-image-full' => array(
      'presetname' => 'product-image-full',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '700',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'product-image-preview' => array(
      'presetname' => 'product-image-preview',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '240',
            'height' => '173px',
          ),
        ),
      ),
    ),
    'product-related-thumbnail' => array(
      'presetname' => 'product-related-thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '50',
            'height' => '50',
          ),
        ),
      ),
    ),
    'product-search-thumbnail' => array(
      'presetname' => 'product-search-thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '80',
            'height' => '80',
          ),
        ),
      ),
    ),
    'product-taxonomy-header' => array(
      'presetname' => 'product-taxonomy-header',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '400',
            'height' => '',
            'upscale' => 1,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '785',
            'height' => '90',
            'xoffset' => 'right',
            'yoffset' => 'center',
          ),
        ),
        '2' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_file2canvas',
          'data' => array(
            'xpos' => 0,
            'ypos' => 0,
            'alpha' => '100',
            'path' => 'sites/default/files/_custom/taxonomy-header_mask.png',
          ),
        ),
      ),
    ),
    'product-thumbnail' => array(
      'presetname' => 'product-thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '150',
            'height' => '150',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function osborne_product_node_info() {
  $items = array(
    'product' => array(
      'name' => t('Product'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function osborne_product_views_api() {
  return array(
    'api' => '2',
  );
}
