<div class="result-item">
  <?php if ($thumbnail): ?>
    <span class="image"><?php print $thumbnail; ?></span>
  <?php endif; ?>
  <?php print $title; ?>
  <?php if ($term_links): ?>
    <span class="found">found in <?php print implode(' ', $term_links); ?></span>
  <?php endif; ?>
  <?php print $body; ?>
</div>