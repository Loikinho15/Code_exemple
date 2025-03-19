<?php
session_start();
	setcookie('langue' , 'en', time()+3600);
	
	header('Location: cookie.html');
?>