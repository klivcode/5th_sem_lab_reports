<?php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit();
}

$bg_color = "white"; // default
if (isset($_COOKIE['bg_color'])) {
    $bg_color = $_COOKIE['bg_color'];
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Dashboard</title>
    <style>body { background-color: <?php echo $bg_color; ?>; font-family: Arial; padding: 20px;}</style>
</head>
<body>
    <h2>Welcome to your Dashboard, <?php echo $_SESSION['username']; ?>!</h2>
    <p>Notice the background color? It was retrieved from your Cookie!</p>
    <p>Your username is stored safely in a Session.</p>
    
    <a href="logout.php"><button>Logout</button></a>
</body>
</html>