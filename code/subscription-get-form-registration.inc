<?php
 
//create form elements
function subscription_get_form_registration(&$form){	
	watchdog("subscription", 'subscription_get_form_registration', NULL, WATCHDOG_DEBUG);
	
	return array(
		'username' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->username : $form['post']['username'],
		),
		'password' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->password : $form['post']['password'],
		),
		'confirmpassword' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->confirmpassword : $form['post']['confirmpassword'],
		),
		'screenname' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->screenname : $form['post']['screenname'],
		),
		'newslettersall' => array(
			'#type' => 'checkbox',
			'#default_value' => $editmode ? $subscription->newslettersall : $form['post']['newslettersall'],
		),
		'newsletters_fromtheeditor' => array(
			'#type' => 'checkbox',
			'#default_value' => $editmode ? $subscription->newsletters_fromtheeditor : $form['post']['newsletters_fromtheeditor'],
		),
		'newsletters_specialoffers' => array(
			'#type' => 'checkbox',
			'#default_value' => $editmode ? $subscription->newsletters_specialoffers : $form['post']['newsletters_specialoffers'],
		),
		'newsletters_harperauctions' => array(
			'#type' => 'checkbox',
			'#default_value' => $editmode ? $subscription->newsletters_harperauctions : $form['post']['newsletters_harperauctions'],
		),
		'newsletters_traveloffice' => array(
			'#type' => 'checkbox',
			'#default_value' => $editmode ? $subscription->newsletters_traveloffice : $form['post']['newsletters_traveloffice'],
		),
		'newsletters_porthos' => array(
			'#type' => 'checkbox',
			'#default_value' => $editmode ? $subscription->newsletters_porthos : $form['post']['newsletters_porthos'],
		),
		'#theme' => 'subscriptionthemeregistration',
	);
}