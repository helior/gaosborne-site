<div<?php print drupal_attributes($attributes); ?>>
  <div class="header">
    <div class="header-inner">
      <h1 class="title"><?php print $title; ?></h1>
      <div class="found">Found in: <?php print $term_links; ?></div>
    </div>
  </div>
    
  <div class="node-inner">
    <div class="column column-left">
      <div class='column-inner'>
        <?php print $product_gallery; ?>
        <div class="clear"></div>
      
        <?php if ($related_products): ?>
          <div class="section">
            <h2>Related Products</h2>
            <?php print $related_products?>
          </div>
        <?php endif; ?>
      </div>
    </div>
    
    <div class="column column-right">
      <div class='column-inner'>
        <?php if ($price): ?>
          <span class="price"><?php print $price; ?></span>
        <?php endif; ?>
      
        <div class="section">
          <h2>Product Highlights</h2>
          <div class="body">
            <?php print $body; ?>
          </div>
        </div>
        <div class="section">
          <h2>Customer Reviews</h2>
          <?php print $comments; ?>
        </div>
      </div>
    </div>
    
    <div class="clear"></div>
    
  </div>
</div>