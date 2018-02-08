<?php

//tell drupal we are manually displaying all form elements
function subscription_preprocess_subscriptionthemeconfirmation( &$vars ) {  
	foreach( $vars['form'] as $k => $v ) {    
		if( preg_match( '/^[a-z]/', $k ) ) {      
			$vars[$k] = $vars['form'][$k];      
			unset( $vars['form'][$k] );    
		}  
	}
	subscription_get_confirmation_data($vars);
}