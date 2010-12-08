<div class="comment<?php print ($comment->new) ? ' comment-new' : ''; print ' '. $status ?> clear-block">
  <div class="content">
    <span class="reviewer"><?php print $author; ?> says:</span>
    <?php print $content ?>
  </div>
  <?php print $links ?>
</div>
