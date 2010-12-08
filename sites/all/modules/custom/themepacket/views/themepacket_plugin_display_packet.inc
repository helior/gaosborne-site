<?php
// $Id$

/**
 * @file
 * Views Display plugin to allows custom ID attribute to be added to
 * the view, automatically preprocess field variables for row
 * template overrides, and automatically discover css and javascript
 * to be included when in the context of rendering the view.
 */

class themepacket_plugin_display_packet extends views_plugin_display {
  
  function option_definition() {
    $options = parent::option_definition();
    $options['include_assets'] = array('default' => TRUE);
    $options['preprocess_fields'] = array('default' => TRUE);
    $options['preprocessed'] = array('default' => FALSE);
    $options['css_id'] = array('default' => 'pending...');
    return $options;
  }
  
  
  function options_summary(&$categories, &$options) {
    // It is very important to call the parent function here:
    parent::options_summary($categories, $options);
    $categories['themepacket'] = array(
      'title' => t('ThemePacket Settings'),
    );
    
    $options['preprocess_fields'] = array(
      'category' => 'themepacket',
      'title' => t('Preprocess Fields'),
      'value' => ($this->get_option('preprocess_fields')) ? t('Yes please') : t('No way'),
    );
    
    $options['include_assets'] = array(
      'category' => 'themepacket',
      'title' => t('Include Assets'),
      'value' => t('Not right now'),
    );
    
    if ($this->get_option('include_assets')) {
      $assets_info = $this->get_asset_info();
      $options['include_assets']['value'] = t('Yes') . $assets_info['message'];
      $options['include_assets']['desc'] = $assets_info['desc'];
    }
    
    $options['css_id'] = array(
      'category' => 'themepacket',
      'title' => t('CSS ID'),
      'value' => ($this->get_option('css_id')) ? $this->get_option('css_id') : t('None'),
      );
  }
  
  
  function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);
    switch ($form_state['section']) {
      case 'preprocess_fields':
        $form['#title'] = t('Preprocess Fields');
        $form['#tree'] = TRUE;
        $form['preprocess_fields'] = array(
          '#type' => 'checkbox',
          '#title' => t('Preprocess Fields'),
          '#description' => t('This settings will preprocess each field content so you can access them directly in your fields template.'),
          '#default_value' => $this->get_option('preprocess_fields'),
        );
        
        $fields = $this->get_fields();
        
        if (is_array($fields)) { // Ensures that fields exist in the view, although parent::validate() checks for that anyway.
          $preprocessed_values = $this->get_option('preprocessed');
          foreach ($fields as $field) {
            
            // Recommendations are the default values for "preprocessed" fields.
            $recommendation = $this->strip_field_name($field);
            
            // Determine default value for custom preprocessed field, provide notifier to show that preprocess field name is custom.
            if (!$preprocessed_values[$field['id']] || $preprocessed_values[$field['id']] == $recommendation) {
              $default_value = $recommendation;
              $notifier = '';
            }
            else {
              $default_value = $preprocessed_values[$field['id']];
                $notifier = '<span class="warning">✔custom</span>';
            }
            
            $form['preprocessed'][$field['id']] = array(
              '#type' => 'textfield',
              '#default_value' => $default_value,
              '#size' => 20,
              '#field_prefix' => '$vars[',
              '#field_suffix' => '] = $fields["' . $field['id'] . '"]->content; ' . $notifier,
              '#process' => array('views_process_dependency'),
              '#dependency' => array(
                'edit-preprocess-fields' => array(1),
                ),
              );
          }
        } 
        break;
      
      case 'include_assets':
        // Temporarily change the current theme to accurately flush the correct theme registry
        global $custom_theme;
        $custom_theme = variable_get('theme_default', 'garland');
        
        $form['#title'] = t('Include Assets');
        $form['#help_topic'] = 'analyze-theme';
        $form['include_assets'] = array(
          '#type' => 'checkbox',
          '#title' => t('Include Assets'),
          '#description' => t('This option will automatically register assets used by the display.'),
          '#default_value' => $this->get_option('include_assets'),
        );
        
        if ($this->get_option('include_assets')) {
          $assets = $this->get_asset_info();
          
          $form['assets'] = array(
            '#type' => 'markup',
            '#prefix' => '<div class="form-item dependent-options">',
            '#value' => theme('themepacket_assets_list', $assets),
            '#suffix' => '</div>',
            );
          $form['rescan_button'] = array(
            '#prefix' => '<div class="form-item">',
            '#suffix' => '</div>',
          );
          $form['rescan_button']['button'] = array(
            '#type' => 'submit',
            '#value' => t('Rescan assets registry'),
            '#submit' => array('views_ui_config_item_form_rescan'),
          );
        }
        
        break;
        
      case 'css_id':
        $form['css_id'] = array(
          '#type' => 'textfield',
          '#title' => 'CSS ID',
          '#default_value' => (!$this->get_option('css_id') || ($this->get_option('css_id') == 'pending...')) ? $this->view->name . '-' . str_replace('_', '-', $this->display->id) : $this->get_option('css_id'),
          '#description' => t('This value will be set as the view\'s #id attribute. WARNING: duplicate IDs in your document will invalidate your markup.'),
          );
    }  
  }
  
  
  function options_validate(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_validate($form, $form_state);
    
    switch ($form_state['section']) {
      case 'preprocess_fields':
      
        // Make sure preprocess names do not override critical preprocess variable names
        $not_these = $this->reserved_fields();
          
        $fields = $form_state['values']['preprocessed'] ? $form_state['values']['preprocessed'] : array();
        foreach ($fields as $k => $v) {
          
          // Validate against reserved names.
          if (in_array($v, $not_these)) {
            form_error($form['preprocessed'][$k], t('The value "%value" should not be used since it is likely to conflict with an existing preprocessed variable.', array('%value' => $v)));
          }
          
          // Validate against typical php variable name syntax.
          elseif (preg_match('/[^a-zA-Z0-9_]/', $v)) {
            form_error($form['preprocessed'][$k], t('Preprocess field "<strong>%field</strong>" must be alphanumeric or underscores only.', array('%field' => $v)));
          }
        }
        break;
      
      case 'css_id':
        if (preg_match('/[^a-zA-Z0-9-]/', $form_state['values']['css_id'])) {
          form_error($form['css_id'], t('CSS ID value must be alphanumeric or dashes only.'));
        }
        break;
    }
  }
  
  
  function options_submit(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_submit($form, $form_state);
    
    switch ($form_state['section']) {
      case 'preprocess_fields':
        $this->set_option('preprocess_fields', $form_state['values']['preprocess_fields']);
        $this->set_option('preprocessed', $form_state['values']['preprocessed']);
        break;
      
      case 'include_assets':
        $this->set_option('include_assets', $form_state['values']['include_assets']);
        
        // rebuild theme registry to also rebuild asset registry
        drupal_rebuild_theme_registry();
        break;
      
      case 'css_id':
        $this->set_option('css_id', $form_state['values']['css_id']);
        break;
    }
  }
  
  
  function validate() {
    $errors = NULL; //prevent notices
    /**
     * Auto-save/delete preprocess fields which have not been manually configured.
     */
    if ($this->get_option('preprocess_fields')) {
      // Preprocessor expects this to be set.
      $this->set_option('preprocess_fields', TRUE);
      
      // Get current fields in display (default or otherwise overridden)
      $fields = $this->get_fields();
      
      // Get currently saved preprocessed fields
      $preprocess_fields = ($this->get_option('preprocessed')) ? $this->get_option('preprocessed') : array();
      
      if (is_array($fields)) {
        $auto_save = array();
        foreach ($fields as $field) {
          
          // Auto-save "recommended" default preprocess name if not already in preprocess_fields array OR if preprocess_fields value was left blank.
          if (!array_key_exists($field['id'], $preprocess_fields) || $preprocess_fields[$field['id']] == '') {
            $recommended = $this->strip_field_name($field);
            
            // Pseudo-validation (@see $this->options_validate);
            if (in_array($recommended, $this->reserved_fields())) {
              $errors[] = t('The field name "%field" in display %display is likely to conflict with an existing preprocessed variable. Please review and update "Preprocess Fields" configuration.', array('%field' => $recommended, '%display' => $this->display->display_title));
              break;
            }
            
            // Delegate saving fields to merge with current array of preprocessed_fields; Also consolidates messages to the user.
            $auto_save[$field['id']] = $recommended;
          }
        }
        
        // Auto-delete preprocess fields which don't exist
        $auto_delete = array();
        foreach ($preprocess_fields as $k => $v) {
          if (!array_key_exists($k, $fields)) {
            $auto_delete[$k] = $v;
          }
        }
        
        if (!empty($auto_save) || !empty($auto_delete)) {
          
          // Remove deleted fields
          if (!empty($auto_delete)) {
            $preprocess_fields = array_diff($preprocess_fields, $auto_delete);
          }
          
          // Auto-save fields
          $merged_fields = array_merge($preprocess_fields, $auto_save);
          $this->set_option('preprocessed', $merged_fields);
          
          // Give the user some feedback.
          if (!empty($auto_save)) {
            drupal_set_message(t('Field names "%auto_save_names" in display "%display" have been automatically saved for preprocessing <span style="font-size:20px">☺</span>.', array('%auto_save_names' => implode(', ', $auto_save), '%display' => $this->display->display_title)));
          }
        }
      }
    }
    
    if ($this->get_option('css_id') == 'pending...') {
      // Automatically save suggested CSS #ID
      $id = $this->view->name . '-' . str_replace('_', '-', $this->display->id);
      $this->set_option('css_id', $id);
      drupal_set_message(t('Display %display automatically configured %id as it\'s CSS #ID', array('%display' => $this->display->display_title, '%id' => $id)));
    }
    
    return $errors;
  }
  
  
  function execute() {
    return $this->view->render($this->display->id);
  }
  
  
  function get_fields() {
    // Return display's overriden fields, otherwise default fields are used.
    return (isset($this->options['fields'])) ? $this->options['fields'] : $this->view->display['default']->display_options['fields'];
  }
  
  
  function strip_field_name($field = array()) {
    //remove typical cck prefix/suffix
    $trim_these = array(
      '/^field_/',
      '/_value$/',
      '/_fid$/',
      '/_nid$/',
    );
    return preg_replace($trim_these, '', $field['id']);
  }
  
  
  function reserved_fields() {
    return array(
      'template_files',
      'view',
      'options',
      'row',
      'field_alias',
      'zebra',
      'id',
      'directory',
      'is_admin',
      'is_front',
      'logged_in',
      'db_is_active',
      'user',
      'fields',
      );
  }
  
  
  function compatible_templates() {
    $templates = array();
    
    $templates[] = 'views_view_fields__' . $this->view->name . '__' . $this->display->id;
    $templates[] = 'views_themepacket_view__' . $this->view->name . '__' . $this->display->id;
    
    $templates[] = 'views_view_fields__' . $this->view->name . '__packet';
    $templates[] = 'views_themepacket_view__' . $this->view->name . '__packet';
    
    $templates[] = 'views_view_fields__' . $this->view->name;
    $templates[] = 'views_themepacket_view__' . $this->view->name;

    if (!empty($this->view->tag)) {
      $templates[] = 'views_themepacket_view__' . $this->view->tag;
    }
    
    $templates[] = 'views_view_fields__packet';
    $templates[] = 'views_themepacket_view__packet';

    return $templates;
  }
  
    
  function get_asset_info() {
    $default_theme = variable_get('theme_default', 'garland');
    $assets = assets_get_registry($default_theme);
    
    if (!empty($assets->data)) {
      $templates = $this->compatible_templates();
      $count = 0;
      foreach ($templates as $template) {
        if (isset($assets->data[$template])) {
          $count += count($assets->data[$template]['js']);
          $count += count($assets->data[$template]['css']);
          return array(
            'message' => t(', !notice found!', array('!notice' => format_plural($count, '1 asset', '@count assets'))),
            'info' => $assets->data[$template],
            'desc' => t('found in @location', array('@location' => $assets->data[$template]['base path'])),
            );
        }
      }
    }

    // Fallback return value if compatible template not found in asset registry.
    return array(
      'message' => t(', but...'),
      'info' => NULL,
      'desc' => t('If this appears to not be working, it may be for a few different reasons: The view and configuration might not be saved yet, you\'re not overriding a compatible template, or you need to rescan assets registry.'),
      );
  }
}
