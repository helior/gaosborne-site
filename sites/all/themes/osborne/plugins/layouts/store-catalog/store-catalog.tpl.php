<div <?php print $attributes?>>
  <?php if($content['left']): ?>
  <div class="panel-panel panel-left panel-col-first">
    <?php print $content['left']; ?>
  </div>
  <?php endif; ?>

  <?php if($content['content']): ?>
  <div class="panel-panel panel-content panel-col-last">
    <?php print $content['content']; ?>
  </div>
  <?php endif; ?>
  <div class="clear"></div>
</div>
