<?php
	session_start();
	$id=0;
	$adresse_actuelle="validation.php";
	include_once 'modules/bdd.php';
	include 'modules/connexion.php';
?>
<!Doctype html> 
<html class="">
	<head>
		<meta http-equiv="content-type" content="text/html; charset=UTF-8">
		<link href="menu.css" rel="stylesheet" type="text/css">
    	<link href="head.css" rel="stylesheet" type="text/css">
 		<link href="css/bottom.css" rel="stylesheet" type="text/css">
	    <title> Validation de l'incription </title>
    </head>

    <body>
	  	<?php include 'head.php'; ?>
	  	<?php include 'menu.php'; ?>

	    <h1 style="text-align:center"> Validation de l'insciption </h1>

	    <div align="center">
	    	Votre inscription a bien été validée, veuillez vous connecter.
	    </div>
	    <?php include 'bottom.php'; ?>	   
    </body>
</html>