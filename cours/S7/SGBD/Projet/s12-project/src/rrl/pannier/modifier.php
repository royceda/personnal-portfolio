<?php
session_start();
if (!isset($_GET['id']) || !isset($_GET['qute'])){
	header("../pannier/verifier.php");
}
else{
	include_once "../modules/bdd.php";
	include_once "../modules/connexion.php";
	if ($b==TRUE){
		$statement="UPDATE commande SET quantite=".$_GET['qute']." WHERE nprod=".$_GET['id']." AND nclient=".$_SESSION['id']." AND confirme=0";
		$bdd->exec($statement);
		header("../pannier/verifier.php");
	}
	else {
		$_SESSION['pannier'][$_GET['id']]=$_GET["qute"];
		header("../pannier/verifier.php");
	}
}