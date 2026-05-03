// On page load, apply saved theme
window.onload = function() {
    const savedTheme = localStorage.getItem("userTheme");
    if (savedTheme) {
        document.body.className = savedTheme;
    }
};

function setTheme(themeName) {
    // Apply theme to body
    document.body.className = themeName;
    
    // Save to localStorage
    localStorage.setItem("userTheme", themeName);
}

function resetTheme() {
    // Remove from localStorage
    localStorage.removeItem("userTheme");
    
    // Fallback to default
    document.body.className = "light-theme";
    alert("Preference cleared!");
}