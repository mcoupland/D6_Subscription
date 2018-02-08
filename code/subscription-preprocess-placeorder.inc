<?php

include_once(drupal_get_path('module', 'subscription').'/code/subscription-global-variables.inc'); 

function subscription_preprocess_subscriptionthemeplaceorder( &$vars ) {  
	watchdog("subscription", 'subscription_preprocess_subscriptionthemeplaceorder', NULL, WATCHDOG_DEBUG);
	
	foreach( $vars['form'] as $k => $v ) {    
		if( preg_match( '/^[a-z]/', $k ) ) {      
			$vars[$k] = $vars['form'][$k];      
			unset( $vars['form'][$k] );    
		}  
	}		
	$subscription = subscription_get_subscription();
	$vars['membershipoffer'] = node_load(subscription_get_subscription()->membershipofferid);
	$vars['subscriptionlength'] = $vars['membershipoffer']->subscriptionlength / 12;
	
	if(subscription_validate_placeorder($vars) && $vars['form']['#post']){
		subscription_save_subscription($vars['form']['#post']);//, $subscription->membershipofferid);
		drupal_redirect_form($vars['form'], 'subscribe/registration');
	}
}