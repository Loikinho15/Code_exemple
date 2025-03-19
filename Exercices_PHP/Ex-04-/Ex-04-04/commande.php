<!DOCTYPE html>
<html>
	<head>
    	<meta charset="utf-8">
    	<title>Titre de ma page</title>
      </head>
  	<body>
		<h2>Votre formulaire de commande</h2>
		<form name="pass_form" action="recap.php" method="post">
			<table border='1'>
			<thead>
				<tr>
					<th>Intitulé</th>
					<th>Prix</th>
					<th>Quantité voulue</th>
				</tr>
			</thead>

			<?php
			require_once('produits.php');

				foreach($tableau as $product){
					echo'<tr><td>' .$product['Intitulé']. '</td><td>' .$product['Prix']. '</td><td> <input type="text" name="'.$product['textbox'].'"</td></tr>';
				}
			?>

			</td><td colspan="2"><input type="reset" value="Rétablir">&nbsp;<input type="submit" value="Commander"/></td></tr>
	  	</table>
    	</form>
      
    </body>
</html>