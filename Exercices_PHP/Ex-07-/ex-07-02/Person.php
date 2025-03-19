<?php
	class Person{

		private $fisrt_name = null;
		private $last_name = null;
		private $email = null;
		private $zip_code = null;

		function __construct($fisrt_name, $last_name, $email, $zip_code){
			$this->set_first_name($fisrt_name);
			$this->set_last_name($last_name);
			$this->set_email($email);
			$this->set_zip_code($zip_code);
		}

		function set_first_name($first_name){

		}

		function set_last_name($last_name){

		}

		function set_email($email){

		}

		function set_zip_code($zip_code){

		}

		function get_first_name(){
			return $this->first_name;
		}

	}
?>