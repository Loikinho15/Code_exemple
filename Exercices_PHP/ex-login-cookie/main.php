<?php

	session_start();
	//on vérifie si le formulaire est envoyé
	if(isset($_POST['btnConnexion'])){
		//on récupère les valeurs envoyées
		$user = isset($_POST['txtUtilisateur'])?$_POST['txtUtilisateur']:0;
		$password = isset($_POST['txtmdp'])?$_POST['txtmdp']:0;
		$remember = !empty($_POST['chkNewsletter'])?'true':'false';
		//on vérifie si le nom d'utilisateur et le mdp sont bien ceux qu'il faut entrer et si il a cocher la case
		if(($user == 'toto') && ($password == 'toto') && ($remember == 'true')){
			//on démarre la session
			$_SESSION['toto'] = 'true';
			//on démarre le cookie
			setcookie('user','toto', time() +3600);
			//on redirige vers la page qu'il faut
			header('location:zoneprivee.php');
		}
		//si non si le nom d'utilisateur et le mdp sont correcte mais qu'il n'a pas coché la case
		elseif(($user == 'toto') && ($password == 'toto')){
			$_SESSION['toto'] = 'true';
			header("location: zoneprivee.php");
		}
		//si non c'est qu'il a mal rentré son nom ou mdp donc on affiche un message
		else{
			echo'Mauvais mot de passe !';
		}
	}
	//maintenant on crée la condition si le bouton n'est pas cliqué
	else{
		if(isset($_COOKIE['user'])){
			//on test si le cookie est actif ou non quand l'utilisateur arrive sur la page
			if($_COOKIE['user'] == 'toto'){
				//on initialise le cookie
				setcookie('user','toto',time() +3600);
				//on le redirige vers la page qu'il faut
				header('location:zoneprivee.php');
			}
		}
	}
?>

<html>
	<header>
		<meta charset="utf-8">
	</header>
		<body>
			<h1> LOGIN </h1>
			<form name="formLogin" action="" method="post">
				<div>
					<label for="utilisateur">Utilisateur</label>
					<input type="text" name="txtUtilisateur" id="utilisateur" value="">
				</div>
				<div>
					<label for="mdp">Mot de passe</label>
					<input type="password" name="txtMdp" id="mdp" value="">
				</div>
				<div>
					<label for="newletter">Rester connecté ?</label>
					<input type="checkbox" name="chkNewsletter" id="Newsletter" value="checked">
				</div>
				<div>
					<input type="submit" name="btnConnexion" id="btn" value="Connexion">
				</div>
		</body>
</html>	