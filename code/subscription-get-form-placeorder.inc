<?php

function subscription_edit_placeorder(){
	watchdog("subscription", 'subscription_edit_placeorder', NULL, WATCHDOG_DEBUG);
	
	subscription_set_editmode(1);
	
	//redirect to the place order form
	drupal_redirect_form(NULL, 'subscribe/placeorder');
}

function subscription_new_placeorder(){
	watchdog("subscription", 'subscription_new_placeorder', NULL, WATCHDOG_DEBUG);	
	
	subscription_create_subscription();
	
	//redirect to the place order form
	drupal_redirect_form(NULL, 'subscribe/placeorder');
}

//create form elements
function subscription_get_form_placeorder(&$form){
	watchdog("subscription", 'subscription_get_form_placeorder', NULL, WATCHDOG_DEBUG);
	
	$subscription = subscription_get_subscription();
	$editmode = $subscription->edit;
	subscription_get_selectvalues($prefixes, $suffixes, $countries, $regions, $years, $months, $editmode ? $subscription->country : 'US');
		
	return array(
		'membershipofferid' => array(
			'#type' => 'hidden',
			'#default_value' => $editmode ? $subscription->membershipofferid : $form['post']['membershipofferid'],
		),
		'selectedccstate' => array(
			'#type' => 'hidden',
			'#default_value' => $editmode ? $subscription->username : $form['post']['ccstate'],
		),
		'prefix' => array(
			'#type' => 'select',
			'#options' => $prefixes,
			'#default_value' => $editmode ? $subscription->prefix : $form['post']['prefix'],			
		),	
		'firstname' => array(
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->firstname : $form['post']['firstname'],
		),		
		'middleinitial' => array(
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->middleinitial : $form['post']['middleinitial'],
		),			
		'lastname' => array(
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->lastname : $form['post']['lastname'],
		),	
		'businessname' => array(
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->businessname : $form['post']['businessname'],
		),
		'suffix' => array(
			'#type' => 'select',
			'#options' => $suffixes,
			'#default_value' => $editmode ? $subscription->suffix : $form['post']['suffix'],
		),
		'country' => array(
			'#type' => 'select',	
			'#options' => $countries,
			'#default_value' => $editmode ? $subscription->country : $form['post']['country'],
		),	
		'selectedcountry' => array(
			'#type' => 'hidden',
			'#default_value' => $editmode ? $subscription->selectedcountry : ($form['post']['country'] ? $form['post']['country'] : 'US1'),
		),
		'address1' => array(		
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->address1 : $form['post']['address1'],
		),	
		'address2' => array(
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->address2 : $form['post']['address2'],
		),	
		'address3' => array(
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->address3 : $form['post']['address3'],
		),
		'city' => array(
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->city : $form['post']['city'],
		),	
		'state' => array(
			'#type' => 'select',
			'#options' => $regions,
			'#default_value' => $editmode ? $subscription->state : $form['post']['state'],
		),
		'postalcode' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->postalcode : $form['post']['postalcode'],
		),
		'daytimephone' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->daytimephone : $form['post']['daytimephone'],
		),	
		'mobilephone' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->mobilephone : $form['post']['mobilephone'],
		),
		'email' => array(
			'#type' => 'textfield', 
			'#default_value' => $editmode ? $subscription->email : $form['post']['email'], 
		),
		'secondemail' => array(
			'#type' => 'textfield',  
			'#default_value' => $editmode ? $subscription->secondemail : $form['post']['secondemail'],
		),	
		'cctype' => array(
			'#type' => 'radios',		
			'#options' => array(
			  'americanexpress' => t('<img src="'.$base_uri.'/'.drupal_get_path('module', 'subscription').'/img/icon-amex.gif">'),
			  'mastercard' => t('<img src="'.$base_uri.'/'.drupal_get_path('module', 'subscription').'/img/icon-mastercard.gif">'),
			  'visa' => t('<img src="'.$base_uri.'/'.drupal_get_path('module', 'subscription').'/img/icon-visa.gif">'),		
			),
			'#default_value' => $editmode ? $subscription->cctype : $form['post']['cctype'],
		),
		'ccnumber' => array(
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->ccnumber : $form['post']['ccnumber'],
		),
		'ccexpmonth' => array(
			'#type' => 'select',
			'#options' => $months,	
			'#default_value' => $editmode ? $subscription->ccexpmonth : $form['post']['ccexpmonth'],		
		),
		'ccexpyear' => array(
			'#type' => 'select',
			'#options' => $years,	
			'#default_value' => $editmode ? $subscription->ccexpyear : $form['post']['ccexpyear'],
		),
		'ccname' => array(
			'#type' => 'textfield',	
			'#default_value' => $editmode ? $subscription->ccname : $form['post']['ccname'],
		),
		'billingsame' => array(
			'#type' => 'checkbox', 
			'#default_value' => $editmode ? $subscription->billingsame : $form['post']['billingsame'],
		),
		'cccountry' => array(
			'#type' => 'select',		
			'#options' => $countries,
			'#default_value' => $editmode ? $subscription->cccountry : $form['post']['cccountry'],
		),
		'selectedcccountry' => array(
			'#type' => 'hidden',
			'#default_value' => $editmode ? $subscription->selectedcccountry : ($form['post']['cccountry'] ? $form['post']['cccountry'] : 'US1'),
		),
		'ccaddress1' => array(	
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->ccaddress1 : $form['post']['ccaddress1'],
		),
		'ccaddress2' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->ccaddress2 : $form['post']['ccaddress2'],
		),
		'cccity' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->cccity : $form['post']['cccity'],
		),
		'ccstate' => array(
			'#type' => 'select',	
			'#options' => $regions,	
			'#default_value' => $editmode ? $subscription->ccstate : $form['post']['ccstate'],
		),
		'ccpostalcode' => array(
			'#type' => 'textfield',
			'#default_value' => $editmode ? $subscription->ccpostalcode : $form['post']['ccpostalcode'],
		),
		'#theme' => 'subscriptionthemeplaceorder',
	);
}
