<?php if ($list): ?>
  <div class="product-gallery">
    <div class="ppy">
      <?php print $list; ?>
      <div class="ppy-outer">
        <div class="ppy-stage">
          <div class="ppy-nav">
            <a class="ppy-prev" title="Previous image">Previous image</a>
            <a class="ppy-switch-enlarge" title="Enlarge">Enlarge</a>
            <a class="ppy-switch-compact" title="Close">Close</a>
            <a class="ppy-next" title="Next image">Next image</a>
          </div>
          <div class="ppy-counter"><strong class="ppy-current"></strong> of <strong class="ppy-total"></strong></div>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>