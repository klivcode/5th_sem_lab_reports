function drawNumbers() {
    // Get all td elements in the table
    const table = document.getElementById("numberTable");
    const cells = table.getElementsByTagName("td");
    
    // Iterate through all cells and replace content with random number
    for (let i = 0; i < cells.length; i++) {
        // Generate random number between 1 and 100
        let randomNum = Math.floor(Math.random() * 100) + 1;
        cells[i].innerText = randomNum;
        
        // Extra: change background color dynamically
        cells[i].style.backgroundColor = `hsl(${Math.random() * 360}, 70%, 80%)`;
    }
}