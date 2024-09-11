document.getElementById('legalForm').addEventListener('submit', function(event){
    event.preventDefault(); // Prevent form from submitting
    var court = document.getElementById('court').value;
    var lawyer = document.getElementById('lawyer').value;
    console.log('Court selected:', court);
    console.log('Lawyer selected:', lawyer);
    // Implement further logic here
});
