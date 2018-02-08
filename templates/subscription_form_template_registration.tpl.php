<div id="registrationform-wrapper" class="grid_24 alpha omega">	
	<div class="grid_24 form-wrapper">
		<h2 class="grid_23 prefix_1 alpha omega">Create an account</h2>
		<label class="grid_23 prefix_1 alpha omega">Please create a user name, password, and screen name for your account.</label>
		<label class="grid_23 prefix_1 alpha omega drop_12">* <span class="parenthetical">Required field</span></label>
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Choose a User Name: <span style="color:red">*</span></label>	
		</div>
		<div class="grid_11 prefix_1 alpha drop_12">
			<?php print drupal_render($username); ?>
		</div>
		<div id="username_checking_availability_status" class="grid_12 omega error-hidden"><?php print subscription_get_errormessage('CHECKING_AVAILABILITY_STATUS'); ?></div>
		<div id="username_required" class="grid_12 omega <?php print $username_required_errorclass; ?>"><?php print subscription_get_errormessage('USERNAME_REQUIRED'); ?></div>
		<div id="username_available" class="grid_12 omega <?php print $username_available_errorclass; ?>"><?php print subscription_get_errormessage('USERNAME_UNAVAILABLE_ERROR'); ?></div>
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Choose a Password: <span style="color:red">*</span></label>	
		</div>
		<label class="grid_23 prefix_1 parenthetical">
			Passwords must be at least 7 characters.
		</label>
		<div class="grid_11 prefix_1 alpha drop_12">
			<?php print drupal_render($password); ?>
		</div>
		<div id="password_required" class="grid_12 omega <?php print $password_required_errorclass; ?>"><?php print subscription_get_errormessage('PASSWORD1_REQUIRED'); ?></div>
		<div id="password_length" class="grid_12 omega <?php print $password_length_errorclass; ?>"><?php print subscription_get_errormessage('PASSWORD_LENGTH_ERROR'); ?></div>
		<div id="password_mismatch" class="grid_12 omega <?php print $password_mismatch_errorclass; ?>"><?php print subscription_get_errormessage('PASSWORD_CONFIRMPASSWORD_MISMATCH'); ?></div>
		
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Confirm Password: <span style="color:red">*</span></label>	
		</div>
		<div class="grid_11 prefix_1 alpha drop_12">
			<?php print drupal_render($confirmpassword); ?>
		</div>
		<div id="confirmpassword_required" class="grid_12 omega <?php print $confirmpassword_required_errorclass; ?>"><?php print subscription_get_errormessage('PASSWORD2_REQUIRED'); ?></div>
			
		<div class="grid_23 prefix_1 alpha omega formfield-label">
			<label>Choose a Screen Name: <span style="color:red">*</span></label>	
		</div>
		<label class="grid_23 prefix_1 parenthetical">
			Your screen name appears on your member comments, auction bids and any outgoing messages when you are logged in to AndrewHarper.com.
		</label>
		<div class="grid_11 prefix_1 alpha">
			<?php print drupal_render($screenname); ?>
		</div>
		<div id="screenname_checking_availability_status" class="grid_12 omega error-hidden"><?php print subscription_get_errormessage('CHECKING_AVAILABILITY_STATUS'); ?></div>
		<div id="screenname_required" class="grid_12 omega <?php print $screenname_required_errorclass; ?>"><?php print subscription_get_errormessage('SCREENNAME_REQUIRED'); ?></div>
		<div id="screenname_available" class="grid_12 omega <?php print $screenname_available_errorclass; ?>"><?php print subscription_get_errormessage('SCREENNAME_UNAVAILABLE_ERROR'); ?></div>
	</div>
	
	<div class="grid_24 form-wrapper drop_12">
		<h2 class="grid_23 prefix_1 alpha omega">Email preferences</h2>
		<div class="grid_23 prefix_1 alpha omega drop_12">
			Andrew Harper offers several email newsletters to inform you of new publications, member benefits and special offers. 
			Choose any of the email newsletters below then click &ldquo;Next.&rdquo;
			Click &ldquo;View Sample&rdquo; to see an example of each newsletter.
			To stop a newsletter subscription in the future, simply follow the
			unsubscribe" link at the bottom of each email.
		</div>
		
		<div class="grid_1 prefix_1 alpha">
			<?php print drupal_render($newslettersall); ?> 
		</div>
		<div class="grid_22 omega drop_12 dedent_8 inline-header">	
			Select All Newsletters
		</div>
		
		<div class="grid_1 prefix_1 alpha">
			<?php print drupal_render($newsletters_fromtheeditor); ?>
		</div>
		<div class="grid_22 omega drop_12 dedent_8">	
			<span class="inline-header">From The Editor:</span> Monthly delivery of Hideaway Report Online, highlighting exclusive multimedia and feature articles, as well as the latest editorial news from Mr. Harper, plus Harper Collection updates, Footsteps Itineraries and blog posts of note. <a href="http://andrewharper.com/imagestore/images/samples/fromtheeditor_sample.html" target="_blank">View sample</a>
		</div>
					
		<div class="grid_1 prefix_1 alpha">
			<?php print drupal_render($newsletters_specialoffers); ?>
		</div>
		<div class="grid_22 omega drop_12 dedent_8">	
			<span class="inline-header">Special Offers:</span> Negotiated offers and promotions exclusively for our members from Andrew Harper-recommended hotels and travel partners. <a href="http://andrewharper.com/imagestore/images/samples/specialoffers_sample.html" target="_blank">View sample</a></div>
		
		<div class="grid_1 prefix_1 alpha">				
			<?php print drupal_render($newsletters_harperauctions); ?>
		</div>
		<div class="grid_22 omega drop_12 dedent_8">	
			<span class="inline-header">Harper Auctions:</span> Weekly alerts on the latest auction offers for stays at select Andrew Harper properties. Members can receive up to 45 percent off retail prices. <a href="http://andrewharper.com/imagestore/images/samples/auctions_sample.html" target="_blank">View sample</a>
		</div>	
			
		<div class="grid_1 prefix_1 alpha">				
			<?php print drupal_render($newsletters_traveloffice); ?>
		</div>
		<div class="grid_22 omega drop_12 dedent_8">	
			<span class="inline-header">Travel Office:</span> Timely news and travel information from the Andrew Harper Travel Office. Includes destination guides, insider travel advice, travel partner promotions and special offers from Andrew Harper properties. <a href="http://andrewharper.com/imagestore/images/samples/fromourpartners_sample.html" target="_blank">View sample</a>
		</div>	
				
		<div class="grid_1 prefix_1 alpha">			
			<?php print drupal_render($newsletters_porthos); ?>
		</div>
		<div class="grid_22 omega drop_12 dedent_8">	
			<span class="inline-header">Porthos:</span> Exclusive weekly specials offering members discounted "first-to-market" access to the world\'s cult and micro-production boutique wines. <a href="http://andrewharper.com/imagestore/images/samples/porthos_sample.html" target="_blank">View sample</a>
		</div>		
	</div>
	
	<div class="grid_23 prefix_1 drop_12">
		View our Privacy Policy <a href="privacy-policy" target="_blank">here</a>.
	</div>		
	
	<div class="grid_23 prefix_1">
		<input type="image" src="<?php print($base_uri.'/'.drupal_get_path('module', 'subscription').'/img/NextButton.gif'); ?>" />
	</div> 
</div>