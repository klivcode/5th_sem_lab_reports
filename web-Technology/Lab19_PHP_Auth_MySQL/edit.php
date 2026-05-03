<?php
session_start();
require 'config.php';

if (!isset($_SESSION['user_id'])) { header("Location: login.php"); exit(); }

if(!isset($_GET['id'])) { header("Location: dashboard.php"); exit(); }
$id = (int)$_GET['id'];

if($_SERVER['REQUEST_METHOD'] == 'POST') {
    $email = $conn->real_escape_string($_POST['email']);
    $conn->query("UPDATE users SET email='$email' WHERE id=$id");
    header("Location: dashboard.php");
    exit();
}

$res = $conn->query("SELECT * FROM users WHERE id=$id");
$user = $res->fetch_assoc();
?>
<!DOCTYPE html>
<html><body>
    <h2>Edit User: <?php echo $user['username']; ?></h2>
    <form method="POST">
        Email: <input type="text" name="email" value="<?php echo $user['email']; ?>"><br><br>
        <button type="submit">Update</button>
    </form>
    <br><a href="dashboard.php">Back to Dashboard</a>
</body></html>