<?php
	session_start();
	echo"<h1>Zone privée</h1><br>";
	//si l'utilisateur arrive ici mais qu'il s'est ni connecté, ni a coché la case
	if(empty($_SESSION['toto']) && (empty($_COOKIE['user']))) {
		echo"Vous n'avez pas le droit d'être ici !";
		echo"-->";
		echo '<a href="http://localhost/exercice/main.php"> LOGIN </a>';
	}
	else{
		//on test si l'utilisateur a rentré son nom et son mdp et si il a coché la case
		if(isset($_SESSION['toto']) && isset($_COOKIE['user'])){
			echo'Vous êtes connecté en tant que ' . $_COOKIE['user'] .' <br> ';
			echo'<a href="http://localhost/exercice/logout.php">Se deconnecter</a>';
		}
		//si non il faut tester si il a rentrer son nom et son mdp mais pas coché la case
		if(isset($_SESSION['toto'])){
			if(empty($_COOKIE['user'])) {
				echo'Vous êtes connecté en tant que ' . $_SESSION['toto'] .' <br> ';
				echo'<a href="http://localhost/exercice/logout.php">Se deconnecter</a>';
			}
		}
		//si non c'est que c'est uniquement son cookie qui est actif 
		else{
				echo'Vous êtes connecté en tant que ' . $_COOKIE["user"] .' <br> ';
				echo'<a href="http://localhost/exercice/logout.php">Se deconnecter</a>';
		}
	}
?>