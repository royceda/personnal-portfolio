<?php
if (!isset($_GET['id'])){
	header("Location: ../index.php");
}
else{
	$id_produit=$_GET['id'];
	include_once "../modules/bdd.php";
	include_once "../modules/connexion.php";
	if ($b==TRUE){
		$statement="Select id,quantite from commande where nprod=".$id_produit." And confirme=0 And nclient=".$_SESSION['id'];
		$select=$bdd->query($statement);
		$a=FALSE;
		while($res=$select->fetch()){
			$quantite=$res['quantite'];
			$a=TRUE;
		}
		if ($a){
			$statement="UPDATE commande SET quantite=".($quantite+1)." WHERE nprod=".$_GET['id']." AND nclient=".$_SESSION['id']." AND confirme=0";
			$bdd->exec($statement);
		}
		else{
			$statement="INSERT INTO commande(nprod,quantite,nclient,date,confirme) VALUES(".$_GET['id'].",1,".$_SESSION['id'].",NOW(),0)";
			$bdd->exec($statement);			
		}
	}
	else {
		if (array_key_exists($_GET['id'], $_SESSION['pannier']))
			$_SESSION['pannier'][$_GET['id']]++;
		else
			$_SESSION['pannier'][$_GET['id']]=$_GET["qute"];
	}
	header("Location: ../produit/consulter.php?id=".$_GET['id']);	
}