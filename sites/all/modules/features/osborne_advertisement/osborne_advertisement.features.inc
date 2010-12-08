<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function osborne_advertisement_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function osborne_advertisement_imagecache_default_presets() {
  $items = array(
    'advertisement-featured' => array(
      'presetname' => 'advertisement-featured',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '992',
            'height' => '600',
          ),
        ),
      ),
    ),
    'advertisement-landscape' => array(
      'presetname' => 'advertisement-landscape',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '496',
            'height' => '250',
          ),
        ),
      ),
    ),
    'advertisement-portrait' => array(
      'presetname' => 'advertisement-portrait',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '250',
            'height' => '',
            'upscale' => 1,
          ),
        ),
      ),
    ),
    'basic-thumbnail' => array(
      'presetname' => 'basic-thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '100',
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
function osborne_advertisement_node_info() {
  $items = array(
    'advertisement' => array(
      'name' => t('Advertisement'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function osborne_advertisement_views_api() {
  return array(
    'api' => '2',
  );
}
