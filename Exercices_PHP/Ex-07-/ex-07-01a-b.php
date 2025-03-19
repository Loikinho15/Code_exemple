	<!DOCTYPE html>
	<html>
		<head>
			<title>Formulaire</title>
			<meta name="keywords" content="formulaire,exercice,apprentissage">
			<meta name="description" content="Création d'un formulaire en HTML">
			<meta name="author" content="Loïc Damon">
			<meta charset="utf-8">
		</head>
		
		<body>
			<h1>Formulaire d'inscription</h1>
				<form name="formLogin" action="" method="post">
							<div class="champ">
								<label for="nom">Largeur</label>
								<input type="text" name="txtLargeur" id="nom" value="" required><br>
							</div>
							
							<div class="champ">
								<label for="nom">Longueur</label>
								<input type="text" name="txtLongueur" id="nom" value="" required><br>
							</div>
							
							<div>
								<input type="submit" name="btnEnvoyer" id="btn" value="envoyer">
							</div>
				</form>
		</body>
	</html>

	<?php
	class Rectangle{
		public $largeur = 0;
		public $longueur = 0;
		
		public function SetLargeur($Largeur){
			$this->largeur = $Largeur;
		}
		
		public function GetLargeur(){
			return $this->largeur;
		}
		
		public function SetLongueur($Longueur){
			$this->longueur = $Longueur;
		}
		
		public function GetLongueur(){
			return $this->longueur;
		}
		
		public function surface(){
			return $this->longueur * $this->largeur;
		}	
	}	
	$rectangleSurface = new Rectangle();
		
		if(isset($_POST['btnEnvoyer'])){
			if(isset($_POST['txtLargeur'])){
				$rectangleSurface ->SetLargeur($_POST['txtLargeur']);
				if(isset($_POST['txtLongueur'])){
					$rectangleSurface ->SetLongueur($_POST['txtLongueur']);
					echo"Un rectangle de ". $rectangleSurface->GetLargeur()." largeur , ". $rectangleSurface->GetLongueur()." longueur et de surface" . $rectangleSurface->surface();
				}
			}
		}
	?>
	