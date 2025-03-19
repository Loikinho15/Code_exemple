
<!-- a -->

<table border="1">
	<tr><td><b>Valeur</b></td></tr>
<?php
	$guy = array("Marc", "Müller", 21, 1.52);
	for($i = 0; $i < count($guy); $i++){
		echo "<tr><td>$guy[$i]</td></tr>";
	}
?>

<!-- b -->

<?php
	$guy = array("Marc", "Müller", 21, 1.52);
	list($first_name, $last_name, $age, $height) = $guy;
	echo "Prenom : $first_name <br> Nom : $last_name <br> Age : $age <br> Taille : $height";
?>

