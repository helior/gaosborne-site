<?php
// $Id$

/**
 * @file
 * Theme function to format found assets.
 */

function theme_themepacket_assets_list($assets = NULL) {
  if (!empty($assets['info'])) {
    $extensions = array('js' => 'Javascript', 'css' => 'Stylesheet');
    foreach ($extensions as $ext => $extension) {
      if (!empty($assets['info'][$ext])) {
        $items = array();
        foreach ($assets['info'][$ext] as $file) {
          $temp = $file->basename;
          if (!empty($file->alias)) {
            $temp .= ' <span class="warning">➥ ' . $file->filename . '</span>';
          }
          $items[] = $temp;
        }
        return theme('item_list', $items, $extension);
      }
    }
  }
}