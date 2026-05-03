<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Lab 17 - PHP Basics</title>
    <style>
        body { font-family: Arial; padding: 20px; }
        .game, .table-box { margin-bottom: 40px; padding: 15px; border: 1px solid #ccc; background: #fafafa;}
        table { border-collapse: collapse; }
        td, th { border: 1px solid #333; padding: 5px 10px; }
    </style>
</head>
<body>

    <div class="table-box">
        <h2>1. Multiplication Table using PHP Loop</h2>
        <table>
            <?php
            $num = 5; // Static number for example
            echo "<tr><th colspan='2'>Table for $num</th></tr>";
            for ($i = 1; $i <= 10; $i++) {
                $result = $num * $i;
                echo "<tr><td>$num x $i</td><td>$result</td></tr>";
            }
            ?>
        </table>
    </div>

    <div class="game">
        <h2>2. Rock-Paper-Scissors Game</h2>
        <p>Choose your move:</p>
        <a href="index.php?choice=rock">Rock</a> | 
        <a href="index.php?choice=paper">Paper</a> | 
        <a href="index.php?choice=scissors">Scissors</a>
        <br><br>

        <?php
        if (isset($_GET['choice'])) {
            $user_choice = $_GET['choice'];
            $options = ['rock', 'paper', 'scissors'];
            
            // Validate input
            if(in_array($user_choice, $options)){
                // Computer random choice
                $comp_choice = $options[rand(0, 2)];
                
                echo "<strong>You chose:</strong> $user_choice <br>";
                echo "<strong>Computer chose:</strong> $comp_choice <br><br>";
                
                // Logic
                if ($user_choice == $comp_choice) {
                    echo "<span style='color:blue'>Result: It's a Tie!</span>";
                } elseif (
                    ($user_choice == 'rock' && $comp_choice == 'scissors') ||
                    ($user_choice == 'paper' && $comp_choice == 'rock') ||
                    ($user_choice == 'scissors' && $comp_choice == 'paper')
                ) {
                    echo "<span style='color:green'>Result: You Win!</span>";
                } else {
                    echo "<span style='color:red'>Result: Computer Wins!</span>";
                }
            }
        }
        ?>
    </div>

</body>
</html>