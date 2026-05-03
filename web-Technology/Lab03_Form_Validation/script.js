function validateForm() {
    let isValid = true;
    
    // Get fields
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;
    const eduCheckboxes = document.querySelectorAll('input[name="edu"]:checked');
    
    // Reset errors
    document.getElementById('userError').style.display = 'none';
    document.getElementById('passError').style.display = 'none';
    document.getElementById('eduError').style.display = 'none';

    // 1. Username Validation (>= 4 characters)
    if (username.length < 4) {
        document.getElementById('userError').style.display = 'block';
        isValid = false;
    }

    // 2. Password Validation (start with digit, end with #)
    // Regex: ^[0-9].*#$ -> starts with a digit [0-9], any characters .*, ends with #
    const passRegex = /^[0-9].*#$/;
    if (!passRegex.test(password)) {
        document.getElementById('passError').style.display = 'block';
        isValid = false;
    }

    // 3. Checkbox validation
    if (eduCheckboxes.length === 0) {
        document.getElementById('eduError').style.display = 'block';
        isValid = false;
    }

    if (isValid) {
        alert("Form submitted successfully!");
    }

    return isValid; // Prevent form submission if validation fails
}