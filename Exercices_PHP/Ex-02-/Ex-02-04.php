
<!-- a -->

<!-- a -->
<?php
	$string = ("Un poisson nage dans l'eau sans se noyer");
	$tableau = explode(" ", $string);
	
	for($i = 0; $i < count($tableau); $i++){
		echo "$tableau[$i] <br>";	
	}
?>
<br><br>
<!-- b -->
<?php
	$string = ("Un poisson nage dans l'eau sans se noyer");
	$tableau = explode(" ", $string);
	sort($tableau);
	
	for($i = 0; $i < count($tableau); $i++){
		echo "$tableau[$i] <br>";	
	}

?>