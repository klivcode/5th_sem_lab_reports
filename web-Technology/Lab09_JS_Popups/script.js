// 1. Display Current Date
function displayDate() {
    const today = new Date();
    document.getElementById("dateInput").value = today.toDateString();
}

// 2. Factorial of a number
function calcFactorial() {
    let input = prompt("Enter a positive number:");
    if (input === null || input === "") return;
    
    let num = parseInt(input);
    if (isNaN(num) || num < 0) {
        alert("Please enter a valid positive integer.");
        return;
    }
    
    let fact = 1;
    for (let i = 1; i <= num; i++) {
        fact *= i;
    }
    alert("The factorial of " + num + " is: " + fact);
}

// 3. Multiplication table
function showMultiplicationTable() {
    let input = prompt("Enter a number for the multiplication table:");
    if (input === null || input === "") return;
    
    let num = parseInt(input);
    if (isNaN(num)) {
        alert("Please enter a valid number.");
        return;
    }
    
    let result = "Multiplication Table for " + num + ":\n";
    for (let i = 1; i <= 10; i++) {
        result += num + " x " + i + " = " + (num * i) + "\n";
    }
    
    // Display using alert as requested (or could be written to DOM)
    alert(result);
}\n