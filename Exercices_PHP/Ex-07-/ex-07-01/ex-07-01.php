<?php
	//On démarre la session
	session_start();
	require_once('class-rectangle.php');

echo'
<html>
	<head>
	<meta charset="utf-8">
	</head>
		<body>
			<h1>Générateur de rectangle</h1>
			<form name="form_rectangle" method="post" action="">
				<table>
					<tr>
						<td>Largeur : <input type="text" name="tbxLargeur" ></td>
					</tr>
					<tr>
						<td>Longueur : <input type="text" name="tbxLongueur" ></td>
					</tr>
					<tr>
						<td><input type="submit" name="btnEnvoyer" value="Ajouter"></td>
					</tr>
				</table>
			</form>';	

	//on test si le formulaire est envoyer
	if(isset($_POST['btnEnvoyer'])){
		//si les valeurs sont bien passées
		if(!empty($_POST['tbxLargeur']) && ($_POST['tbxLongueur'])){
			//on crée le rectangle, on récupère les valeurs et on les ajoutes aux valeurs de notre class
			$myRectangle = new Rectangle($_POST['tbxLargeur'], $_POST['tbxLongueur']);

			//on passe en session les arguments pour les mettre dans un tableau
			$_SESSION['tabRectangle'][] = $myRectangle;
		}
		//si non on affiche un message pour que l'utilisateur rentre des valeurs
		else{
			echo'<font color="red">Merci de remplir tous les champs.</font><br>';
		}
	}

	//on gère le logout
		if(isset($_POST['form_reset'])){
			//on efface la session
			session_destroy();
			$_SESSION = array();
		}

	//On affiche les rectangle envoyer
		//en premier on test si la session est active
		if(isset($_SESSION['tabRectangle'])){
			//on affiche les rectangles dans un tableau
			echo'Liste des rectangles';
			echo'<table border="1">';
			echo'<tr><th>Largeur</th><th>Longueur</th><th>Surface</th></tr>';
			//en utiliser une boucle foreach pour récupérer chaque valeur et les mettres dans des variables
			foreach($_SESSION['tabRectangle'] as $valueRectangle){
				$largeur = $valueRectangle->GetLargeur();
				$longueur = $valueRectangle->GetLongueur();
				$surface = $valueRectangle->surface();
				//Et puis on affiche le résultat sous forme HTML
				echo'<tr><td>' .$largeur. '</td><td>' .$longueur. '</td><td>' .$surface. '</td></tr>';
			}
			echo'</table>';
			//on gère le bouton pour tout enlever
			echo'<form name="logout_form" method="post" action="post">
				<input type="hidden" name="form_reset">
				<input type="submit" name="btnReset" value="Réinitialiser">
			</form>';
		}
	echo'</body>
	</html>';
?>



