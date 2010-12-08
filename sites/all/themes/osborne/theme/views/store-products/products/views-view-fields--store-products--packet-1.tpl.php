<?php
$html  = '';
$html .= '<span class="image">' . $image . '</span>';
$html .= '<span class="title">' . $title . '</span>';
if ($price) {
  $html .= '<span class="price">' . $price . '</span>';
}
if ($updated) {
  $html .= '<span class="updated"></span>';
}

print l($html, 'node/' . $nid, array('html' => TRUE, 'attributes' => array('class' => 'product')));