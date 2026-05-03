function showCapital() {
    // Get the selected value from the dropdown
    const select = document.getElementById('countrySelect');
    const capital = select.value;
    
    // Display the value in the span
    const displaySpan = document.getElementById('capitalDisplay');
    
    if (capital) {
        displaySpan.innerText = capital;
    } else {
        displaySpan.innerText = "";
    }
}