<?php
 
//create form elements
function subscription_get_form_confirmation(&$form){
	return array(
		//'agreetoterms' => array(
		//	'#type' => 'checkbox',
		//	'#default_value' => $form['post']['agreetoterms'],
		//),
		'#theme' => 'subscriptionthemeconfirmation',
	);
}