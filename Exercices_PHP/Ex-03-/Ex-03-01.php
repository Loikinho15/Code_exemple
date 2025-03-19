<?php
/*if(isset($_GET['arbre'])){
	$val = $_GET['arbre']; 
	echo"Une fôret avec $val arbre";
	$val++;
	$url = "http://$_SERVER[HTTP_HOST]$_SERVER[PHP_SELF]?arbre=$val";
}

else{
	$val = 0;
	$url = "http://$_SERVER[HTTP_HOST]$_SERVER[PHP_SELF]?arbre=$val";
	echo"Une fôret avec $val arbre";
}


echo "<a href='$url'> Ajouter un arbre  </a>";*/
?>

<?php
	
	if(isset($_GET['arbre'])){
		$nbArbre = $_GET['arbre'];
	}
	
	else{
		$nbArbre = 0;
	}
	
		echo"Il y a $nbArbre dans la forêt <br>";
		
		$nbArbre++;


echo "<a href=\"http://$_SERVER[HTTP_HOST]$_SERVER[PHP_SELF]?arbre=$nbArbre\">Ajouter un arbre</a><br>";

//ex b
		$nbArbre++;
echo "<a href=\"http://$_SERVER[HTTP_HOST]$_SERVER[PHP_SELF]?arbre=$nbArbre\">Ajouter deux arbres</a><br>";
?>