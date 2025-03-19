//création de la classe qui représente les carré de notre jeu
class carrejeu {
	//initialisation des objets element et couleur
	constructor(element, couleur) {
		this.element = element;
		//ajout de l'évènement quand l'utilisateur clique sur un carré
		//click = au type / this = à l'objet qui reçevra la notification d'évènement --> element / option on en veut pas 
		this.element.addEventListener("click", this, false);
		
		this.isfacevisible = false;
		this.isMatched = false;
		this.setColor(couleur);
	}
	//Ajout d'une méthode pour l'élément lors du clique /!\ obligé de l'appeler handleEvent à cause de addEventListener au dessus /!\/
	handleEvent(event){
			switch (event.type) {
				case "click":
				
				//condition pour retourner les case --> switch entre flipped ou non
				if (this.isfacevisible || this.isMatched) {
					
					return
				}
				this.isfacevisible = true;
				this.element.classList.add('flipped');

				
				carreRetourne(this);
			}
			
		}
		
		reset() {
				this.isfacevisible = false;
				this.isMatched = false;
				this.element.classList.remove('flipped');
			}
			
			paireTrouve(){
				this.isfacevisible = true;
				this.isMatched = true;
			}
			
	//création d'une fonction pour set les couleurs
	setColor(couleur) {
		//on accède au div qui contient la classe facevisible de carre-jeu
		const faceVisibleElement = this.element.getElementsByClassName('facecacher')[0];
		//on efface la couleur d'avant si il y en a une
		faceVisibleElement.classList.remove(this.couleur);
		//set l'objet de la classe CarreJeu avec la couleur 
		this.couleur = couleur;
		//ajoute la classe du css facevisible pour set la couleur face visible du container carre-jeu
		faceVisibleElement.classList.add(couleur);
	}
	
}

//Création de la fonction qui va nous permettre de générer 16 carrés
function genereCarreHTML() {

	const nbCarre = 16;
	var carreHTML = '';

	// Génère l'HTML 16x pour faire les carrés
	for (var i = 0; i < nbCarre ; i++) {
		carreHTML += '<div class="col-3 carrejeu"><div class="face-container"><div class="facevisible"></div><div class="facecacher"></div></div></div>';
	}
	// Insert l'HTML 
	const boardElement = document.getElementById('plateau');
	boardElement.innerHTML = carreHTML;
}

//génération random des couleurs
//initialistation d'un tableau
const pairesCouleurs = [];

//création de la fonction pour générer les couleurs aléatoirement
function generePairsCouleurs() {
	//test de la taille du tableau
	if(pairesCouleurs.length > 0) {
		return pairesCouleurs;
	} 
	else {
		//On génère les paires de couleurs qui se correspondent
		for (let i = 0; i < 8; i++) {
			/* en modifiant la longueur du tableau à chaque passage on va avoir --> 1,1 / 2,2 etc... 
			ces numéros correspondent au classe css et c'est pour ça qu'il ffaut deux .push*/
			pairesCouleurs.push('color-' + i);
			pairesCouleurs.push('color-' + i);
		}
		return pairesCouleurs;	
	}
}

//fonction qui va nous retourner un string d'une couleur mélangée
function couleurMelanger(){
	const pairesCouleurs = generePairsCouleurs()
	return shuffle(pairesCouleurs);
}

// création d'une fonction pour mélanger nos couleurs en passant notre tableau par la suite comme arguments
// Cette fonction reprend l'algorithm de Fisher-Yates
function shuffle(array){
	let indexActuel = array.length;
	let valeurTemporaire, randomIndex;

	//tant qu'il y a des éléments à mélanger
	while (0 !== indexActuel){
		//choisir un élément qui reste
		randomIndex = Math.floor(Math.random() * indexActuel);
		//on décrémente l'index actuel de 1
		indexActuel -= 1;
		
		//et on change l'élément qui reste avec l'élément actuel
		valeurTemporaire = array[indexActuel];
		array[indexActuel] = array[randomIndex];
		array[randomIndex] = valeurTemporaire;
	}
	return array;
}

const CarresJeu = [];

//sans ça le jeu ne fonctionne pas
function setupGame(){
	genereCarreHTML();
	
	
	const randomPairesCouleurs = couleurMelanger();
	// Nous servira pour créer chaque objet de notre html carre-jeu avec la classse carre-jeu"
	const elementCarre = document.getElementsByClassName("carrejeu");
	//boucle qui traverse tous les elements contant la classe carrejeu 
	//pour créer à chaque fois son objet CarreJeu juste au dessus
	for( let i = 0; i < elementCarre.length; i++){
		const element = elementCarre[i];
		const couleur = randomPairesCouleurs[i];
		
		const carre = new carrejeu(element, couleur);
		
		CarresJeu.push(carre);
	}
}

setupGame();

//initialisation d'une variable qui va contenir une valeur en référence si le carré est le premier retourné ou pas
let premierRetourne = null;

//si le carré qu'on retourne est le premier alors on indique que c'est le premier et on recommence la fonction
function carreRetourne(carre) {
	if (premierRetourne === null){
		premierRetourne = carre;
		return
	}
	//si le carre qu'on retourne c'est le deuxième alors en test si ils correspondent
	if(premierRetourne.couleur === carre.couleur){
		premierRetourne.paireTrouve();
		carre.paireTrouve();
		
		premierRetourne = null;
	}
	//si non on retourne les deux carrés
	else {
		const a = premierRetourne;
		const b = carre;
		
		premierRetourne = null;
		
		setTimeout(function() {
			a.reset();
			b.reset();
		}, 400);
	}
}

const resetButton = document.getElementById("reset-button");

resetButton.addEventListener("click", () => {
	resetJeu();
});

//fonction pour retourner toutes les cases
function resetJeu() {
	//on remet la valeur du premier carré qui est retourné à null
	premierRetourne = null;
	
	// on utilise la méthode reset de carrejeu pour remettre les valeurs isMatched et isfacevisible à false
	CarresJeu.forEach((carre) => {
		carre.reset()
	});
	
	//on utilise cet fonction pour ne pas interrompre l'animation des carrés qui se retourne
	setTimeout(() => {
		//on refait un random des couleurs
		const randomPairesCouleurs = couleurMelanger();
		//on repasse les valeurs des couleurs qui viennent d'être mélangées
		for(let i = 0; i < CarresJeu.length; i++) {
			const newCouleur = randomPairesCouleurs[i];
			const carre = CarresJeu[i];
			
			carre.setColor(newCouleur);
		}
	}, 500);
}