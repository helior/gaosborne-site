<?php
// $Id$

/**
 * @file
 * Defining Views Plugin. 
 */
 
/**
 * Implementation of hook_views_plugins().
 */
function themepacket_views_plugins() {
  $path = drupal_get_path('module', 'themepacket') .'/views';
  return array(
    'display' => array(
      'packet' => array(
        'title' => t('ThemePacket'),
        'help' => t('This is a ThemePacket!'),
        'handler' => 'themepacket_plugin_display_packet',
        'path' => $path,
        'theme' => 'views_themepacket_view',
        'theme file' => 'themepacket.theme.inc',
        'theme path' => $path,
        'use ajax' => TRUE,
        'use pager' => TRUE,
        'use more' => TRUE,
        'accept attachments' => TRUE,
        'themepacket' => TRUE,
      ),
    ),
  );
}
