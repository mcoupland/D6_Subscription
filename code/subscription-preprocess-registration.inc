<?php

//tell drupal we are manually displaying all form elements
function subscription_preprocess_subscriptionthemeregistration( &$vars ) {
	watchdog("subscription", 'subscription_preprocess_subscriptionthemeregistration', NULL, WATCHDOG_DEBUG);
	
	foreach( $vars['form'] as $k => $v ) {    
		if( preg_match( '/^[a-z]/', $k ) ) {      
			$vars[$k] = $vars['form'][$k];      
			unset( $vars['form'][$k] );    
		}  
	}
	
	if(subscription_validate_registration(&$vars) && $vars['form']['#post']){
		subscription_save_subscription($vars['form']['#post']);
		drupal_redirect_form($vars['form'], 'subscribe/summary');
	}
}