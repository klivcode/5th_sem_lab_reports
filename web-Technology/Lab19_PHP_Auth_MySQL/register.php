<?php
require 'config.php';

if(isset($_POST['submit'])){

$username=$_POST['username'];
$email=$_POST['email'];
$password=$_POST['password'];

$sql="
INSERT INTO users
(username,email,password)
VALUES
('$username','$email','$password')
";

$conn->query($sql);

echo "User Created";
}
?>

<form method="post">
Username:
<input name="username"><br><br>

Email:
<input name="email"><br><br>

Password:
<input name="password"><br><br>

<button name="submit">
Register
</button>
</form>