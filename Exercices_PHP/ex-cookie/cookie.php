<?php
	session_start();
?>
<html>
	<header>
	</header>
		<body>
		 <a href="http://localhost/exercice/cookieFR.php"> FR </a>
		 -
		 <a href="http://localhost/exercice/cookieEN.php"> EN </a>
		<?php
	if(isset($_COOKIE['langue'])){
		if($_COOKIE['langue'] == 'en'){
		echo"c'est de l'anglais !";
		}
	
		else{
			echo"c'est du français !";
		}
	}
?>
		</body>
</html>


