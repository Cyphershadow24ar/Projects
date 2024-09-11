document.addEventListener("DOMContentLoaded", function() {
    document.getElementById("homeIcon").addEventListener("click", function() {
        alert("Navigating to Home...");
    });

    document.getElementById("chatbotIcon").addEventListener("click", function() {
        alert("Opening Chatbot Support...");
    });

    document.getElementById("notificationIcon").addEventListener("click", function() {
        alert("Checking Notifications...");
    });

    document.getElementById("menuIcon").addEventListener("click", function() {
        alert("Opening Menu...");
    });

    document.querySelector(".registered-cases").addEventListener("click", function() {
        alert("Showing Registered Cases...");
    });
});