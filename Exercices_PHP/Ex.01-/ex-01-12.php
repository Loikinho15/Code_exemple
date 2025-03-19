<?php
	
	
	function fonctionA($a, $b) {
		//a
		$somme = (($a +$b) == 1156);
		return $somme;
		//b
		$multilplication = (($a * $b) == 314203);
		return $multilplication;
		//c
		$sommeMultiplication = (($a + $b) == 1156) && (($a * $b) == 314203);
		return $sommeMultiplication;
		//d
		do {			
			$a++;
			$b++;
			
		} wile($sommeMultiplication = (($a + $b) == 1156) && (($a * $b) == 314203));
	
	}
	
?>