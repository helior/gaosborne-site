<?php

/**
 * Implementation of hook_theme().
 */
function osborne_theme($existing, $type, $theme, $path) {
 $hooks = array();
 $hooks['node'] = array(
   'arguments' => array('node' => NULL, 'teaser' => FALSE, 'page' => FALSE),
   'function' => 'node_delegator',
   'pattern' => 'node__',
 );
 $patterns = (module_exists('themepacket')) ? themepacket_find_patterns($hooks, '.tpl.php', $path) : drupal_find_theme_templates($hooks, '.tpl.php', $path);
 $discover = (module_exists('themepacket')) ? themepacket_discover($existing, $type, $theme, $path) : array();
 return $hooks += $patterns += $discover;
}

function node_delegator($node = NULL, $teaser = FALSE, $page = FALSE ) {
 return theme(array('node__'. $node->type, 'node__default'), $node, $teaser, $page);
}


/***********************************************************************************
* Preprocess Functions
***********************************************************************************/
/**
 * Implementation of hook_preprocess_page().
 */
function osborne_preprocess_page(&$vars, $hook) {
  // krumo(theme_get_registry());
  // krumo(assets_get_registry());
	$vars['styles'] = drupal_get_css();
	$vars['scripts'] = drupal_get_js();
}


/**
 * Implementation of hook_preprocess_panels_pane().
 */
function osborne_preprocess_panels_pane(&$vars) {
  // Perform extra functionality when pane has a configured class
  if (empty($vars['pane']->css)) return;
    $pane_classes = $vars['pane']->css['css_class'];
    
    switch ($pane_classes) {
      
      // Replace $title with a taxonomy image banner
      case 'taxonomy-header':
        // Get taxonomy image path from last argument if the pane is in the path 'store'
        // assuming path is taxonomy/term/%tid
        if ($image_path = _osborne_helper_get_taxonomy_image_path(arg(2))) {
          $text = $vars['content'];
          /**
           * @todo use imagecache_create_url() to use as background image instead.
           */
          $vars['content']  = theme('imagecache', 'product-taxonomy-header', $image_path);
          $vars['content'] .= $text;
        }
        break;
    }
}


/**
 * Implementation of hook_preprocess_node().
 * Delegating preprocessor to dedicated function.
 */
function osborne_preprocess_node(&$vars) {
  /* Global preprocessing */
  $classes_array = explode(' ', $vars['classes']);
  $classes_array[] = 'node-' . $vars['type'];
  $classes_array[] = $vars['zebra'];
  $classes_array[] = ($vars['status']) ? 'published' : 'unpublished';
  $classes_array[] = 'clear-block';
  $vars['attributes'] = array(
    'id' => 'node-'. $vars['nid'],
    'class' => implode(' ', $classes_array),
    );
  
  /* Delegating micro preprocessing */
  $func = 'osborne_preprocess_node_' . $vars['type'];
  if (function_exists($func)) {
    $func($vars);
  }
}

function osborne_preprocess_node_product(&$vars) {
  // Create photo gallery
  $vars['product_gallery'] = theme('osborne_product_gallery', $vars['field_product_image']);
  
  // Term links
  $term_links = array();
  foreach ($vars['taxonomy'] as $term) {
    $term_links[] = l($term['title'], $term['href'], array('attributes' => array('class' => 'taxonomy')));
  }
  $vars['term_links'] = implode(' ', $term_links);
  
  // Get body
  $vars['body'] = $vars['node']->content['body']['#value'];
  
  // Get price
  $vars['price'] = $vars['node']->field_product_price[0]['value'];
  
  // Format related products
  if (function_exists('_os_product_query_related_items')) {
    $items = _os_product_query_related_items($vars['node']->field_product_related);
    if ($items) {
      $vars['related_products'] = '';
      foreach ($items as $item) {
        $vars['related_products'] .= theme('osborne_product_related_item', array('item' => $item));
      } 
    }
  }
  
  // Get Comments
  $vars['comments'] = comment_render($vars['node']);
}

function osborne_preprocess_node_page(&$vars) {
  // Get generic body
  $vars['body'] = $vars['node']->content['body']['#value'];
  
  // Set image
  $vars['image'] = '';
  foreach ($vars['field_basic_image'] as $delta => $item) {
    if (isset($item['filepath'])) {
      $vars['image'] .= theme('imagecache', 'basic-page-image', $item['filepath']);
    }
  }
}

/**
 * Implementation of hook_preprocess_search_result().
 */
function osborne_preprocess_search_result(&$vars) {
  
  // Products get special attention
  if ($vars['info_split']['type'] == 'Product') {
    foreach ($vars['result']['node']->taxonomy as $term) {
      $vars['term_links'][] = l($term->name, 'taxonomy/term/' . $term->tid, array('attributes' => array('class' => 'taxonomy')));
    }
    $vars['thumbnail'] = theme('imagecache', 'product-search-thumbnail', $vars['result']['node']->field_product_image[0]['filepath']);
    $vars['thumbnail'] = l($vars['thumbnail'], $vars['url'], array('html' => true, 'alias' => TRUE));
  }
  
  
  // Truncating body text if necessary.
  $body_character_limit = 260;
  $body_text = $vars['result']['node']->content['body']['#value'];
  $vars['body'] = (strlen($body_text) > $body_character_limit) ? substr($body_text, 0, $body_character_limit) . '...' : $body_text;
  
  // Wrapping elements with links
  $vars['title'] = l($vars['title'], $vars['url'], array('alias' => TRUE, 'attributes' => array('class' => 'title')));
}

/**
 * Implementation of hook_preprocess_comment().
 */
function osborne_preprocess_comment(&$vars) {
  $vars['author'] = str_replace(' (not verified)', '', $vars['author']);
}



/***********************************************************************************
* Theme Overrides
***********************************************************************************/

/**
 * Remove wrapping div, unless a title was actually set.
 * Force recursive to reuse this override and not the original theme_item_list().
 */
function osborne_item_list($items = array(), $title = NULL, $type = 'ul', $attributes = NULL) {
  $output = '';
  if (isset($title)) {
    $output = '<div class="item-list">';
    $output .= '<h3>'. $title .'</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type". drupal_attributes($attributes) .'>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        $data .= theme('item_list', $children, NULL, $type, $attributes); // Render nested list
      }
      if ($i == 0) {
        $attributes['class'] = empty($attributes['class']) ? 'first' : ($attributes['class'] .' first');
      }
      if ($i == $num_items - 1) {
        $attributes['class'] = empty($attributes['class']) ? 'last' : ($attributes['class'] .' last');
      }
      $output .= '<li'. drupal_attributes($attributes) .'>'. $data ."</li>\n";
    }
    $output .= "</$type>";
  }
  if (isset($title)) {
    $output .= '</div>';
  }
  return $output;
}



/***********************************************************************************
* Custom Functions
***********************************************************************************/
