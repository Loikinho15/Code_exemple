<?php
	session_start();

	if(isset($_POST["btnConnexion"])){
		$password = $_POST["txtMdp"];
		
		if($password == "toto"){
			$_SESSION['connected'] = 'true';
			header('Location: zoneprivee.php');
		}
		else{
			echo'<html>
				<header>
				</header>
					<body>
						<h1> LOGIN </h1>
						<form name="formLogin" action="login.php" method="post">
						<div>
							<label for="mdp">Mot de passe</label>
							<input type="text" name="txtMdp" id="mdp" value="">
						</div>
						<div>
							<input type="submit" name="btnConnexion" id="btn" value="Connexion">
						</div>
					</body>
			</html>';
		echo"Le mot de passe est incorrecte !";
		}
		if(isset($_SESSION['connected'])){
			header('Location: zoneprivee.php');
		}
	}
	else{
		echo"Vous n'avez pas le droit d'être ici<br>";
		echo"Veuillez vous connecter !";
		echo"-->";
		echo '<a href="http://localhost/exercice/login.html"> LOGIN </a>';
	}
	
?>