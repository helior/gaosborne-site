<?php
$html  = '';
$html .= '<span class="image">' . $image . '</span>';
$html .= '<span class="title">' . $name . '</span>';

print l($html, 'taxonomy/term/' . $tid, array('html' => TRUE, 'attributes' => array('class' => 'category')));