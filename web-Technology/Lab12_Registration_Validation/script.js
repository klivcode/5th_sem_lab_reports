function validateForm() {
    let isValid = true;
    
    // Hide all errors initially
    document.querySelectorAll('.error').forEach(e => e.style.display = 'none');
    
    const fname = document.getElementById('fname').value;
    const pass = document.getElementById('pass').value;
    const email = document.getElementById('email').value;
    const phone = document.getElementById('phone').value;

    // 1. First Name: Alphabets only, min length 6
    const nameRegex = /^[A-Za-z]{6,}$/;
    if (!nameRegex.test(fname)) {
        document.getElementById('fnameErr').style.display = 'block';
        isValid = false;
    }

    // 2. Password: Minimum 6 characters
    if (pass.length < 6) {
        document.getElementById('passErr').style.display = 'block';
        isValid = false;
    }

    // 3. Email ID: Valid format
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailRegex.test(email)) {
        document.getElementById('emailErr').style.display = 'block';
        isValid = false;
    }

    // 4. Phone Number: Digits only
    const phoneRegex = /^\d+$/;
    if (!phoneRegex.test(phone) || phone === '') {
        document.getElementById('phoneErr').style.display = 'block';
        isValid = false;
    }

    if (isValid) {
        alert("Registration Successful!");
    }
    
    return isValid;
}\n