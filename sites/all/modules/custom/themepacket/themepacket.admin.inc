<?php

/**
 * @file
 * Admin configuration forms.
 */

function themepacket_settings() {
  $form['themepacket_library_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to libraries directory'),
    '#default_value' => variable_get('themepacket_library_path', 'sites/all/libraries'),
    '#description' => t('Set the absolute path to the directory where all your library files will be saved. (ex: sites/all/libraries)'),
    );
  
  $form['themepacket_theme_dir'] = array(
    '#type' => 'textfield',
    '#title' => t('Theme directory name'),
    '#default_value' => variable_get('themepacket_theme_dir', 'theme'),
    '#description' => t('Set which directory to scan for theme implementations. This is applicable to both modules and themes.'),
    );
  
  $form['themepacket_theme_dir_ignore'] = array(
    '#type' => 'textfield',
    '#title' => t('Ignored directories'),
    '#default_value' => variable_get('themepacket_theme_dir_ignore', 'views'),
    '#description' => t('A comma seperated list of directories to ignore while discovering theme implementations.'),
    );
  
  return system_settings_form($form);
}


function themepacket_settings_validate($form, &$form_state) {
  // Ensure "Ignored directories" field is formatted in exactly the right way.
  if (!empty($form_state['values']['themepacket_theme_dir_ignore'])) {
    $temp = explode(',', $form_state['values']['themepacket_theme_dir_ignore']);
    foreach ($temp as $value) {
      $clean[] = trim($value);
    }
    $form_state['values']['themepacket_theme_dir_ignore'] = implode(', ', $clean);
  }
}
