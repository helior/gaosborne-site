<?php
// $Id$

/**
 * @file
 * Preprocessors for Themepacket Views Display Plugin.
 */

function template_preprocess_views_themepacket_view(&$vars, $hook) {
  // Envoke initial preprocessor.
  template_preprocess_views_view($vars);
  
  $assets = assets_get_registry();
  
  if (!empty($assets->data)) {  

    foreach ($vars['view']->display_handler->compatible_templates() as $key) {
      if (isset($assets->data[$key])) {
        
        $item = $assets->data[$key];
        if (!empty($item['js'])) {
          foreach ($item['js'] as $js) {
            drupal_add_js($js->filename);
          }
        }
      
        if (!empty($item['css'])) {
          foreach ($item['css'] as $css) {
            drupal_add_css($css->filename);
          }
        }
      
        break;
      }
    }
  }

  // Display attributes
  $attributes = array();
  $attributes['class'] = implode(' ', $vars['classes_array']);
  
  $id = check_plain($vars['view']->display[$vars['view']->current_display]->display_options['css_id']);
  if (!empty($id)) {
    $attributes['id'] = $id;
  }
  $vars['attributes'] = drupal_attributes($attributes);
}


/**
 * Implementation of hook_preprocess_views_view_fields().
 */
function themepacket_preprocess_views_view_fields(&$vars, $hook) {
  //get view configuration
  $options = $vars['view']->display[$vars['view']->current_display]->display_options;
  
  //Prepare Preprocessed Fields for template
  if ($options['preprocess_fields']) {
    $fields = $options['preprocessed'];
    if (is_array($fields)) {
      foreach ($fields as $original => $custom) {
        $vars[$custom] = $vars['fields'][$original]->content;
      }
    }
  }
}
