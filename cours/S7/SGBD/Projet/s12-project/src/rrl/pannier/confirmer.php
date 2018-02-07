<?php
session_start();
$adresse_actuelle="../pannier/confirmer.php";
include_once "../modules/connexion.php";
if (isset($_GET['co']) && isset($_GET['login'])){
	foreach ($_SESSION['pannier'] as $id=>$quantite){
		$statement="Insert Into (nprod,quantite,nclient,date,confirme) Values($id,$quantite,".$_SESSION['id'].',NOW(),0)';
		$bdd->exec($statement);
	}
}
?>
<!DOCTYPE html>
<html class=""><head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
<meta charset="UTF-8">
<title>Pannier</title>
<link href="../menu.css" rel="stylesheet" type="text/css">
<link href="../head.css" rel="stylesheet" type="text/css">
<link href="../index.css" rel="stylesheet" type="text/css">
<link href="../css/pannier.css" rel="stylesheet" type="text/css">
</head>
<body>
<?php include_once "../head.php"?>
<?php include_once "../menu.php"?>
<?php if ($b==FALSE){?>
<div class="message">
<span>Pour poursuivre la démarche de votre achat, vous êtes invités à vous connecter ou créer un compte</span>
</div>	
<form action="../pannier/confirmer.php?co=1" id="connexion_2">
<div><label for="login">Login</label><input id="login" name="login" type="text"></div>
<div><label for="password">Pass</label><input id="password" name="password" type="password"></div>
<div class="connexion">
	<a href="inscription.php">register</a> 
    <input type="submit" value="Log in"/>	
</div>
</form>
<?php 
}
//Permettre à l'utilisateur de saisir une adresse ou de récuperer une ancienne utilisé dans une commande ou son adresse 

?>