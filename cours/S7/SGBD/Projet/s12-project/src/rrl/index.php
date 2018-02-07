<?php
session_start();
$adresse_actuelle="index.php";
$id=0;
include_once 'modules/bdd.php';
$NBPAGE=18;
include "modules/connexion.php";
?>
<!DOCTYPE html>
<html class=""><head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
<meta charset="UTF-8">
<title>Index</title>
<link href="menu.css" rel="stylesheet" type="text/css">
<link href="head.css" rel="stylesheet" type="text/css">
<link href="index.css" rel="stylesheet" type="text/css">
</head>
<body>
<?php include_once 'head.php';
include_once 'menu.php';
include_once 'modules/pannier.php';
$statement='Select name FROM photo Where id=0';
$res=$bdd->query($statement)->fetch();
?>
<div class="photo_j"><img src="images/photo_j/<?php echo $res['name']?>.jpg"><div>Nouveautés</div></div>
<div class="bloc">
<?php 
	if (!isset($_GET['p'])){
		$page=0;
	}
	else $page=$_GET['p'];
	$statement="Select p.id as id, p.type as type, p.designation as designation, p.prix as prix, c.nom as catalogue ".
				"From produit p,catalogue c, disponibilite d ".
				"Where p.catalogue=c.id And p.id=d.nprod And d.quantite<>0 ".
				"Order By date_add Desc ". 
				"Limit ".$page*$NBPAGE.",".($page+1)*$NBPAGE;
	$select=$bdd->query($statement);
	$pages=$select->rowCount();
	echo $pages;
	print_r($select);
	while($res=$select->fetch()){
		?>		 
		<div class="item">
		<div class="photo_item_c">
		<img class="photo_item" src="images/photos/<?php echo $res['catalogue']?>/<?php echo $res['id']?>.jpeg">
		<a href="produits/consulter.php?id=<?php echo $res['id']?>">Details</a>
		</div>
		<span class="info"><?php echo $res['designation']?> <span class="prix"><?php echo $res['prix']?></span></span>
		</div>
		<?php 
	}
?>
</div>
<?php 
	include_once 'modules/pages.php';
	include_once 'bottom.php';
?>


</body>
