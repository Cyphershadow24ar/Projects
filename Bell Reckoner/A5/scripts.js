document.addEventListener("DOMContentLoaded", function() {
    const steps = Array.from(document.querySelectorAll('.progress-bar li'));
    const connectButton = document.querySelector('.action-button:first-child');
    const paymentButton = document.querySelector('.action-button:last-child');

    // Function to advance the process
    function advanceProcess(currentStep) {
        if (currentStep < steps.length) {
            steps[currentStep].classList.add('active');
            alert('Moving to: ' + steps[currentStep].textContent);
        }
    }

    // Connect with a lawyer
    connectButton.addEventListener('click', function() {
        advanceProcess(1); // Assume 'Apply' is 0 and 'Lawyer' is 1
    });

    // Handle payment action
    paymentButton.addEventListener('click', function() {
        advanceProcess(steps.length - 1); // Move to the final step
        alert('Initiating payment process...');
    });
});
