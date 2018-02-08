<?php

function subscription_validate_placeorder(&$vars){	
	watchdog("subscription", 'subscription_validate_placeorder', NULL, WATCHDOG_DEBUG);
	$is_valid = TRUE;
	$vars['prefix_required_errorclass'] = 'error-hidden';
	$vars['firstname_required_errorclass'] = 'error-hidden';
	$vars['lastname_required_errorclass'] = 'error-hidden';
	$vars['country_required_errorclass'] = 'error-hidden';
	$vars['address1_required_errorclass'] = 'error-hidden';
	$vars['city_required_errorclass'] = 'error-hidden';
	$vars['state_required_errorclass'] = 'error-hidden';
	$vars['zip_required_errorclass'] = 'error-hidden';
	$vars['phone_required_errorclass'] = 'error-hidden';
	$vars['email_required_errorclass'] = 'error-hidden';
	$vars['email_invalid_errorclass'] = 'error-hidden';
	$vars['email_unavailable_errorclass'] = 'error-hidden';
	$vars['secondemail_invalid_errorclass'] = 'error-hidden';
	$vars['secondemail_unavailable_errorclass'] = 'error-hidden';
	$vars['cctype_required_errorclass'] = 'error-hidden';
	$vars['ccnumber_required_errorclass'] = 'error-hidden';
	$vars['ccexp_required_errorclass'] = 'error-hidden';
	$vars['ccname_required_errorclass'] = 'error-hidden';
	$vars['cccountry_required_errorclass'] = 'error-hidden';
	$vars['ccaddress_required_errorclass'] = 'error-hidden';
	$vars['cccity_required_errorclass'] = 'error-hidden';
	$vars['ccstate_required_errorclass'] = 'error-hidden';
	$vars['cczip_required_errorclass'] = 'error-hidden';
	if($vars['form']['#post']){	
		if(!aherrormessages_validate_required($vars['form']['#post']['prefix'])) { 
			$vars['prefix_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['firstname'])) { 
			$vars['firstname_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['lastname'])) { 
			$vars['lastname_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['country'])) { 
			$vars['country_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['address1'])) { 
			$vars['address1_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['city'])) { 
			$vars['city_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['state'])) { 
			$vars['state_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['postalcode'])) { 
			$vars['zip_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['daytimephone'])) { 
			$vars['phone_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['email'])) { 
			$vars['email_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_email($vars['form']['#post']['email'])) { 
			$vars['email_invalid_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_username_available($vars['form']['#post']['email'])) { 
			$vars['email_unavailable_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if($vars['form']['#post']['secondemail']){
			if(!aherrormessages_validate_email($vars['form']['#post']['secondemail'])) { 
				$vars['secondemail_invalid_errorclass'] = 'error-visible';
				$is_valid = FALSE;
			}
			if(!aherrormessages_validate_username_available($vars['form']['#post']['secondemail'])) { 
				$vars['secondemail_unavailable_errorclass'] = 'error-visible';
				$is_valid = FALSE;
			}
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['cctype'])) { 
			$vars['cctype_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['ccnumber'])) { 
			$vars['ccnumber_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		};
		if(!aherrormessages_validate_dateafter($vars['form']['#post']['ccexpmonth'].'-'.subscription_get_yearvalue($vars['form']['#post']['ccexpyear']))) { 
			$vars['ccexp_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['ccname'])) { 
			$vars['ccname_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['cccountry'])) { 
			$vars['cccountry_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['ccaddress1'])) { 
			$vars['ccaddress_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['cccity'])) { 
			$vars['cccity_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['ccstate'])) { 
			$vars['ccstate_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['ccpostalcode'])) { 
			$vars['cczip_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
	}
	return $is_valid;
}

function subscription_validate_registration(&$vars){
	watchdog("subscription", 'subscription_validate_registration', NULL, WATCHDOG_DEBUG);
	
	$is_valid = TRUE;
	$vars['username_required_errorclass'] = 'error-hidden';
	$vars['username_available_errorclass'] = 'error-hidden';
	$vars['password_required_errorclass'] = 'error-hidden';
	$vars['password_length_errorclass'] = 'error-hidden';
	$vars['password_mismatch_errorclass'] = 'error-hidden';
	$vars['confirmpassword_required_errorclass'] = 'error-hidden';
	$vars['screenname_required_errorclass'] = 'error-hidden';
	$vars['screenname_available_errorclass'] = 'error-hidden';
	if($vars['form']['#post']){	
		if(!aherrormessages_validate_required($vars['form']['#post']['username'])) { 
			$vars['username_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_username_available($vars['form']['#post']['username'])) { 
			$vars['username_available_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['password'])) { 
			$vars['password_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_length_gte($vars['form']['#post']['password'], 7)) { 
			$vars['password_length_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if($vars['form']['#post']['password'] != $vars['form']['#post']['confirmpassword']) { 
			$vars['password_mismatch_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['confirmpassword'])) { 
			$vars['confirmpassword_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if(!aherrormessages_validate_required($vars['form']['#post']['screenname'])) { 
			$vars['screenname_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
		if($vars['form']['#post']['screenname'] == $vars['form']['#post']['username']){
			$vars['screenname_available_errorclass'] = $vars['username_available_errorclass'];
		}
		else{
			if(!aherrormessages_validate_username_available($vars['form']['#post']['screenname'])) { 
				$vars['screenname_available_errorclass'] = 'error-visible';
				$is_valid = FALSE;
			}
		}
	}
	return $is_valid;
}

function subscription_validate_summary(&$vars){	
	watchdog("subscription", 'subscription_validate_summary', NULL, WATCHDOG_DEBUG);
	
	$is_valid = TRUE;
	$vars['agreetoterms_required_errorclass'] = 'error-hidden';
	if($vars['form']['#post']){	
		if(!aherrormessages_validate_required($vars['form']['#post']['agreetoterms'])) { 
			$vars['agreetoterms_required_errorclass'] = 'error-visible';
			$is_valid = FALSE;
		}
	}
	return $is_valid;
}

function subscription_get_errormessage($errorcode){	
	$aherrormessage = db_fetch_object(db_query('SELECT a.nid FROM {aherrormessages} a JOIN {node} b ON a.nid = b.nid WHERE a.errorcode = "%s"', $errorcode));
	if($aherrormessage){
		$aherrormessagenode = node_load($aherrormessage->nid);
		return $aherrormessagenode->body;
	}
	return '';
}
