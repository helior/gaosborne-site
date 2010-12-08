<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function osborne_basic_user_default_permissions() {
  $permissions = array();

  // Exported permission: create page content
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: delete any page content
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: delete own page content
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: edit any page content
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: edit own page content
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      '0' => 'Owner',
    ),
  );

  // Exported permission: view imagecache basic-page-image
  $permissions['view imagecache basic-page-image'] = array(
    'name' => 'view imagecache basic-page-image',
    'roles' => array(),
  );

  // Exported permission: view imagecache basic-thumbnail
  $permissions['view imagecache basic-thumbnail'] = array(
    'name' => 'view imagecache basic-thumbnail',
    'roles' => array(),
  );

  return $permissions;
}
