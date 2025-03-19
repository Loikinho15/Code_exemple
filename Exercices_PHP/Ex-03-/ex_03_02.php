<html>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<head>
</head>
<body>
<?php
	//on vérifie si la valeur arbre est passée
	$nb_arbre = array_key_exists('arbre', $_GET)?$_GET['arbre']:0;
	$arbre_pluriel = ($nb_arbre <= 1)?'arbre':'arbres';
	echo'Une forêt avec ' .$nb_arbre. ' ' .$arbre_pluriel. '<br>';

	//on vérifie si la valeur branche est passée
	$nb_branche = array_key_exists('branche', $_GET)?$_GET['branche']:0;
	$branche_pluriel = ($nb_branche <= 1)? 'branche':'branches';
	echo'Une forêt avec ' .$nb_branche. ' ' .$branche_pluriel. '<br>';

	//On calcule le nombre de branche totale
	$branche_total = $nb_arbre*$nb_branche;
	$branche_total_pluriel = ($branche_total <= 1?'branche':'branches');
	echo'et dans la forêt il y a ' .$branche_total. ' ' .$branche_total_pluriel. '<br>';

	//pour incrémenter le nombre d'arbre
	$arbre_plus = array(
					'arbre' => $nb_arbre + 1,
					'branche' => $nb_branche);
	//on construit une url à partir des valeurs de notre tableau
	$url_arbre_plus = http_build_query($arbre_plus);
	//on affiche le lien pour augmenter le nombre d'arbre au clique
	echo'<a href=http://localhost/exercice/foret.php?' .$url_arbre_plus. '>Ajouter un arbre</a><br>';

	//pour incrémenter les branches
	$branche_plus = array(
						'arbre' => $nb_arbre,
						'branche' => $nb_branche + 1);
	//on construit l'url à partir des valeurs de notre tableau
	$url_branche_plus = http_build_query($branche_plus);
	//on affiche le lien pour augmenter les branches
	echo'<a href=http://localhost/exercice/foret.php?' .$url_branche_plus. '> Ajouter des branches </a>';
?>