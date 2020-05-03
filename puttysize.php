<?php
$row =  $_POST['row'];
$col = $_POST['col'];
&maxdb = $_POST['maxdb'];
&peaks = $_POST['peaks'];
$today = date("Y-m-d H;i;s");
$record = $today . "," . $row . " " . $col ."".$peaks . "" . $maxdb . "\n";

$file = "putty.txt";
if(file_exists($file))
	$fp = fopen($file, "a");
else
	$fp =fopen($file, "w");

fwrite($fp, $record);
fclose($fp);
echo "From Hoang Hieu-e1900314\n"
?>
