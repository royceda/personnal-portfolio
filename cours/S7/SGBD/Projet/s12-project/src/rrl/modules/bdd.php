<?php
try {
	$pdo_options [PDO::ATTR_ERRMODE] = PDO::ERRMODE_EXCEPTION;
	$bdd = new PDO ( 'mysql:host=localhost;dbname=rrl', 'root', '',array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION) );
} catch ( Exception $e ) {
	die ( 'Erreur : ' . $e->getMessage () );
}
?>
