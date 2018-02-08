<div id="registrationform-wrapper" class="container_24">	
	<div class="grid_20 prefix_1">
		<h1>SUMMARY</h1>
	</div>
	
	<div class="grid_22 prefix_1 submission-error drop_12">
		<?php print $error; ?>
	</div>
	
	<h3 class="grid_20 prefix_1 drop_12">
		Please review your order before clicking &ldquo;Place Order.&rdquo;
	</h3>
		
	<div class="grid_20 prefix_1">
		If you need assistance, please <a href="mailto:membership@andrewharper.com">email</a> Andrew Harper Member Services or call (866) 831-4314 USA or +1 (512) 904-7342 International. Our offices are open Monday through Friday, 8 a.m.-6 p.m. (CST).
	</div>
	<div class="grid_24 form-wrapper drop_12">
		<h2 class="grid_22 prefix_1">Order Details</h2>
		
		<div class="grid_22 prefix_1">
			<h3>Membership Type:</h3> <?php print $years; ?>-year <?php print $offer; ?> Membership
		</div>
		
		<div class="grid_22 prefix_1 drop_12">
			<h3>Total:</h3> $  <?php print $price; ?>
		</div>
		
		<div class="grid_22 prefix_1">
			<h3>Payment Method:</h3>
		</div>
		<div class="grid_22 prefix_1 drop_12">
			<img src="<?php print $cctypeimage; ?>" /> ending in <?php print $cclastfour; ?>
		</div>
		
		<div class="grid_22 prefix_1">
			<h3>Billing Address:</h3>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $ccfullname; ?>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $ccaddress1; ?>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $ccaddress2; ?>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $cccitystate; ?>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $cccountryname; ?>
		</div>
		
		<div class="grid_22 prefix_1 drop_12">
			<a href="<?php print $changelink; ?>">Change</a>
		</div>
				
		<div class="grid_22 prefix_1 drop_12">
			<hr class="horizontal-rule" />
		</div>
		
		<h2 class="grid_22 prefix_1">Account Details</h2>
		
		<div class="grid_22 prefix_1">
			<h3>User Name:</h3> <?php print $username; ?>
		</div>
		
		<div class="grid_22 prefix_1">
			<h3>Password:</h3> <?php print $password; ?>
		</div>
		
		<div class="grid_22 prefix_1 drop_12">
			<h3>Screen Name:</h3> <?php print $screenname; ?>
		</div>
		
		<div class="grid_22 prefix_1 drop_12">
			<h3>Email Address:</h3> <?php print $emailaddress; ?>
		</div>
				
		<div class="grid_22 prefix_1">
			<h3>Mailing Address:</h3>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $fullname; ?>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $address1; ?>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $address2; ?>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $address3; ?>
		</div>
		<div class="grid_22 prefix_1">
			<?php print $citystate; ?>
		</div>
		<div class="grid_22 prefix_1 drop_12">
			<?php print $countryname; ?>
		</div>
		
		<div class="grid_22 prefix_1">
			<h3>Daytime Phone:</h3><?php print $daytimephone; ?>
		</div>
		
		<div class="grid_22 prefix_1">
			<h3>Mobile Phone:</h3><?php print $mobilephone; ?>
		</div>
		
		<div class="grid_22 prefix_1 drop_12">
			<a href="<?php print $changelink; ?>">Change</a>
		</div>
		
		<div class="grid_22 prefix_1">
			<hr class="horizontal-rule" />
		</div>
		
		
		<h2 class="grid_22 prefix_1">Email Preferences</h2>
		
		<div class="grid_22 prefix_1">
			You have chosen to receive the following Andrew Harper email newsletters:
		</div>
		
		<ul class="grid_22 prefix_1">
			<li class="grid_21 <?php print $newsletters_fromtheeditor ? 'visible-element' : 'hidden-element'; ?>">From the Editor</li>
			<li class="grid_21 <?php print $newsletters_specialoffers ? 'visible-element' : 'hidden-element'; ?>">Special Offers</li>
			<li class="grid_21 <?php print $newsletters_harperauctions ? 'visible-element' : 'hidden-element'; ?>">Harper Auctions</li>
			<li class="grid_21 <?php print $newsletters_traveloffice ? 'visible-element' : 'hidden-element'; ?>">Travel Office</li>
			<li class="grid_21 <?php print $newsletters_porthos ? 'visible-element' : 'hidden-element'; ?>">Porthos</li>
		</ul>
		
		<div class="grid_22 prefix_1 drop_12">
			<a href="<?php print $changeregistrationlink; ?>">Change</a>
		</div>
	</div>
	
	<div class="grid_11 prefix_1 drop_12">				
		<?php print drupal_render($agreetoterms); ?><span>I agree to the <a href="terms-conditions">terms and conditions</a></span>
	</div>
	
	<div id="agreetoterms_required" class="grid_12 omega <?php print $agreetoterms_required_errorclass; ?>"><?php print subscription_get_errormessage('AGREETOTERMS_REQUIRED'); ?></div>
	
	<div class="grid_23 prefix_1">
		<input type="image" src="<?php print($base_uri.'/'.drupal_get_path('module', 'subscription').'/img/NextButton.gif'); ?>" />
	</div> 
</div>