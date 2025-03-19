<?php
	session_start();
	session_destroy();
	$_SESSION['connected'] = '';
	setcookie('user','toto',time()-3600);
	header('location:main.php');
?>