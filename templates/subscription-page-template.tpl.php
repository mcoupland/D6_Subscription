<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>
	<title></title>
	<link rel="stylesheet" type="text/css" href="<?php print $base_uri.'/'.drupal_get_path('module', 'subscription'); ?>/css/960_24_col.css" />
	<link rel="stylesheet" type="text/css" href="<?php print $base_uri.'/'.drupal_get_path('module', 'subscription'); ?>/css/subscription.css" />
	
	<script type="text/javascript" src="<?php print $base_uri.'/'.drupal_get_path('module', 'subscription') ?>/js/jquery-1.6.2.min.js"></script>
	<script type="text/javascript" src="<?php print $js_file; ?>"></script>
</head>
<body class="container_24">
	<div class="grid_24 alpha omega">	
		<img src="<?php print $base_uri.'/'.drupal_get_path('module', 'subscription').$header_image; ?>">
	</div>
	<?php print $messages; ?>
	<?php print $content; ?>
</body>
</html>