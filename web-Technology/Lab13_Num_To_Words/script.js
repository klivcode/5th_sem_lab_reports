const ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"];
const tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"];

function convertToWords(n) {
    if (n === 0) return "Zero";
    let words = "";
    
    if (n >= 100) {
        words += ones[Math.floor(n / 100)] + " Hundred ";
        n %= 100;
    }
    
    if (n > 0) {
        if (n < 20) {
            words += ones[n];
        } else {
            words += tens[Math.floor(n / 10)];
            if (n % 10 > 0) {
                words += " " + ones[n % 10];
            }
        }
    }
    return words.trim();
}

function convert() {
    const input = document.getElementById("numInput").value.trim();
    const resultDiv = document.getElementById("result");
    
    // Validation
    if (input === "") {
        resultDiv.innerHTML = "<span class='error'>Please enter a value.</span>";
        return;
    }
    
    if (!/^\d+$/.test(input)) {
        resultDiv.innerHTML = "<span class='error'>Invalid input. No alphabets or special characters allowed.</span>";
        return;
    }
    
    const num = parseInt(input, 10);
    
    if (num >= 1000) {
        resultDiv.innerHTML = "<span class='error'>Number too large! Enter between 0 and 999.</span>";
        return;
    }
    
    // Conversion
    const words = convertToWords(num);
    resultDiv.innerHTML = words;
}\n