<!-- a -->

<?php
	$student = array("first_name" => "John",
					"last_name" => "sixpack",
					"age" => 27,
					"height" => 1.62);
?>

<!-- b -->

<?php
	$student = array("first_name" => "John",
					"last_name" => "sixpack",
					"age" => 27,
					"hieght" => 1.62);
					
	foreach($student as $key => $value){
		echo "$key : $value <br>";
	}
?>
<br><br>

<!-- c -->

<table border="1">
<tr><td><b>Indice</b></td><td><b>Valeur</b></td></tr>
<?php
	$student = array("first_name" => "John",
					"last_name" => "sixpack",
					"age" => 27,
					"height" => 1.62);
					
	foreach($student as $key => $value) {
		echo "<tr><td>$key</td> <td>$value</td></tr>";
	}
?>

