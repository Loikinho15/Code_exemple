<?php
	$tableau = array(array 	('nom' => 'Carotte',
							'couleur' => 'Orange',
							'Energie [Kcal/100g]' => 40),
						array	('nom' => 'Courge',
								'couleur' => 'Orange',
								'Energie [Kcal/100g]' => 45),
								
						array	('nom' => 'Navets',
								'couleur' => 'Blanc',
								'Energie [Kcal/100g]' => 37),
								
						array 	('nom' => 'Poireaux',
								'couleur' => 'Vert',
								'Energie [Kcal/100g]' => 39)
					);
					
	function Mafonction($tableau){
		echo'<table border="1">';
			echo'<tr><td><b>Nom</b></td> <td><b>Couleur</b></td> <td><b>Energie [Kcal/100g]</b></td></tr>';
			//Affichage du tableau
			foreach($tableau as $value){
				echo"<tr>";
				//Affichage du contenu du tableau (chaque cellule)
				foreach($value as $valTableau){
					echo"<td>$valTableau</td>";
				}
				echo "</tr>";
			} 
	}
	
	Mafonction($tableau);

?>