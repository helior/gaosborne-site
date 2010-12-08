<div<?php print drupal_attributes($attributes); ?>>
  <div class="node-inner">
    
    <?php if ($image): ?>
      <div class="image-wrapper"><div class="image"><?php print $image; ?></div></div>
    <?php endif; ?>
    
    <div class="header">
      <h1><?php print $title; ?></h1>
    </div>
    
    <div class="content">
      <?php print $body ?>
    </div>
  </div>
</div>