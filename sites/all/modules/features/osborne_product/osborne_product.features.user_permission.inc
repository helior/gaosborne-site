<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function osborne_product_user_default_permissions() {
  $permissions = array();

  // Exported permission: create product content
  $permissions['create product content'] = array(
    'name' => 'create product content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: delete any product content
  $permissions['delete any product content'] = array(
    'name' => 'delete any product content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: delete own product content
  $permissions['delete own product content'] = array(
    'name' => 'delete own product content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: edit any product content
  $permissions['edit any product content'] = array(
    'name' => 'edit any product content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: edit own product content
  $permissions['edit own product content'] = array(
    'name' => 'edit own product content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: view imagecache product-category-navigation-preview
  $permissions['view imagecache product-category-navigation-preview'] = array(
    'name' => 'view imagecache product-category-navigation-preview',
    'roles' => array(),
  );

  // Exported permission: view imagecache product-category-thumbnail
  $permissions['view imagecache product-category-thumbnail'] = array(
    'name' => 'view imagecache product-category-thumbnail',
    'roles' => array(),
  );

  // Exported permission: view imagecache product-image-full
  $permissions['view imagecache product-image-full'] = array(
    'name' => 'view imagecache product-image-full',
    'roles' => array(),
  );

  // Exported permission: view imagecache product-image-preview
  $permissions['view imagecache product-image-preview'] = array(
    'name' => 'view imagecache product-image-preview',
    'roles' => array(),
  );

  // Exported permission: view imagecache product-related-thumbnail
  $permissions['view imagecache product-related-thumbnail'] = array(
    'name' => 'view imagecache product-related-thumbnail',
    'roles' => array(),
  );

  // Exported permission: view imagecache product-search-thumbnail
  $permissions['view imagecache product-search-thumbnail'] = array(
    'name' => 'view imagecache product-search-thumbnail',
    'roles' => array(),
  );

  // Exported permission: view imagecache product-thumbnail
  $permissions['view imagecache product-thumbnail'] = array(
    'name' => 'view imagecache product-thumbnail',
    'roles' => array(),
  );

  return $permissions;
}
