<?php
 
//create form elements
function subscription_get_form_summary(&$form){
	watchdog("subscription", 'subscription_get_form_summary', NULL, WATCHDOG_DEBUG);
	return array(
		'agreetoterms' => array(
			'#type' => 'checkbox',
			'#default_value' => $form['post']['agreetoterms'],
		),
		'#theme' => 'subscriptionthemesummary',
	);
}