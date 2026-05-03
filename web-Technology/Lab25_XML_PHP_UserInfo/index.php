<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Lab 25 - PHP XML parsing</title>
</head>
<body>
    <h2>User Information Lookup</h2>
    <form method="GET">
        Enter User ID (1-10): <input type="number" name="uid" min="1" max="10" required>
        <button type="submit">Search</button>
    </form>
    <hr>
    <?php
if (isset($_GET['uid'])) {
    $search_id = $_GET['uid'];

    $doc = new DOMDocument();
    $doc->load("users.xml");

    $users = $doc->getElementsByTagName("user");

    $found = false;

    foreach ($users as $user) {
        $id = $user->getAttribute("id");

        if ($id == $search_id) {
            $name = $user->getElementsByTagName("name")[0]->nodeValue;
            $email = $user->getElementsByTagName("email")[0]->nodeValue;
            $role = $user->getElementsByTagName("role")[0]->nodeValue;

            echo "<h3>User Details:</h3>";
            echo "<strong>Name:</strong> $name <br>";
            echo "<strong>Email:</strong> $email <br>";
            echo "<strong>Role:</strong> $role <br>";

            $found = true;
            break;
        }
    }

    if (!$found) {
        echo "<p style='color:red;'>User ID $search_id not found!</p>";
    }
}
?>
</body>
</html>