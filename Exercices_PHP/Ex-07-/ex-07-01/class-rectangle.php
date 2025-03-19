<?php
	class Rectangle{
		// on instantie les valeurs qu'on a besoin
		protected $largeur = null;
		protected $longueur = null;

		//on crée notre constructeur
		function __construct($largeur, $longueur){
			$this->SetLargeur($largeur);
			$this->SetLongueur($longueur);
		}

		//on crée les GETTER et SETTER
		function SetLargeur($Largeur){
			$this->largeur = $Largeur;
		}

		function GetLargeur(){
			return $this->largeur;
		}

		function SetLongueur($Longueur){
			$this->longueur = $Longueur;
		}

		function GetLongueur(){
			return $this->longueur;
		}

		//on crée la fonction qui va nous donner la surface
		function surface(){
			return $this->largeur*$this->longueur;
		}

		function echoHtmlTableLine() {
        echo "<tr> <td>$this->largeur</td> <td>$this->longueur</td> <td>".$this->surface()."</td> </tr>";
    }
	}
?>