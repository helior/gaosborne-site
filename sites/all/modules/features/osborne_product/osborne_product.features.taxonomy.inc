<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function osborne_product_taxonomy_default_vocabularies() {
  return array(
    'store' => array(
      'name' => 'Store',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '1',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_store',
      'weight' => '0',
      'nodes' => array(
        'product' => 'product',
      ),
    ),
  );
}
