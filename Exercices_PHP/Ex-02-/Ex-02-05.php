<table border ="1">
	<tr><td>indice</td> <td>valeur </td></tr>
	<?php
	$jour1 = ["Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"];
	
		for ($i = 0; $i < count($jour1); $i++) {
			echo "<tr> <td>$i</td> <td>$jour1[$i] </td></tr>";
		}
	
	?>
	</table>