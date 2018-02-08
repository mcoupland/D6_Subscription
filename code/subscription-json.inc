<?php
//called from jquery

function subscription_get_regions($country_value = '') {
	$customerwebservice = subscription_get_customerwebservice();
	$country = array('ParentAlpha2' => $country_value);
	$region_result = $customerwebservice->GetISORegions($country); 
	$regions = $region_result->GetISORegionsResult->ISO3166;
	
	$regions_array = array('0' => '-- Select --');
		
	if(is_array($regions)){
		foreach ($regions as $region) {
			/**
			 * Apostrophe breaks the select 
			 * "Governor's Harbour" in Bahamas, for example
			 */
			$regions_array[str_replace("'", "", $region->Name)] = str_replace("'", "", $region->Name);
		}  
	}
	
	return drupal_json($regions_array);
	exit;
}

function subscription_get_countries() {
  $customerwebservice = subscription_get_customerwebservice();
  $countries_result = $customerwebservice->GetISOCountries(); 
  $countries = $countries_result->GetISOCountriesResult->ISO3166;
  $countries_array = array('0' => '-- Select --');
  $countries_array['US1'] = 'United States'; 
  $countries_array['CA1'] = 'Canada';
  $countries_array['99'] = '------------------------';
  
  foreach ($countries as $country) {
    $countries_array[$country->Alpha2] = $country->Name;
  }
  return $countries_array;
}

function subscription_validate_ccnumber($number, $card_type) {
  
  // Strip any non-digits (useful for credit card numbers with spaces and hyphens)
	$number=preg_replace('/\D/','', $number);
	$is_valid = false;
	
  switch($card_type){
		case "mastercard":
			if (strlen($number) == 16 
				&& substr($number, 0, 1) == "5" 
				&& substr($number,1, 1) >= 1
				&& substr($number,1, 1) <= 5)
			{
				$is_valid = TRUE;
			}
			break;
		case "visa":
			if ((strlen($number) == 13 
				|| strlen($number) == 16)
				&& substr($number, 0, 1) == "4")
			{
				$is_valid = TRUE;
			}
			break;
		case "americanexpress":
			if (strlen($number) == 15
				&& (substr($number, 0,2) == "34"
				|| substr($number, 0, 2) == "37"))
			{
				$is_valid = TRUE;
			}
			break;
	}
    
	if($is_valid){
		// Set the string length and parity
		$number_length=strlen($number);
		$parity=$number_length % 2;

		// Loop through each digit and do the maths
		$total=0;
		for ($i=0; $i<$number_length; $i++) {
			$digit=$number[$i];
			// Multiply alternate digits by two
			if ($i % 2 == $parity) {
				$digit*=2;
				// If the sum is two digits, add them together (in effect)
				if ($digit > 9) {
					$digit-=9;
				}
			}
			// Total up the digits
			$total+=$digit;
		}

    // If the total mod 10 equals 0, the number is valid
    if($total % 10 == 0)
      $result_array = array('result' => TRUE);
    else
      $result_array = array('result' => FALSE);      
    
    return drupal_json($result_array);
    exit;
	}
  $result_array = array('result' => FALSE);
  return drupal_json($result_array);
  exit;  
} 

function subscription_validate_email($parm = '') {
	$result = FALSE;
	if(preg_match("/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,3})$/", $parm)){
		$result = TRUE;
	}
	$result_array = array('result' => $result);
	return drupal_json($result_array);
	exit;
}

function subscription_isavailable_nameemail($parm = '') {
	$customerwebservice = subscription_get_customerwebservice();
	$newdata = array('username' => $parm);
	$result = $customerwebservice->IsUserNameAvailable($newdata)->IsUserNameAvailableResult;
	
	$result_array = array('result' => $result);
	return drupal_json($result_array);
}




/*

function subscription_process_order($formdata) {
	$subscriptionoffer = node_load($formdata->subscriptionofferid, NULL, TRUE);
  
	switch($formdata->country) {
		case 'US':
			$price = $subscriptionoffer->usprice;
			break;
		case 'CA':
			$price = $subscriptionoffer->canadianprice;
			break;
		default:
			$price = $subscriptionoffer->internationalprice;
			break;
	}

	$currentdate = date("Y-m-d");
	$expdate = date("Y-m-d",strtotime(date("Y-m-d", strtotime($currentdate)) . " +1 year"));
	list($ccexpyear, $ccexpmonth, $ccexpdaytime ) = split("-",$formdata->expdate);


	$newdata = array(
		'salutation' 			=> $formdata->prefix, 
		'firstname' 			=> $formdata->firstname, 
		'middleinitial' 		=> '', 
		'lastname' 				=> $formdata->lastname, 
		'suffix' 				=> $formdata->suffix, 
		'professionaltitle' 	=> '', 
		'email' 				=> $formdata->email, 
		'optin' 				=> 'False', 
		'businessname' 			=> $formdata->businessname, 
		'address1' 				=> $formdata->address1, 
		'address2' 				=> $formdata->address2, 
		'address3' 				=> '', 
		'city' 					=> $formdata->city, 
		'state' 				=> $formdata->state, 
		'postalcode' 			=> $formdata->postalcode, 
		'country' 				=> $formdata->country, 
		'phone' 				=> $formdata->daytimephone, 
		'fax' 					=> '', 
		'altcity' 				=> '', 
		//'cctype' 				=> $_SESSION['method_of_payment'],
		'ccnum' 				=> $formdata->ccnumber, 
		'ccexpmonth' 			=> $ccexpmonth, 
		'ccexpyear' 			=> $ccexpyear, 
		'amountpaid' 			=> $price, 
		'ccname' 				=> $formdata->ccname, 
		'ccaddress' 			=> $formdata->ccaddress1, 
		'cccity' 				=> $formdata->cccity, 
		'ccstate' 				=> $formdata->ccstate, 
		'ccpostalcode' 			=> $formdata->postalcode, 
		'pubcode' 				=> $subscriptionoffer->pubcode, 
		'username' 				=> $formdata->username, 
		'pwd' 					=> $formdata->password, 
		'keycode' 				=> $subscriptionoffer->keycode, 
		'subscriptionlength' 	=> $subscriptionoffer->subscriptionlength, 
		'source' 				=> $subscriptionoffer->source, 
		'customertype' 			=> 'PERSONAL', 
		'expiredate' 			=> $expdate, 
		'startdate' 			=> $currentdate,
		'newsletters' 			=> $formdata->newsletters,
	);
	
	$customerwebservice = subscription_get_customerwebservice();
	$process_result = $customerwebservice->SubscribeNewUser($newdata);
	$member_node->process_code = $process_result->SubscribeNewUserResult->ResponseCode;
	$member_node->SFGID = $process_result->SubscribeNewUserResult->Customer->SfgId;    

	//If the ResponseCode = 0, we'll perform the email validation
	if($member_node->processcode == 0) {
		_subscription_unsubscribe_all($member_node->email);
		_subscription_process_newsletters($newsletters, $member_node->email);
	} else {
		form_set_error('form_id');
		drupal_set_message("Error Code: ".$member_node->processcode,'error', false);
	}
	
	return;
}

function subscription_unsubscribe_all($email) {
  _mailchimp_unsubscribe_user($lists['937db36184'], $email, null, true, null);
  _mailchimp_unsubscribe_user($lists['c88900eb10'], $email, null, true, null);
  _mailchimp_unsubscribe_user($lists['c5b40f97a2'], $email, null, true, null);
  _mailchimp_unsubscribe_user($lists['f5f37b668f'], $email, null, true, null);  
}

function subscription_process_newsletters($newsletter_list, $email) {
	$account->roles = array(8 => 'discovery');
  $lists = _mailchimp_get_available_lists($account);

  $newsletters = explode("|", $newsletter_list);
  $subscribe_list = array();
  foreach($newsletters as $newsletter)
    switch($newsletter) {
      case "Special Offers":
      _mailchimp_subscribe_user($lists['937db36184'], $email, null, true, null);
      break;
      case "Auction":
      _mailchimp_subscribe_user($lists['c88900eb10'], $email, null, true, null);
      break;
      case "Travel Office": //Waiting on email list for this one
      //_mailchimp_subscribe_user($lists[$id], $email, null, true, null);
      break;
      case "Porthos, Wine":
      _mailchimp_subscribe_user($lists['c5b40f97a2'], $email, null, true, null);
      break;
      case "From The Editor":
      _mailchimp_subscribe_user($lists['f5f37b668f'], $email, null, true, null);
      break;
    }  

  return;
}

*/



