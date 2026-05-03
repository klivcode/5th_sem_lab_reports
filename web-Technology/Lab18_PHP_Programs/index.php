<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Lab 18 - PHP Programs</title>
    <style>body { font-family: Arial; padding: 20px; line-height: 1.6; } .box { border: 1px solid #ccc; padding: 15px; margin-bottom: 20px; }</style>
</head>
<body>

    <div class="box">
        <h2>1. Sum of Digits</h2>
        <?php
        $number = 12345;
        $temp = $number;
        $sum = 0;
        while ($temp > 0) {
            $rem = $temp % 10;
            $sum += $rem;
            $temp = (int)($temp / 10);
        }
        echo "<p>The sum of digits of $number is: <strong>$sum</strong></p>";
        ?>
    </div>

    <div class="box">
        <h2>2. Palindrome Check</h2>
        <?php
        $orig_str = "radar";
        $rev_str = strrev($orig_str);
        if ($orig_str === $rev_str) {
            echo "<p>The string '$orig_str' is a <strong>Palindrome</strong>.</p>";
        } else {
            echo "<p>The string '$orig_str' is <strong>Not a Palindrome</strong>.</p>";
        }
        ?>
    </div>

    <div class="box">
        <h2>3. Date, Time & Delay</h2>
        <?php
        // Set timezone
        date_default_timezone_set("Asia/Kathmandu");
        
        echo "<p>Current Date: " . date("Y-m-d") . "</p>";
        echo "<p>Current Time before sleep: " . date("H:i:s") . "</p>";
        
        echo "<p><em>Sleeping for 2 seconds...</em></p>";
        flush(); // Try to push output to browser before sleep
        sleep(2);
        
        echo "<p>Current Time after sleep: " . date("H:i:s") . "</p>";
        ?>
    </div>

</body>
</html>