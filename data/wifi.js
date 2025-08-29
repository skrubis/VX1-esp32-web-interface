var wifi = {

	wifiValidatePasswordLength: function(pw)
	{
		document.getElementById("apsubmit").disabled = pw.length < 8;
	},

	populateWiFiTab: function()
	{
		var wifiTab = document.getElementById("wifi");
		var wifiFetchRequest = new XMLHttpRequest();
		wifiFetchRequest.onload = function()
		{
			wifiTab.innerHTML = this.responseText;
		}
		wifiFetchRequest.open("GET", "/wifi");
		wifiFetchRequest.send();
	},

	wifiClientForm: function(formId)
	{
		var form = document.getElementById(formId);
		var formData = new FormData(form);
		
		// Handle checkbox for wifiEnabled
		if (!document.getElementById("wifiEnabled").checked) {
			formData.set("wifiEnabled", "false");
		}
		
		var xhr = new XMLHttpRequest();
		xhr.onload = function() {
			if (xhr.status === 200) {
				alert("WiFi settings updated successfully!");
				wifi.populateWiFiTab(); // Refresh the tab
			} else {
				alert("Error updating WiFi settings");
			}
		};
		xhr.open("POST", "/wifi");
		xhr.send(formData);
	}

}