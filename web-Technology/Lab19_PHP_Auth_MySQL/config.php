<?php
$host = "localhost";
$user = "root";
$pass = "root"; // Default XAMPP password
$db = "webl";

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) {
    die("Database connection failed: " . $conn->connect_error);
}
?>