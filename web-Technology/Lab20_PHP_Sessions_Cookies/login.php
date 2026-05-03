<?php
session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = htmlspecialchars($_POST['username']);
    $color = $_POST['color'];
    
    // Start session
    $_SESSION['username'] = $username;
    
    // Set cookie (name, value, expiry (1 hr), path)
    setcookie("bg_color", $color, time() + 3600, "/");
    
    header("Location: dashboard.php");
    exit();
}
?>
<!DOCTYPE html>
<html>
<head><title>Lab 20 - Login</title></head>
<body>
    <h2>Login Page (Sessions & Cookies Demo)</h2>
    <form method="POST">
        Username: <input type="text" name="username" required><br><br>
        Pref. Color: 
        <select name="color">
            <option value="lightblue">Light Blue</option>
            <option value="lightgreen">Light Green</option>
            <option value="pink">Pink</option>
        </select><br><br>
        <button type="submit">Login</button>
    </form>
</body>
</html>