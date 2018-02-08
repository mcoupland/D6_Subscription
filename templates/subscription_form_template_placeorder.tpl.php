<div id="placeorderform-wrapper" class="grid_24 alpha omega">	
	<div class="grid_20 prefix_2">
		<h1><?php print $membershipoffer->title; ?> Membership</h1>
	</div>
	<div class="grid_20 prefix_2 drop_12">
		<b><?php print $subscriptionlength; ?>-year <?php print $membershipoffer->title ?> membership:</b> $<?php print $membershipoffer->usprice ?> USA, $<?php print $membershipoffer->canadianprice ?> Canada, $<?php print $membershipoffer->internationalprice ?> Intl. <span class="parenthetical">All prices in USD</span>.
	</div>
	
	<div class="grid_20 prefix_2">
		<?php print $membershipoffer->body; ?>
	</div>
	
	<div class="grid_24 form-wrapper">
		<h2 class="grid_23 prefix_1 alpha omega">Enter your information</h2>
		<label class="grid_23 prefix_1 alpha omega">* <span class="parenthetical">Required field</span></label>
		<?php print drupal_render($selectedcountry); ?>
		<?php print drupal_render($selectedstate); ?>
		<?php print drupal_render($selectedcccountry); ?>
		<?php print drupal_render($selectedccstate); ?>
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Prefix: <span style="color:red">*</span></label>	
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($prefix); ?>
		</div>
		<div id="prefix_required" class="grid_12 omega <?php print $prefix_required_errorclass; ?>"><?php print subscription_get_errormessage('PREFIX_REQUIRED'); ?></div>
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>First Name: <span style="color:red">*</span></label>	
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($firstname); ?>
		</div>
		<div id="firstname_required" class="grid_12 omega <?php print $firstname_required_errorclass; ?>"><?php print subscription_get_errormessage('FIRSTNAME_REQUIRED'); ?></div>
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Middle Initial:</label>	
		</div>
		<div class="grid_23 prefix_1 alpha omega">
			<?php print drupal_render($middleinitial); ?>
		</div>
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Last Name: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($lastname); ?>
		</div>
		<div id="lastname_required" class="grid_12 omega <?php print $lastname_required_errorclass; ?>"><?php print subscription_get_errormessage('LASTNAME_REQUIRED'); ?></div>
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Business Name:</label>
		</div>
		<div class="grid_23 prefix_1 alpha omega">
			<?php print drupal_render($businessname); ?>
		</div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Suffix:</label>
		</div>
		<div class="grid_23 prefix_1 alpha omega">
			<?php print drupal_render($suffix); ?>
		</div>		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Country: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($country); ?>
		</div>
		<div id="country_required" class="grid_12 omega <?php print $country_required_errorclass; ?>"><?php print subscription_get_errormessage('COUNTRY_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Address 1: <span style="color:red">*</span></label>
			<?php $elementname = 'address1'; ?>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($address1); ?>
		</div>
		<div id="address1_required" class="grid_12 omega <?php print $address1_required_errorclass; ?>"><?php print subscription_get_errormessage('ADDRESS1_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Address 2:</label>
		</div>
		<div class="grid_23 prefix_1 alpha omega">
			<?php print drupal_render($address2); ?>
		</div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Address 3:</label>
		</div>
		<div class="grid_23 prefix_1 alpha omega">
			<?php print drupal_render($address3); ?>
		</div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>City: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($city); ?>
		</div>
		<div id="city_required"class="grid_12 omega <?php print $city_required_errorclass; ?>"><?php print subscription_get_errormessage('CITY_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>State/Region: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($state); ?>
		</div>
		<div id="state_loading_status" class="grid_12 omega error-hidden"><?php print subscription_get_errormessage('LOADING_STATUS'); ?></div>
		<div id="state_required" class="grid_12 omega <?php print $state_required_errorclass; ?>"><?php print subscription_get_errormessage('STATE_REQUIRED'); ?></div>
		
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>ZIP/Postal Code: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($postalcode); ?>
		</div>
		<div id="zip_required" class="grid_12 omega <?php print $zip_required_errorclass; ?>"><?php print subscription_get_errormessage('ZIP_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Daytime Phone: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($daytimephone); ?>
		</div>
		<div id="phone_required" class="grid_12 omega <?php print $phone_required_errorclass; ?>"><?php print subscription_get_errormessage('PHONE_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Mobile Phone:</label>
		</div>
		<div class="grid_23 prefix_1 alpha omega">
			<?php print drupal_render($mobilephone); ?>
		</div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Email: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($email); ?>
		</div>
		<div id="email_checking_availability_status" class="grid_12 omega error-hidden"><?php print subscription_get_errormessage('CHECKING_AVAILABILITY_STATUS'); ?></div>
		<div id="email_required" class="grid_12 omega <?php print $email_required_errorclass; ?>"><?php print subscription_get_errormessage('EMAIL_REQUIRED'); ?></div>
		<div id="email_invalid_error" class="grid_12 omega <?php print $email_invalid_errorclass; ?>"><?php print subscription_get_errormessage('EMAIL_INVALID_ERROR'); ?></div>
		<div id="email_unavailable_error" class="grid_12 omega <?php print $email_unavailable_errorclass; ?>"><?php print subscription_get_errormessage('USERNAME_UNAVAILABLE_ERROR'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Second Email:</label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($secondemail); ?>
		</div>
		<div id="secondemail_checking_availability_status" class="grid_12 omega error-hidden"><?php print subscription_get_errormessage('CHECKING_AVAILABILITY_STATUS'); ?></div>
		<div id="secondemail_invalid_error" class="grid_12 omega <?php print $secondemail_invalid_errorclass; ?>"><?php print subscription_get_errormessage('EMAIL_INVALID_ERROR'); ?></div>
		<div id="secondemail_unavailable_error" class="grid_12 omega <?php print $secondemail_unavailable_errorclass; ?>"><?php print subscription_get_errormessage('USERNAME_UNAVAILABLE_ERROR'); ?></div>
	</div>	
		
	<div class="grid_24 form-wrapper drop_12">
		<h2 class="grid_23 prefix_1 alpha omega">Enter your payment information</h2>
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<h3>Method of Payment</h3>:<span style="color:red">*</span>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($cctype); ?>	
		</div>
		<div id="cctype_required" class="grid_12 omega <?php print $cctype_required_errorclass; ?>"><?php print subscription_get_errormessage('CCTYPE_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Card Number: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($ccnumber); ?>
		</div>
		<div id="validating_cc_status" class="grid_12 omega error-hidden"><?php print subscription_get_errormessage('VALIDATING_CC_STATUS'); ?></div>
		<div id="ccnumber_required" class="grid_12 omega <?php print $ccnumber_required_errorclass; ?>"><?php print subscription_get_errormessage('CCNUMBER_REQUIRED'); ?></div>
		<div id="ccnumber_invalid_error" class="grid_12 omega <?php print $ccnumber_required_errorclass; ?>"><?php print subscription_get_errormessage('CCNUMBER_INVALID_ERROR'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Expiration Date: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($ccexpmonth); ?>
			<?php print drupal_render($ccexpyear); ?>
		</div>
		<div id="date_required" class="grid_12 omega <?php print $ccexp_required_errorclass; ?>"><?php print subscription_get_errormessage('DATE_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Name as it appears on card: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($ccname); ?>
		</div>
		<div id="ccname_required" class="grid_12 omega <?php print $ccname_required_errorclass; ?>"><?php print subscription_get_errormessage('CCNAME_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<h3>Billing Address:</h3>
		</div>
		<div class="grid_11 prefix_1 alpha">		
			<?php print drupal_render($billingsame); ?> Billing address is same as address above
		</div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Country: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($cccountry); ?>
		</div>
		<div id="cccountry_required" class="grid_12 omega <?php print $cccountry_required_errorclass; ?>"><?php print subscription_get_errormessage('COUNTRY_REQUIRED'); ?></div>
				
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Address 1: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($ccaddress1); ?>
		</div>
		<div id="ccaddress1_required" class="grid_12 omega <?php print $ccaddress_required_errorclass; ?>"><?php print subscription_get_errormessage('ADDRESS1_REQUIRED'); ?></div>
				
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Address 2:</label>
		</div>
		<div class="grid_23 prefix_1 alpha omega">
			<?php print drupal_render($ccaddress2); ?>
		</div>
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>City: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($cccity); ?>
		</div>
		<div id="cccity_required" class="grid_12 omega <?php print $cccity_required_errorclass; ?>"><?php print subscription_get_errormessage('CITY_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>State/Region: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($ccstate); ?>
		</div>
		<div id="ccstate_loading_status" class="grid_12 omega error-hidden"><?php print subscription_get_errormessage('LOADING_STATUS'); ?></div>
		<div id="ccstate_required" class="grid_12 omega <?php print $ccstate_required_errorclass; ?>"><?php print subscription_get_errormessage('STATE_REQUIRED'); ?></div>
		
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>ZIP/Postal Code: <span style="color:red">*</span></label>
		</div>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($ccpostalcode); ?>
		</div>
		<div id="cczip_required" class="grid_12 omega <?php print $cczip_required_errorclass; ?>"><?php print subscription_get_errormessage('ZIP_REQUIRED'); ?></div>
	</div>
			
	<div class="grid_22 prefix_1">
		<input id="placeorder_submit" type="image" src="<?php print($base_uri.'/'.drupal_get_path('module', 'subscription').'/img/NextButton.gif'); ?>" />
		<img src="<?php print $base_uri.'/'.drupal_get_path('module', 'subscription'); ?>/img/lock.gif" /> This form is secured for your protection
	</div>
</div>