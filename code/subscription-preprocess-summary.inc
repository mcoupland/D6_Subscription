<?php

//tell drupal we are manually displaying all form elements
function subscription_preprocess_subscriptionthemesummary( &$vars ) {  
	watchdog("subscription", 'subscription_preprocess_subscriptionthemesummary', NULL, WATCHDOG_DEBUG);
	
	foreach( $vars['form'] as $k => $v ) {    
		if( preg_match( '/^[a-z]/', $k ) ) {      
			$vars[$k] = $vars['form'][$k];      
			unset( $vars['form'][$k] );    
		}  
	}
	subscription_get_summary_data($vars);
	
	if(subscription_validate_summary(&$vars) && $vars['form']['#post']){
		watchdog("subscription", 'subscription_validate_summary', NULL, WATCHDOG_DEBUG);
		
		subscription_save_subscription($vars['form']['#post']);
		$errormessage = subscription_send_order($vars);
		if($errormessage){
			$vars['error'] =  $errormessage;
		}
		else{
			drupal_redirect_form($vars['form'], 'subscribe/confirmation');			
		}
	}
}