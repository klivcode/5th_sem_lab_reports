<?php
session_start();
require 'config.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit();
}

// Handle Delete
if(isset($_GET['delete'])) {
    $del_id = (int)$_GET['delete'];
    $conn->query("DELETE FROM users WHERE id=$del_id");
}

?>
<!DOCTYPE html>
<html><body>
    <h2>Welcome, <?php echo $_SESSION['username']; ?>!</h2>
    <a href="logout.php">Logout</a> | <a href="edit.php?id=<?php echo $_SESSION['user_id']; ?>">Edit My Info</a>
    <hr>
    
    <h3>All Users (CRUD Display)</h3>
    <table border="1" cellpadding="5">
        <tr><th>ID</th><th>Username</th><th>Email</th><th>Action</th></tr>
        <?php
        $res = $conn->query("SELECT * FROM users");
        while($row = $res->fetch_assoc()) {
            echo "<tr>";
            echo "<td>".$row['id']."</td>";
            echo "<td>".$row['username']."</td>";
            echo "<td>".$row['email']."</td>";
            echo "<td><a href='edit.php?id=".$row['id']."'>Edit</a> | <a href='?delete=".$row['id']."'>Delete</a></td>";
            echo "</tr>";
        }
        ?>
    </table>
</body></html>