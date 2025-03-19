<?php
session_start();
	setcookie('langue', 'fr', time()+3600);
	
	header('Location: cookie.html');
?>