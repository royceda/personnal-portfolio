<?php
session_start();
$adresse_actuelle="../pannier/verifier.php";
include_once "modules/bdd.php";
include_once "modules/connexion.php";
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
<?php 
if ($b==TRUE){
$statement="Select Count(*) As nb From commande Where confirme=0 And nclient=".$_SESSION['id'].'"';
$nb_commande=$bdd->query($statement)->fetch()['nb'];
}
else {
	if (isset($_SESSION['pannier'])){
		$nb_commande=count($_SESSION['pannier']);
	}
	else 
		$nb_commande=0;
}
?>
<div style="display:inline-block;width:100%;">
<a class="voir_pannier" href="http://localhost/rrl/panier/verifier.php">Cart:<span class="nb_items"><?php echo $nb_commande?></span> item </a>
</div>
<?php 
if ($nb_commande==0){
	?>
	<div class="center">
	<span class="panniervide"> Votre pannier est vide.
		<?php if ($b==FALSE) echo "Vous aviez déjà des articles dans votre panier ? Connectez-vous pour les retrouver";
				else echo 'retourner à <a href="../index.php" style="text-decoration:underline;color:black"> l\'accueil</a>'?>
	</span>
	</div>
<?php 
}
else{?>
	
<table>
<tr>
	<th class="croix"></th>
	<th class="photo"></th>
	<th class="description"></th>
	<th class="quantity">quantity</th>
	<th class="price">price</th>
</tr>
<?php
	if ($b==TRUE){
		$statement="Select co.nprod as id, co.quantite as quantite, c.nom as catalogue, p.prix as prix".
		"From commande co,catalogue c,produit p".
		"Where co.confirme=0 And co.nclient=".$_SESSION['id'].'" And p.id=co.nprod And p.catalogue=c.id';
		$select=$bdd->query($statement);
		while ($res=$select->fetch()){
			?>
			<tr>
				<td  class="croix"><a href="pannier/delete.php?i=<?php echo $res['nproduit']?>"><img src="../images/cross.png"/></a></td>
				<td><img src="../images/photos/<?php echo $res['catalogue']?>/<?php echo $res['id']?>.jpeg" alt="photo"/></td>
				<td></td>
				<td class="quantity">X <form action="pannier/modifier.php?id=<?php echo $res['id']?>" ><input value="<?php echo $res['quantite']?>" name="<?php echo $res['id']?>"/></form></td>
				<td class="price"><?php echo $res['quantite']*$res['prix']?>&euro;</td>
				</tr>
			
			<?php 
			$total+=$res['quantite']*$res['prix'];
		}
		
	}
	else{
		foreach ($_SESSION['pannier'] as $id->$quantite){
			$statement="SELECT c.nom as catalogue, p.prix as prix FROM catalogue c, produit p p.id=$id And p.catalogue=c.id";
			$res=$bdd->query($statement)->fetch();?>
			<tr>
				<td  class="croix"><a href="pannier/delete.php?i=<?php echo $id?>"><img src="../images/cross.png"/></a></td>
				<td><img src="../images/photos/<?php echo $res['catalogue']?>/<?php echo $id?>.jpeg" alt="photo"/></td>
				<td></td>
				<td class="quantity">X <form action="pannier/modifier.php?id=<?php echo $id?>" ><input value="<?php echo $res['quantite']?>" name="<?php echo $res['id']?>"/></form></td>
				<td class="price"><?php echo $res['quantite']*$res['prix']?>&euro;</td>
				</tr>
		<?php
		$total+=$res['quantite']*$res['prix'];	
		}
	}
	?>
	<tr>
	<td class="croix"></td>
	<td></td>
	<td></td>
	<td class="quantity">Total items</td>
	<td class="price"><?php echo $total?>&euro;</td>
	</tr>
	
	<tr>
	<td class="croix"></td>
	<td></td>
	<td></td>
	<td class="quantity"><strong>Frais de port</strong></td>
	<td class="price">5&euro;</td>
	</tr>
	<tr>
	<td class="croix"></td>
	<td></td>
	<td></td>
	<td class="quantity"><strong>total</strong></td>
	<td class="price"><?php echo $total+5?>&euro;</td>
	</tr>
	
	</table>	
<div class="center">
<div class="confirmer"><a href="pannier/confirmer.php">CONFIRMER</a></div>
</div>
			<?php 
}
include_once '../bottom.php';
?>