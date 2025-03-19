<?php
	//a 
	$jour1 = array("Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche");
	
	//b
	$jour2 = ["Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"];
	
	//c
	$nbrElement1 = count($jour1);
	$nbrElement2 = count($jour2);
	
	echo "$nbrElement1 <br><br><br>";
	echo "$nbrElement2 <br><br><br>";
	
	//d
	for($i = 0; $i < count($jour1); $i++){
		echo "Indice $i: $jour1[$i] <br>";
	}
	//Ou alors
	foreach ($jour1 AS $num => $valeur){
		
		echo "indice $num : $valeur <br>";
	}
	echo "<br><br><br>";
	
	//e
	$i = 0;
	$nbrJour = count($jour1);
	
	while($i < $nbrJour){
		echo "Indice $i: $jour1[$i] <br>";
		$i++;
	}
	?>
		
	<!-- f -->
	<table border ="1">
	<tr><td>indice</td> <td>valeur </td></tr>
	<?php
	$jour1 = ["Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"];
	
		for ($i = 0; $i < count($jour1); $i++) {
			echo "<tr> <td>$i</td> <td>$jour1[$i] </td></tr>";
		}
	
	?>
	</table>