<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?>">
	<div class="body-inner">
  	<div id="page">
	
			<div id="header">
				<div id="logo-title">
					<h1>
						<a href="<?php print $front_page;?>" title="<?php print t('Home'); ?>" rel="home">GA Osborne</a>
					</h1>
				</div>
			</div> <!-- /#header -->


			<div id="main">
				<div id="main-inner" class="clear-block">
	      <div id="content"><div id="content-inner">

   
	        <?php if ($content_top): ?>
	          <div id="content-top">
	            <?php print $content_top; ?>
	          </div> <!-- /#content-top -->
	        <?php endif; ?>

	        <?php if ($breadcrumb || $title || $tabs || $help || $messages): ?>
	          <div id="content-header">
	            <?php //print $breadcrumb; ?>
	            <?php if ($title): ?>
	              <h1 class="title"><?php print $title; ?></h1>
	            <?php endif; ?>
	            <?php if ($messages): ?>
	              <div class="message-wrapper"><?php print $messages; ?></div>
	            <?php endif; ?>
	            <?php if ($tabs): ?>
	              <div class="tabs"><?php print $tabs; ?></div>
	            <?php endif; ?>
	            <?php print $help; ?>
	          </div> <!-- /#content-header -->
	        <?php endif; ?>

	        <div id="content-area">
	          <?php print $content; ?>
	        </div>

	        <?php if ($feed_icons): ?>
	          <div class="feed-icons"><?php print $feed_icons; ?></div>
	        <?php endif; ?>

	        <?php if ($content_bottom): ?>
	          <div id="content-bottom" class="region region-content_bottom">
	            <?php print $content_bottom; ?>
	          </div> <!-- /#content-bottom -->
	        <?php endif; ?>

	      </div></div> <!-- /#content-inner, /#content -->

        <div id="navbar">
          <?php print $store_navigation; ?>
					<div id="navbar-bottom"><?php print $navbar_bottom; ?></div>
        </div> <!-- /#navbar -->

	      <?php if ($left): ?>
	        <div id="sidebar-left"><div id="sidebar-left-inner" class="region region-left">
	          <?php print $left; ?>
	        </div></div> <!-- /#sidebar-left-inner, /#sidebar-left -->
	      <?php endif; ?>

	      <?php if ($right): ?>
	        <div id="sidebar-right"><div id="sidebar-right-inner" class="region region-right">
	          <?php print $right; ?>
	        </div></div> <!-- /#sidebar-right-inner, /#sidebar-right -->
	      <?php endif; ?>

	    </div></div> <!-- /#main-inner, /#main -->

	    <?php if ($footer || $footer_message): ?>
	      <div id="footer"><div id="footer-inner" class="region region-footer">

	        <?php if ($footer_message): ?>
	          <div id="footer-message"><?php print $footer_message; ?></div>
	        <?php endif; ?>

	        <?php print $footer; ?>

	      </div></div> <!-- /#footer-inner, /#footer -->
	    <?php endif; ?>

		</div> <!-- /#page-inner, /#page -->

	  <?php print $closure; ?>
	</div>
</body>
</html>
<?php
// TODO: set location of default drupal search box; not a block;
?>