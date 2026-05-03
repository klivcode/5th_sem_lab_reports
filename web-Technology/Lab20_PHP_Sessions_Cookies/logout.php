<?php
session_start();

// Destroy session
session_destroy();

// Delete cookie by setting expiry time to the past
setcookie("bg_color", "", time() - 3600, "/");

header("Location: login.php");
exit();
?>