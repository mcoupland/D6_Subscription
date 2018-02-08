
$(document).ready(function() {		
	$('#subscription-get-form-summary').submit(function() {
		if ($("#edit-agreetoterms").attr('checked')){
			return true;
		}
		else{
			$("#agreetoterms_required").removeClass("error-hidden").addClass("error-visible");
			return false;
		}
	});
});
