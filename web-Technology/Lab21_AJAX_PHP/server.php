<?php
// Array with names
$a[] = "Anna"; $a[] = "Brittany"; $a[] = "Cinderella";
$a[] = "Diana"; $a[] = "Eva"; $a[] = "Fiona";
$a[] = "Gunda"; $a[] = "Hege"; $a[] = "Inga";
$a[] = "Johanna"; $a[] = "Kitty"; $a[] = "Linda";
$a[] = "Nina"; $a[] = "Ophelia"; $a[] = "Petunia";
$a[] = "Amanda"; $a[] = "Raquel"; $a[] = "Cindy";
$a[] = "Doris"; $a[] = "Eve"; $a[] = "Evita";

// get the q parameter from URL
$q = $_REQUEST["q"];
$hint = "";

if ($q !== "") {
    $q = strtolower($q);
    $len = strlen($q);
    foreach($a as $name) {
        // If match found
        if (stristr($q, substr($name, 0, $len))) {
            if ($hint === "") {
                $hint = $name;
            } else {
                $hint .= ", $name";
            }
        }
    }
}

// Output "no suggestion" if no hint was found or output correct values
echo $hint === "" ? "no suggestion" : $hint;
?>