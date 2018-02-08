
$(document).ready(function() {		
	populate_regions();
	populate_cc_regions();	
	$("#edit-prefix").change(function() { 
		if($("#edit-prefix").val() == 0){
			$("#prefix_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-prefix").addClass('element-error'); 
		} 
		else{
			$("#prefix_required").addClass('error-hidden').removeClass('error-visible'); 	
			$("#edit-prefix").removeClass('element-error'); 	
		}
	});
	$("#edit-firstname").change(function() { 
		if(!$("#edit-firstname").val()){
			$("#firstname_required").addClass('error-visible').removeClass('error-hidden');
			$("#edit-firstname").addClass('element-error');  
		} 
		else{
			$("#firstname_required").addClass('error-hidden').removeClass('error-visible'); 
			$("#edit-firstname").removeClass('element-error'); 			
		}
	});
	$("#edit-lastname").change(function() { 
		if(!$("#edit-lastname").val()){ 
			$("#lastname_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-lastname").addClass('element-error'); 
		}
		else{
			$("#lastname_required").addClass('error-hidden').removeClass('error-visible'); 
			$("#edit-lastname").removeClass('element-error'); 			
		}
	});
	$("#edit-address1").change(function() { 
		if($("#edit-billingsame").is(":checked")) {
			clear_billing_address_fields(); 
		} 
		if(!$("#edit-address1").val()){
			$("#address1_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-address1").addClass('element-error'); 
		} 
		else{
			$("#address1_required").addClass('error-hidden').removeClass('error-visible'); 	
			$("#edit-address1").removeClass('element-error'); 				
		}
	});
	$("#edit-address2").change(function() { if($("#edit-billingsame").is(":checked")) { clear_billing_address_fields(); } });
	$("#edit-city").change(function() { 
		if($("#edit-billingsame").is(":checked")) { 
			clear_billing_address_fields(); 
		}
		if(!$("#edit-city").val()){
			$("#city_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-city").addClass('element-error'); 
		} 
		else{
			$("#city_required").addClass('error-hidden').removeClass('error-visible'); 		
			$("#edit-city").removeClass('element-error'); 				
		}		
	});
	$("#edit-postalcode").change(function() { 
		if($("#edit-billingsame").is(":checked")) { 
			clear_billing_address_fields(); 
		} 
		if(!$("#edit-postalcode").val()){
			$("#zip_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-postalcode").addClass('element-error'); 
		} 
		else{
			$("#zip_required").addClass('error-hidden').removeClass('error-visible'); 			
			$("#edit-postalcode").removeClass('element-error'); 				
		}
	});
	$("#edit-country").change(function() { 
		populate_regions();
		if($("#edit-billingsame").is(":checked")) { 
			clear_billing_address_fields(); 
		} 
		if($("#edit-country").val() == 0){
			$("#country_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-country").addClass('element-error'); 
		} 
		else{
			$("#country_required").addClass('error-hidden').removeClass('error-visible'); 			
			$("#edit-country").removeClass('element-error'); 
				
			$("#edit-selectedcountry").val($("#edit-country").val());
		}			
	});
	$("#edit-state").change(function() { 
		if($("#edit-billingsame").is(":checked")) { 
			clear_billing_address_fields(); 
		}
		if($("#edit-state").val() == 0){
			$("#state_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-state").addClass('element-error'); 
		} 
		else{
			$("#state_required").addClass('error-hidden').removeClass('error-visible'); 				
			$("#edit-state").removeClass('element-error'); 						
		}
	});
	$("#edit-email").change(function() {
		//Hide error messages
		$("#email_required").removeClass("error-visible").addClass("error-hidden");	
		$("#email_invalid_error").removeClass("error-visible").addClass("error-hidden");	
		$("#email_unavailable_error").removeClass("error-visible").addClass("error-hidden");	
		$("#edit-email").removeClass('element-error'); 	
				
		//Show checking message
		$("#email_checking_availability_status").removeClass("error-hidden").addClass("error-visible");		
		
		if(!$("#edit-email").val()){
			//Email empty, show "required" message
			$("#email_required").removeClass("error-hidden").addClass("error-visible");	
			$("#edit-email").addClass('element-error'); 	
			//Hide checking message
			$("#email_checking_availability_status").removeClass("error-visible").addClass("error-hidden");		
		}
		else{
			//Has email, see if it is valid 
			$.getJSON('/subscribe/validateemail/' + $("#edit-email").val(), function(data) {
				$.each(data, function(key, val) {
					if(val) {
						//Email is valid, see if it is available
						$.getJSON('/subscribe/isavailablenameemail/' + $("#edit-email").val(), function(data) {
							$.each(data, function(key, val) {
								if(val) {	
									//Email is in not in use, hide checking message
									$("#email_checking_availability_status").removeClass("error-visible").addClass("error-hidden");	
								} else {  
									//Email is in use, show "unavailable" message
									$("#email_unavailable_error").removeClass("error-hidden").addClass("error-visible");	
									$("#edit-email").addClass('element-error'); 	
									
									//Hide checking message
									$("#email_checking_availability_status").removeClass("error-visible").addClass("error-hidden");	 							
								}
							});
						});
					} else {   
						//Email is not valid, show invalid message
						$("#email_invalid_error").removeClass("error-hidden").addClass("error-visible");	
						$("#edit-email").addClass('element-error'); 	
						
						//Hide checking message
						$("#email_checking_availability_status").removeClass("error-visible").addClass("error-hidden");							
					}
				});
			});
		}
	});
	$("#edit-secondemail").change(function() {
		//Hide error messages
		$("#secondemail_invalid_error").removeClass("error-visible").addClass("error-hidden");	
		$("#secondemail_unavailable_error").removeClass("error-visible").addClass("error-hidden");	
		$("#edit-secondemail").removeClass('element-error'); 	
				
		//Show checking message
		$("#secondemail_checking_availability_status").removeClass("error-hidden").addClass("error-visible");		
		
		if(!$("#edit-secondemail").val()){	
			//Hide checking message
			$("#secondemail_checking_availability_status").removeClass("error-visible").addClass("error-hidden");		
		}
		else{
			//Has email, see if it is valid 
			$.getJSON('/subscribe/validateemail/' + $("#edit-secondemail").val(), function(data) {
				$.each(data, function(key, val) {
					if(val) {
						//Email is valid, see if it is available
						$.getJSON('/subscribe/isavailablenameemail/' + $("#edit-secondemail").val(), function(data) {
							$.each(data, function(key, val) {
								if(val) {	
									//Email is in not in use, hide checking message
									$("#secondemail_checking_availability_status").removeClass("error-visible").addClass("error-hidden");	
								} else {   
									//Email is in use, show "unavailable" message
									$("#secondemail_unavailable_error").removeClass("error-hidden").addClass("error-visible");	
									$("#edit-secondemail").addClass('element-error'); 	
									
									//Hide checking message
									$("#secondemail_checking_availability_status").removeClass("error-visible").addClass("error-hidden");								
								}
							});
						});
					} else {   
						//Email is not valid, show invalid message
						$("#secondemail_invalid_error").removeClass("error-hidden").addClass("error-visible");	
						$("#edit-secondemail").addClass('element-error'); 	
						
						//Hide checking message
						$("#secondemail_checking_availability_status").removeClass("error-visible").addClass("error-hidden");							
					}
				});
			});
		}
	});
	$("#edit-daytimephone").change(function() { 
		if(!$("#edit-daytimephone").val()){ 
			$("#phone_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-daytimephone").addClass('element-error'); 	
		}
		else{
			$("#phone_required").addClass('error-hidden').removeClass('error-visible'); 
			$("#edit-daytimephone").removeClass('element-error'); 	
		}
	});
	$("#edit-billingsame").change(function() {   
		if($("#edit-billingsame").is(":checked")) { 
			populate_billing_address_fields(); 
		}
	});
	$("input[name='cctype']").change(function() { 
		if(!$("input[name='cctype']").val()){
			$("#cctype_required").addClass('error-visible').removeClass('error-hidden'); 
		} 
		else{
			$("#cctype_required").addClass('error-hidden').removeClass('error-visible'); 		
			if($("#edit-ccnumber").val() != "") { 
				validate_credit_card($("#edit-ccnumber").val()); 
			}  	
		}
	});
	$("#edit-ccnumber").change(function() { 
		validate_credit_card($("#edit-ccnumber").val()); 
	});
	$("#edit-ccname").change(function() { 
		if(!$("#edit-ccname").val()){
			$("#ccname_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-ccname").addClass('element-error'); 	
		} 
		else{
			$("#ccname_required").addClass('error-hidden').removeClass('error-visible'); 		
			$("#edit-ccname").removeClass('element-error'); 	
		}		
	});
	$("#edit-cccountry").change(function() { 		
		if($("#edit-cccountry").val() == 0){
			$("#cccountry_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-cccountry").addClass('element-error'); 	
		} 
		else{
			populate_cc_regions();
			
			$("#edit-selectedcccountry").val($("#edit-cccountry").val());	
			$("#cccountry_required").addClass('error-hidden').removeClass('error-visible'); 		
			$("#edit-cccountry").removeClass('element-error'); 			
		}		
	});
	$("#edit-cccity").change(function() { 
		if(!$("#edit-cccity").val()){
			$("#cccity_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-cccity").addClass('element-error'); 	
		} 
		else{
			$("#cccity_required").addClass('error-hidden').removeClass('error-visible');		
			$("#edit-cccity").removeClass('element-error'); 			 		
		}		
	});
	$("#edit-ccaddress1").change(function() { 
		if(!$("#edit-ccaddress1").val()){
			$("#ccaddress1_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-ccaddress1").addClass('element-error'); 	
		} 
		else{
			$("#ccaddress1_required").addClass('error-hidden').removeClass('error-visible'); 		
			$("#edit-ccaddress1").removeClass('element-error'); 			 					
		}		
	});	
	$("#edit-ccstate").change(function() { 
		if($("#edit-ccstate").val() == 0){
			$("#ccstate_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-ccstate").addClass('element-error'); 	
		} 
		else{
			$("#ccstate_required").addClass('error-hidden').removeClass('error-visible'); 		
			$("#edit-ccstate").removeClass('element-error'); 			 						
		}		
	});
	$("#edit-ccpostalcode").change(function() { 
		if(!$("#edit-ccpostalcode").val()){
			$("#cczip_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-ccpostalcode").addClass('element-error'); 	
		} 
		else{
			$("#cczip_required").addClass('error-hidden').removeClass('error-visible'); 		
			$("#edit-ccpostalcode").removeClass('element-error'); 			 						
		}		
	});
	$('#subscription-get-form-placeorder').submit(function() {
		return validate_form();
	});
});

function populate_regions() {	
	var country_name;
	switch($("#edit-country").val()){
		case "0":
		case "US":
		case "US1":
			country_name = "US";
			break;
		case "CA":
		case "CA1":
			country_name = "CA";
			break;
		default:
			country_name = $("#edit-country").val();
			break;
	}	
	var sel_country;
	switch($("#edit-selectedcountry").val()){
		case "0":
		case "US":
		case "US1":
			sel_country = "US";
			break;
		case "CA":
		case "CA1":
			sel_country = "CA";
			break;
		default:
			sel_country = $("#edit-selectedcountry").val();
			break;
	}
	
	if(country_name != sel_country){	
		//Hide error msg (might have been shown at some point)	
		$("#state_required").removeClass('error-visible').addClass('error-hidden');	
		//Show "loading" status 
		$("#state_loading_status").removeClass("error-hidden").addClass("error-visible");
		
		//Get regions for the selected country
		$.getJSON('/subscribe/getregions/' + country_name, function(data) {
			$("#edit-state").empty();    
			$.each(data, function(key, val) { 
				//Populate select box with regions returned by the service
				$("#edit-state").append(new Option(val, key, true, true)); 
				
				//If user had already selected a region, select it
				var current_state = $("#edit-selectedstate").val();
				if(!current_state){
					$("#edit-state").val("0"); 
				}
				else{
					$("#edit-state").val(current_state); 
				}				
			});	
			if($('#edit-state option').length <= 1){
				$("#edit-state").attr('disabled', 'disabled');
			}
			else{
				$("#edit-state").removeAttr('disabled');
			}
			//Finished populating the regions, hide "Loading" status
			$("#state_loading_status").removeClass("error-visible").addClass("error-hidden");
		}); 
	}
}

function populate_cc_regions() {
	var country_name;
	switch($("#edit-cccountry").val()){
		case "0":
		case "US":
		case "US1":
			country_name = "US";
			break;
		case "CA":
		case "CA1":
			country_name = "CA";
			break;
		default:
			country_name = $("#edit-cccountry").val();
			break;
	}	
	var sel_country;
	switch($("#edit-selectedcccountry").val()){
		case "0":
		case "US":
		case "US1":
			sel_country = "US";
			break;
		case "CA":
		case "CA1":
			sel_country = "CA";
			break;
		default:
			sel_country = $("#edit-selectedcccountry").val();
			break;
	}
			
	if(country_name != sel_country){	
		//Hide error msg (might have been shown at some point)	
		$("#ccstate_required").removeClass('error-visible').addClass('error-hidden');	
		//Show "loading" status 
		$("#ccstate_loading_status").removeClass("error-hidden").addClass("error-visible");
		
		//Get regions for the selected country
		$.getJSON('/subscribe/getregions/' + country_name, function(data) {
			$("#edit-ccstate").empty();    
			$.each(data, function(key, val) {
			
				//Populate select box with regions returned by the service
				$("#edit-ccstate").append(new Option(val, key, true, true)); 
			});		
			
			//If user had already selected a region, select it
			var current_state = $("#edit-selectedccstate").val();				
			if(!current_state){
				$("#edit-ccstate").val("0"); 
			}
			else{
				$("#edit-ccstate").val(current_state); 
			}
			//disable if no states
			if($('#edit-ccstate option').length <= 1){
				$("#edit-ccstate").attr('disabled', 'disabled');
			}
			else{
				$("#edit-ccstate").removeAttr('disabled');
			}
			//Finished populating the regions, hide "Loading" status
			$("#ccstate_loading_status").removeClass("error-visible").addClass("error-hidden");
		}); 	
	}
}

function populate_billing_address_fields() {
	$("#edit-cccountry").val($("#edit-country").val());	 
	$("#edit-selectedccstate").val($("#edit-state").val());	 
	populate_cc_regions(); 
	$("#edit-ccaddress1").val($("#edit-address1").val());
	$("#edit-ccaddress2").val($("#edit-address2").val());
	$("#edit-cccity").val($("#edit-city").val());
	$("#edit-ccstate").val($("#edit-state").val());
	$("#edit-ccpostalcode").val($("#edit-postalcode").val());
}

function clear_billing_address_fields() {
  $("#edit-billingsame").removeAttr("checked");
  $("#edit-cccountry").val("0");
  $("#edit-ccaddress1").val("");
  $("#edit-ccaddress2").val("");
  $("#edit-cccity").val("");
  $("#edit-ccstate").val("0");
  $("#edit-ccpostalcode").val("");
}

function validate_credit_card($card_number) {
	//Hide error msg (might have been shown at some point)	
	$("#ccnumber_required").removeClass('error-visible').addClass('error-hidden');	
	$("#ccnumber_invalid_error").removeClass('error-visible').addClass('error-hidden');	
	$("#cctype_required").removeClass("error-visible").addClass("error-hidden");
	$("#edit-ccnumber").removeClass('element-error'); 	
	
	//Show "loading" status 
	$("#validating_cc_status").removeClass("error-hidden").addClass("error-visible");
	
	//Get type of card to validate
	if($("input[name='cctype']:checked").val()) {   
		if(!$card_number){
			//No card number, show "required" message
			$("#ccnumber_required").removeClass("error-hidden").addClass("error-visible");
			$("#edit-ccnumber").addClass('element-error'); 	
			
			//hide "loading" status 
			$("#validating_cc_status").removeClass("error-visible").addClass("error-hidden");
		}
		else{
			$card_type = $("input[name='cctype']:checked").val();
			$.getJSON('/subscribe/validateccnumber/' + $card_number + '/' + $card_type, function(data) {
				//hide "loading" status 
				$("#validating_cc_status").removeClass("error-visible").addClass("error-hidden");	
				
				$.each(data, function(key, val) {
					if(!val) {
						//Card number is invalid, show error
						$("#ccnumber_invalid_error").removeClass("error-hidden").addClass("error-visible");
						$("#edit-ccnumber").addClass('element-error'); 	
					}
				});
			});
		}
	}
	else{
		//No card type selected, show error
		$("#cctype_required").removeClass("error-hidden").addClass("error-visible");
		//hide "loading" status 
		$("#validating_cc_status").removeClass("error-visible").addClass("error-hidden");	
	}
}

function validate_form(){
		var result = true; 
		if($("#edit-prefix").val() == 0){ 
			$("#prefix_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-prefix").addClass('element-error'); 
			result = false;
		}
		if(!$("#edit-firstname").val()){
			$("#firstname_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-firstname").addClass('element-error'); 
			result = false;
		} 
		if(!$("#edit-lastname").val()){ 
			$("#lastname_required").addClass('error-visible').removeClass('error-hidden');
			$("#edit-lastname").addClass('element-error'); 
			result = false; 
		}
		if($("#edit-country").val() == 0){ 
			$("#country_required").addClass('error-visible').removeClass('error-hidden');
			$("#edit-country").addClass('element-error'); 
			result = false; 
		}
		if(!$("#edit-address1").val()){ 
			$("#address1_required").addClass('error-visible').removeClass('error-hidden');
			$("#edit-address1").addClass('element-error');  
			result = false;
		}
		if(!$("#edit-city").val()){ 
			$("#city_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-city").addClass('element-error'); 
			result = false;
		}
		if($("#edit-state").val() == 0){ 
			if($('#edit-state option').length > 1){
				$("#state_required").addClass('error-visible').removeClass('error-hidden'); 
				$("#edit-state").addClass('element-error'); 
				result = false;				
			}
		}
		if(!$("#edit-postalcode").val()){ 
			$("#zip_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-postalcode").addClass('element-error'); 
			result = false;
		}
		if(!$("#edit-daytimephone").val()){ 
			$("#phone_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-daytimephone").addClass('element-error'); 
			result = false;
		}
		if(!$("#edit-email").val()){ 
			$("#email_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-email").addClass('element-error'); 
			result = false;
		}
		if(!$("input[name='cctype']").val()){
			$("#cctype_required").addClass('error-visible').removeClass('error-hidden'); 
			result = false;
		}
		if(!$("#edit-ccnumber").val()){ 
			$("#ccnumber_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-ccnumber").addClass('element-error'); 
			result = false;
		}
		if(!$("#edit-ccexpmonth").val()){ 
			$("#ccexpmonth_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-ccexpmonth").addClass('element-error'); 
			result = false;
		}
		if(!$("#edit-ccexpyear").val()){ 
			$("#ccexpyear_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-ccexpyear").addClass('element-error'); 
			result = false;
		}
		if(!$("#edit-ccname").val()){ 
			$("#ccname_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-ccname").addClass('element-error'); 
			result = false;
		}
		if($("#edit-cccountry").val() == 0){ 
			$("#cccountry_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-cccountry").addClass('element-error'); 
			result = false;
		}
		if(!$("#edit-ccaddress1").val()){ 
			$("#ccaddress1_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-ccaddress1").addClass('element-error'); 
			result = false;
		}
		if(!$("#edit-cccity").val()){ 
			$("#cccity_required").addClass('error-visible').removeClass('error-hidden'); 
			$("#edit-cccity").addClass('element-error'); 
			result = false;
		}
		if($("#edit-ccstate").val() == 0){ 
			if($('#edit-ccstate option').length > 1){
				$("#ccstate_required").addClass('error-visible').removeClass('error-hidden'); 
				$("#edit-ccstate").addClass('element-error'); 
				result = false;
			}
		}
		if(!$("#edit-ccpostalcode").val()){ 
			$("#cczip_required").addClass('error-visible').removeClass('error-hidden');
			$("#edit-ccpostalcode").addClass('element-error');  
			result = false;
		}
		return result;
}

