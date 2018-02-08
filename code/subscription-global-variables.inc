<?php 

function subscription_get_selectvalues(&$prefixes, &$suffixes, &$countries, &$regions, &$years, &$months, $selectedcountry){
	
	$customerwebservice = subscription_get_customerwebservice();
	
	if(empty($prefixes)){
		$result = $customerwebservice->GetPrefixes();
		$results = $result->GetPrefixesResult->Prefix;
		$prefixes = array('0' => '-- Select --');
		foreach ($results as $value) {
			$prefixes[$value->displayname] = $value->displayname;
		}  
	}
	
	if(empty($suffixes)){
		$result = $customerwebservice->GetSuffixes();
		$results = $result->GetSuffixesResult->Suffix;
		$suffixes = array('0' => '-- Select --');
		foreach ($results as $value) {
			$suffixes[$value->displayname] = $value->displayname;
		}  
	}
	
	if(empty($countries)){
		$result = $customerwebservice->GetISOCountries(); 
		$results = $result->GetISOCountriesResult->ISO3166;
		$countries = array('0' => '-- Select --');
		$countries['US1'] = 'United States'; 
		$countries['CA1'] = 'Canada';
		$countries['99'] = '------------------------';
		foreach ($results as $value) {
			$countries[$value->Alpha2] = $value->Name;
		}
	}
	
	if(empty($regions)){
		$result = $customerwebservice->GetISORegions(array('ParentAlpha2' => $selectedcountry));
		$results = $result->GetISORegionsResult->ISO3166;
		$regions = array('0' => '-- Select --');
		foreach ($results as $value) {
			$regions[$value->Name] = $value->Name;
		}
	}
	
	if(empty($months)){		
		$months = array(
				'1' => 'Jan',
				'2' => 'Feb',
				'3' => 'Mar',
				'4' => 'Apr',
				'5' => 'May',
				'6' => 'Jun',
				'7' => 'Jul',
				'8' => 'Aug',
				'9' => 'Sep',
				'10' => 'Oct',
				'11' => 'Nov',
				'12' => 'Dec',
			);
	}
	
	if(empty($years)){
		$year = (int) date('Y');
		$years = array();
		for($i = 0; $i < 5; $i++){
			$years[$i] = $year++;
		}
	}
}

function subscription_get_prefixvalue($prefix){
	if(!$prefix){return '';}
	
	$customerwebservice = subscription_get_customerwebservice();
	$result = $customerwebservice->GetPrefixes();	
	$results = $result->GetPrefixesResult->Prefix;
	foreach ($results as $value) {
		if($value->displayname == $prefix){
			return $value->sfgcode ? $value->sfgcode : '';
		}
	}
}

function subscription_get_suffixvalue($suffix){		
	if(!$suffix){return '';}
	
	$customerwebservice = subscription_get_customerwebservice();
	$result = $customerwebservice->GetSuffixes();	
	$results = $result->GetSuffixesResult->Suffix;
	foreach ($results as $value) {
		if($value->displayname == $suffix){
			return $value->sfgcode ? $value->sfgcode : '';		
		}
	}
}

function subscription_get_yearvalue($selectedyear){
	$year = (int) date('Y');
	return $year + $selectedyear;
}

function subscription_get_customerwebservice(){
	return new SoapClient(
		variable_get(
			'subscription_customerservice_webservice_url', 
			'http://192.168.2.53/HarperSERVICE/customerservice.asmx?wsdl'
		),
		array(
		"trace" => 1, 
		"exceptions" => 0
		)
	);	
}

function subscription_set_editmode($edit){
	watchdog("subscription", 'subscription_set_editmode '.$edit, NULL, WATCHDOG_DEBUG);
	db_query('UPDATE {subscribe} SET edit = "%s" WHERE sessionid = "%s" AND ipaddress = "%s"', 
		$edit, $_COOKIE['session_id'], $_SERVER['REMOTE_ADDR']);
}

function subscription_create_subscription(){
	watchdog("subscription", 'subscription_create_subscription '.$offer, NULL, WATCHDOG_DEBUG);
	
	//delete any existing record for this user/session
	db_queryd('DELETE FROM {subscribe} WHERE sessionid = "%s" AND ipaddress = "%s" AND memberid IS NULL', $_COOKIE['session_id'], $_SERVER['REMOTE_ADDR']);	
	
	//get the offerid	
	$page = explode("/", $_GET['q']);	
	$offerid = db_fetch_object(db_queryd('SELECT a.nid FROM {ahmembershipoffer} a JOIN {node} b ON a.nid = b.nid WHERE b.title = "%s"', $page[1]));
		
	//create the new subscription
	$subscription = new stdClass();
	$subscription->sessionid = $_COOKIE['session_id'];
	$subscription->ipaddress = $_SERVER['REMOTE_ADDR'];
	$subscription->membershipofferid = $offerid->nid;
	drupal_write_record('subscribe', $subscription);	
}

function subscription_get_subscription(){
	watchdog("subscription", 'subscription_get_subscription', NULL, WATCHDOG_DEBUG);
	
	return db_fetch_object(db_query(
		'SELECT a.* FROM {subscribe} a WHERE a.sessionid = "%s" AND a.ipaddress = "%s" AND memberid IS NULL', 
		$_COOKIE['session_id'], $_SERVER['REMOTE_ADDR']));	
}

function subscription_save_subscription($formpost){//, $membershipofferid = NULL){	
	watchdog("subscription", 'subscription_save_subscription', NULL, WATCHDOG_DEBUG);	
	$subscription = subscription_get_subscription();
	
	$subscription->dateupdated = date('Y-m-d');
	$subscription->edit = $formpost['edit'];
	if(isset($formpost['memberid'])){$subscription->memberid = $formpost['memberid'];}
	if(isset($formpost['prefix'])){$subscription->prefix = $formpost['prefix'];}
	if(isset($formpost['firstname'])){$subscription->firstname = $formpost['firstname'];	}
	if(isset($formpost['middleinitial'])){$subscription->lastname = $formpost['middleinitial'];}
	if(isset($formpost['lastname'])){$subscription->lastname = $formpost['lastname'];}
	if(isset($formpost['businessname'])){$subscription->businessname = $formpost['businessname'];}
	if(isset($formpost['suffix'])){$subscription->suffix = $formpost['suffix'];}
	if(isset($formpost['selectedcountry'])){$subscription->selectedcountry = $formpost['country'];}
	if(isset($formpost['country'])){
		if($formpost['country'] == "US1"){
			$subscription->country = "US";      
		}elseif($formpost['country'] == "CA1"){
			$subscription->country = "CA";
		}else{
			$subscription->country = $formpost['country'];
		}
	}
	if(isset($formpost['address1'])){$subscription->address1 = $formpost['address1'];}
	if(isset($formpost['address2'])){$subscription->address2 = $formpost['address2'];}
	if(isset($formpost['address3'])){$subscription->address3 = $formpost['address3'];}
	if(isset($formpost['city'])){$subscription->city = $formpost['city'];}
	if(isset($formpost['selectedstate'])){$subscription->selectedstate = $formpost['state'];}
	if(isset($formpost['state'])){$subscription->state = $formpost['state'];}
	if(isset($formpost['postalcode'])){$subscription->postalcode = $formpost['postalcode'];}
	if(isset($formpost['daytimephone'])){$subscription->daytimephone = $formpost['daytimephone'];}
	if(isset($formpost['mobilephone'])){$subscription->mobilephone = $formpost['mobilephone'];}
	if(isset($formpost['email'])){$subscription->email = $formpost['email'];}
	if(isset($formpost['secondemail'])){$subscription->secondemail = $formpost['secondemail'];}
	if(isset($formpost['cctype'])){$subscription->cctype = $formpost['cctype'];}
	if(isset($formpost['ccnumber'])){$subscription->ccnumber = $formpost['ccnumber'];}	//encrypt found in C:\andrewharper.com\sites\all\modules\ah_secure\ah_secure.module
	if(isset($formpost['ccexpmonth'])){$subscription->ccexpmonth = $formpost['ccexpmonth'];}
	if(isset($formpost['ccexpyear'])){$subscription->ccexpyear = $formpost['ccexpyear'];}
	if(isset($formpost['ccname'])){$subscription->ccname = $formpost['ccname'];}
	if(isset($formpost['billingsame'])){$subscription->billingsame = $formpost['billingsame'];}
	if(isset($formpost['selectedcccountry'])){$subscription->selectedcccountry = $formpost['cccountry'];}
	if(isset($formpost['cccountry'])){	
		if($formpost['cccountry'] == "US1"){
			$subscription->cccountry = "US";      
		}elseif($formpost['cccountry'] == "CA1"){
		  $subscription->cccountry = "CA";
		}else{
		  $subscription->cccountry = $formpost['cccountry'];
		}
	}
	if(isset($formpost['ccaddress1'])){$subscription->ccaddress1 = $formpost['ccaddress1'];}
	if(isset($formpost['ccaddress2'])){$subscription->ccaddress2 = $formpost['ccaddress2'];}
	if(isset($formpost['cccity'])){$subscription->cccity = $formpost['cccity'];}
	if(isset($formpost['selectedccstate'])){$subscription->selectedccstate = $formpost['ccstate'];}
	if(isset($formpost['ccstate'])){$subscription->ccstate = $formpost['ccstate'];}
	if(isset($formpost['ccpostalcode'])){$subscription->ccpostalcode = $formpost['ccpostalcode'];}
	if(isset($formpost['username'])){$subscription->username = $formpost['username'];}
	if(isset($formpost['screenname'])){$subscription->screenname = $formpost['screenname'];}
	if(isset($formpost['password'])){$subscription->password = $formpost['password'];}
	if(isset($formpost['confirmpassword'])){$subscription->confirmpassword = $formpost['confirmpassword'];}
		
	if(isset($formpost['newslettersall']) || 
			isset($formpost['newsletters_fromtheeditor']) ||
			isset($formpost['newsletters_specialoffers']) ||
			isset($formpost['newsletters_harperauctions']) ||
			isset($formpost['newsletters_traveloffice']) || 
			isset($formpost['newsletters_porthos'])){
		$subscription->newslettersall = $formpost['newslettersall'] ? 1 : 0;
		$subscription->newsletters_fromtheeditor = $formpost['newsletters_fromtheeditor'] ? 1 : 0;
		$subscription->newsletters_specialoffers = $formpost['newsletters_specialoffers'] ? 1 : 0;
		$subscription->newsletters_harperauctions = $formpost['newsletters_harperauctions'] ? 1 : 0;
		$subscription->newsletters_traveloffice = $formpost['newsletters_traveloffice'] ? 1 : 0;
		$subscription->newsletters_porthos = $formpost['newsletters_porthos'] ? 1 : 0;
	}
	if(isset($formpost['agreetoterms'])){
		$subscription->agreetoterms = 1;
	}
	
	drupal_write_record('subscribe', $subscription, 'id');
}

function subscription_get_summary_data(&$vars){
	watchdog("subscription", 'subscription_preprocess_subscriptionthemeplaceorder', NULL, WATCHDOG_DEBUG);
	
	$subscription = subscription_get_subscription();
	$membershipoffer = node_load($subscription->membershipofferid);
	
	$vars['years'] = $membershipoffer->subscriptionlength/12;
	$vars['offer'] = $membershipoffer->title;
	$vars['changelink'] = 'editdata/placeorder';
	$vars['changeregistrationlink'] = 'registration';
	switch($subscription->country){
		case 'US':
			$vars['price'] = $membershipoffer->usprice;
			break;
		case 'CA':
			$vars['price'] = $membershipoffer->canadianprice;
			break;
		default:
			$vars['price'] = $membershipoffer->internationalprice;
			break;
	}	
	switch($subscription->cctype){
		case 'americanexpress':
			$vars['cctypeimage'] = $base_uri.'/'.drupal_get_path('module', 'subscription').'/img/icon-amex.gif';
			break;
		case 'mastercard':
			$vars['cctypeimage'] = $base_uri.'/'.drupal_get_path('module', 'subscription').'/img/icon-mastercard.gif';
			break;
		case 'visa':
			$vars['cctypeimage'] = $base_uri.'/'.drupal_get_path('module', 'subscription').'/img/icon-visa.gif';
			break;
	}
	$vars['cclastfour'] = substr($subscription->ccnumber, (-4));
	$vars['ccfullname'] = $subscription->ccname;
	$vars['ccaddress1'] = $subscription->ccaddress1;
	$vars['ccaddress2'] = $subscription->ccaddress2;
	$vars['cccitystate'] = $subscription->cccity.', '.$subscription->ccstate;
	$vars['cccountryname'] = subscription_get_countryname($subscription->cccountry); //this is not efficient at all, but I want to put this code on staging tonight
	$vars['username'] = $subscription->username;
	$vars['password'] = $subscription->password;
	$vars['screenname'] = $subscription->screenname;
	$vars['emailaddress'] = $subscription->email;
	$vars['fullname'] = $subscription->firstname.' '.$subscription->lastname;
	$vars['address1'] = $subscription->address1;
	$vars['address2'] = $subscription->address2;
	$vars['address3'] = $subscription->address3;
	$vars['citystate'] = $subscription->city.', '.$subscription->state;
	$vars['countryname'] = subscription_get_countryname($subscription->country); //this is not efficient at all, but I want to put this code on staging tonight
	$vars['daytimephone'] = $subscription->daytimephone;
	$vars['mobilephone'] = $subscription->mobilephone;
		
	$vars['newsletters_fromtheeditor'] = $subscription->newsletters_fromtheeditor;
	$vars['newsletters_specialoffers'] = $subscription->newsletters_specialoffers;
	$vars['newsletters_harperauctions'] = $subscription->newsletters_harperauctions;
	$vars['newsletters_traveloffice'] = $subscription->newsletters_traveloffice;
	$vars['newsletters_porthos'] = $subscription->newsletters_porthos;
}

function subscription_send_order(&$vars){
	$subscription = subscription_get_subscription();
	
	$membershipoffer = node_load($subscription->membershipofferid);
	switch($subscription->country) {
		case 'US':
			$price = $membershipoffer->usprice;
			break;
		case 'CA':
			$price = $membershipoffer->canadianprice;
			break;
		default:
			$price = $membershipoffer->internationalprice;
			break;
	}
		
	$currentdate = date("Y-m-d");
	$expdate = date("Y-m-d",strtotime(date("Y-m-d", strtotime($currentdate)) . " +1 year"));
	
	$newdata = array(
		'salutation' 			=> subscription_get_prefixvalue($subscription->prefix), 
		'firstname' 			=> $subscription->firstname, 
		'middleinitial' 		=> $subscription->middleinitial, 
		'lastname' 				=> $subscription->lastname, 
		'suffix' 				=> subscription_get_suffixvalue($subscription->suffix), 
		'professionaltitle' 	=> '', 
		'email' 				=> $subscription->email, 
		'businessname' 			=> $subscription->businessname, 
		'address1' 				=> $subscription->address1, 
		'address2' 				=> $subscription->address2, 
		'address3' 				=> $subscription->address3,
		'city' 					=> $subscription->city, 
		'state' 				=> $subscription->state, 
		'postalcode' 			=> $subscription->postalcode, 
		'country' 				=> $subscription->country, 
		'phone' 				=> $subscription->daytimephone, 
		'ccnum' 				=> $subscription->ccnumber, 
		'ccexpmonth' 			=> $subscription->ccexpmonth, 
		'ccexpyear' 			=> subscription_get_yearvalue($subscription->ccexpyear), 
		'amountpaid' 			=> $price, 
		'ccname' 				=> $subscription->ccname, 
		'ccaddress' 			=> $subscription->ccaddress1, 
		'cccity' 				=> $subscription->cccity, 
		'ccstate' 				=> $subscription->ccstate, 
		'ccpostalcode' 			=> $subscription->postalcode, 
		'pubcode' 				=> $membershipoffer->pubcode, 
		'username' 				=> $subscription->username, 
		'pwd' 					=> $subscription->password, 
		'keycode' 				=> $membershipoffer->keycode, 
		'subscriptionlength' 	=> $membershipoffer->subscriptionlength, 
		'source' 				=> $membershipoffer->source, 
		'customertype' 			=> 'PERSONAL', 
		'expiredate' 			=> $expdate, 
		'startdate' 			=> $currentdate,
		'newsletters' 			=> '',
		'mobilephone' 			=> $subscription->mobilephone,
		'secondemail'			=> $subscription->secondemail,
		'methodofpayment'		=> $subscription->cctype,
		'cccountry'				=> $subscription->cccountry,
		'ccaddress2'			=> $subscription->ccaddress2,
		'screenname'			=> $subscription->screenname
	);
	
	$customerwebservice = subscription_get_customerwebservice();
	$process_result = $customerwebservice->SubscribeNewUser($newdata);
	
	$subscription->memberid = $process_result->SubscribeNewUserResult->Customer->SfgId;    
	$subscription->responsecode = $process_result->SubscribeNewUserResult->ResponseCode;
	//If the ResponseCode = 0, we'll perform the email validation
	/**
	 * 302 bad cc
	 * 402 err processing suborderinsert (test mode at sfg?)
	 * 200 err at AH (is path to email correct at web service?)
	 * 105 dupe username	 
	 */
	
	drupal_write_record('subscribe', $subscription, 'id');
	if($subscription->responsecode) {
		$default = 'There was an error submitting your order, please review your data and try again.';
		$error = subscription_get_errormessage($subscription->responsecode);
		
		return $error ? $error : $default;
	} 
	
	return $subscription->subscription;
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

function subscription_get_confirmation_data(&$vars){
	$subscription = subscription_get_subscription();	
	$vars['subscription'] = $subscription;
	$name = empty($subscription->prefix) ? '' : $subscription->prefix.' ';
	$name .= $subscription->firstname.' ';
	$name .= empty($subscription->middleinitial) ? '' : $subscription->middleinitial.' ';
	$name .= $subscription->lastname;
	$name .= empty($subscription->suffix) ? '' : ' '.$subscription->suffix;
	$vars['name'] = $name;
}

function subscription_get_countryname($alpha2) {	
	$countryname = 'United States'; 
	switch($alpha2){
		case 'US': 
			break;
		case 'CA':
			$countryname = 'Canada';
			break;
		default:
			$customerwebservice = subscription_get_customerwebservice();
			$countries_result = $customerwebservice->GetISOCountries(); 
			$countries = $countries_result->GetISOCountriesResult->ISO3166;
			
			foreach ($countries as $country) {
				if($country->Alpha2 == $alpha2){
					$countryname = $country->Name;
					break;
				}
			}
			break;
	}
	return $countryname;
}