<!DOCTYPE html>
<html>
	<head>
    	<meta charset="utf-8">
    	<title>Titre de ma page</title>
      </head>
  	<body>
  		<?php
		echo '<pre>';
		print_r($_POST);
		echo '</pre>';
		?>
		<h2>Résumé de votre commande</h2>
		<table border='1'>
			<thead>
				<tr>
					<th>Intitulé</th>
					<th>Prix</th>
					<th>Quantité voulue</th>
					<th>Sous-total
				</tr>
			</thead>

			<?php
			require_once('produits.php');
			
				foreach($tableau as $product){
					$qteVoulue = !empty($_POST[$product['textbox']])?$_POST[$product['textbox']]:0;
					$prix = $product['Prix'];
					if($qteVoulue != 0){
					echo'<tr><td>' .$product['Intitulé']. '</td><td>' .$prix. '</td><td>' .$qteVoulue. '</td><td>' .$qteVoulue*$prix. '</td></tr>';
					}
				}
			?>

		</table>
	</body>
</html>