
$(document).ready(function() {
	$("#edit-username").change(function() {	
		validate_username(true);
	});
		
	$("#edit-screenname").change(function() {	
		validate_screenname(true);
	});
	
	$("#edit-password").change(function(){	
		//password changed, clear out confirm password
		$("#edit-confirmpassword").val('');	
		validate_password();
	});
	
	$("#edit-confirmpassword").change(function(){	
		validate_confirmpassword();
	});
	
	//Handle changes to newsletter selections
	$("#edit-newslettersall").change(function(){
		if ($('#edit-newslettersall').attr('checked')) {
			$("#edit-newsletters-specialoffers").attr('checked', true);
			$("#edit-newsletters-harperauctions").attr('checked', true);
			$("#edit-newsletters-traveloffice").attr('checked', true);
			$("#edit-newsletters-porthos").attr('checked', true);
			$("#edit-newsletters-fromtheeditor").attr('checked', true);
		}
	});	
	
	$("#edit-newsletters-specialoffers").change(function(){
		if(!$("#edit-newsletters-specialoffers").attr('checked')) {
			$("#edit-newslettersall").attr('checked', false);
		}
	});
	
	$("#edit-newsletters-harperauctions").change(function(){
		if(!$("#edit-newsletters-harperauctions").attr('checked')) {
			$("#edit-newslettersall").attr('checked',false);
		}
	});
	
	$("#edit-newsletters-traveloffice").change(function(){
		if(!$("#edit-newsletters-traveloffice").attr('checked')) {
			$("#edit-newslettersall").attr('checked',false);
		}
	});
	
	$("#edit-newsletters-porthos").change(function(){
		if(!$("#edit-newsletters-porthos:checked").attr('checked')) {
			$("#edit-newslettersall").attr('checked',false);
		}
	});
	
	$("#edit-newsletters-fromtheeditor").change(function(){	
		if(!$("#edit-newsletters-fromtheeditor").attr('checked')) {
			$("#edit-newslettersall").attr('checked',false);
		}
	});	
	
	$('#subscription-get-form-registration').submit(function() {
		return validate_form();
	});	
});

function validate_username(testavailability){
	var result = true;
	$("#edit-username").removeClass('element-error'); 	
	if($("#edit-username").val() <= 0){
		//User name is empty, show "required" error
		$("#username_required").removeClass("error-hidden").addClass("error-visible");	
		$("#edit-username").addClass('element-error'); 	
		result = false;
	}
	else{
		//User name is not empty, hide any previously displayed user name errors
		$("#username_required").removeClass("error-visible").addClass("error-hidden");
		$("#username_available").removeClass('error-visible').addClass('error-hidden');		
		if(testavailability){
			//Check user name, show "Checking..." status
			$("#username_checking_availability_status").removeClass("error-hidden").addClass("error-visible");		
			$.getJSON('/subscribe/isavailablenameemail/' + $("#edit-username").val(), function(data) {
				$.each(data, function(key, val) {
					if(val){
						//User name is not being used, hide "unavailable" error
						$("#username_available").removeClass('error-visible').addClass('error-hidden');
					} 
					else{
						//User name is being used, show "unavailable" error
						$("#username_available").removeClass('error-hidden').addClass('error-visible');	
						$("#edit-username").addClass('element-error'); 	
						result = false;
					}
					//Done checking user name, hide "Checking..." status
					$("#username_checking_availability_status").addClass('error-hidden').removeClass('error-visible');
				});
			});	
		}		
	}
	return result;
}

function validate_screenname(testavailability){
	result = true;
	$("#edit-screenname").removeClass('element-error'); 	
	if($("#edit-screenname").val() <= 0){
		//screen name is empty, show "required" error
		$("#screenname_required").removeClass("error-hidden").addClass("error-visible");	
		$("#edit-screenname").addClass('element-error'); 			
		result = false;
	}
	else{
		//screen name is not empty, hide any previously displayed screen name errors
		$("#screenname_required").removeClass("error-visible").addClass("error-hidden");
		$("#screenname_available").removeClass('error-visible').addClass('error-hidden');
		
		if(testavailability){			
			//Check screen name, show "Checking..." status	
			$("#screenname_checking_availability_status").removeClass("error-hidden").addClass("error-visible");						
			$.getJSON('/subscribe/isavailablenameemail/' + $("#edit-screenname").val(), function(data) {
				$.each(data, function(key, val) {
					if(val){
						//screen name is not being used, hide "unavailable" error
						$("#screenname_available").removeClass('error-visible').addClass('error-hidden');
					} 
					else{
						//screen name is being used, show "unavailable" error
						$("#screenname_available").removeClass('error-hidden').addClass('error-visible');	
						$("#edit-screenname").addClass('element-error'); 	
						result = false;
					}
					//Done checking screen name, hide "Checking..." status
					$("#screenname_checking_availability_status").addClass('error-hidden').removeClass('error-visible');
				});
			});	
		}
	}
	return result;
}

function validate_password(){	
	result = true;					
	$("#edit-password").removeClass('element-error'); 			
	if($("#edit-password").val().length <= 0){
		//password is empty, show "Required" error
		$("#password_required").removeClass('error-hidden').addClass('error-visible');	
		$("#edit-password").addClass('element-error'); 			
		result = false;
	}
	else{
		//password is not empty, hide "Required" error
		$("#password_required").removeClass('error-visible').addClass('error-hidden');
		if($("#edit-password").val().length < 7){
			//password is too short, show "Min length" error
			$("#password_length").removeClass('error-hidden').addClass('error-visible');	
			$("#edit-password").addClass('element-error'); 			
			result = false;
		}	
		else{
			//password is fine, hide "Min length" error
			$("#password_length").removeClass('error-visible').addClass('error-hidden');
		}
	}	
	return result;
}

function validate_confirmpassword(){	
	result = true;
	$("#edit-confirmpassword").removeClass('element-error'); 
	if($("#edit-confirmpassword").val().length <= 0){
		//confirm password is empty, show "Required" error
		$("#confirmpassword_required").removeClass('error-hidden').addClass('error-visible');	
		$("#edit-confirmpassword").addClass('element-error'); 
		result = false;
	}
	else{
		//confirm password is not empty, hide "Required" error
		$("#confirmpassword_required").removeClass('error-visible').addClass('error-hidden');
		if($("#edit-confirmpassword").val() != $("#edit-password").val()){
			//confirm password does not match password, show "mismatch" error
			$("#password_mismatch").removeClass('error-hidden').addClass('error-visible');	
			$("#edit-confirmpassword").addClass('element-error'); 
			result = false;
		}	
		else{
			//confirm password matches password, hide "mismatch" error
			$("#password_mismatch").removeClass('error-visible').addClass('error-hidden');
		}
	}
	return result;
}

function validate_form(){
	var v1 = validate_username(false);
	var v2 = validate_password();
	var v3 = validate_confirmpassword();
	var v4 = validate_screenname(false);
	if(v1 && v2	&& v3 && v4){
		return true;
	}
	else{
		return false;
	}
}