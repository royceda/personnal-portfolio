<?php
$id=999;
ini_set('xdebug.collect_vars', 'on');
ini_set('xdebug.collect_params', '4');
ini_set('xdebug.dump_globals', 'on');
ini_set('xdebug.dump.SERVER', 'REQUEST_URI');
ini_set('xdebug.show_local_vars', 'on');


session_start();

if (!isset($_GET['id'])){
	header("Location: ../index.php");
	
}
else{
	include_once '../modules/bdd.php';
	$statement="Select catalogue From produit Where id=".$_GET['id'];
	$_GET['c']=$bdd->query($statement)->fetch()['catalogue'];
	$adresse_actuelle="../categorie/index.php";
	$statement='Select name FROM photo Where id='.$_GET['c'];
	$res=$bdd->query($statement)->fetch();
	$state="Select designation From produit Where id=".$_GET['id'];
	$designation=$bdd->query($state)->fetch()['designation'];
	include "../modules/connexion.php";?>
	<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title><?php echo $designation?></title>
<link href="../menu.css" rel="stylesheet" type="text/css">
<link href="../head.css" rel="stylesheet" type="text/css">
<link href="../css/categorie.css" rel="stylesheet" type="text/css">
<link href="../css/bottom.css" rel="stylesheet" type="text/css">
<link href="../css/produit.css" rel="stylesheet" type="text/css">
<script src="../js/menu.js" type="text/javascript"></script>

</head>
<body>
<?php include "../head.php";
		include "../menu.php";?>
	<div class="photo_categorie"><img src="images/photos/categories/<?php echo $res['name']?>.jpg"></div>
	<div id="menuV">
	<div id="menu">
	<?php 
		$statement="Select id,nom From catalogue";
		$select=$bdd->query($statement);
		while($res=$select->fetch()){
			$catalogues[$res['id']]=$res['nom'];
		}
		for ($i=1;$i<5;$i++){
			echo '<div class="menu" id="menu'.$i.'" onclick="event.preventDefault();afficheMenu(this);">';
			echo '<a href="#">'.$catalogues[$i].'</a>';
			echo '</div>';
			$statement='Select type from produit Where catalogue='.$i.' Order By type';
			$select=$bdd->query($statement);
			$a=1;
			if ($_GET['c']==$i)
				echo '<div id="sousmenu'.$_GET['c'].'" style="display:initial">';
			else 
				echo '<div id="sousmenu'.$_GET['c'].'" style="display:none">';
			while($res=$select->fetch()){
				echo '<div class="sousmenu">';
				if ($i==$id && $type==$a){
					echo '<a href="../categorie/index.php?id='.$i.'&amp;ty='.$a.'" class="act">'.$res['type'].'</a>';
					$typeName=$res['type'];
				}
				else 
					echo '<a href="../categorie/index.php?id='.$i.'&amp;ty='.$a.'">'.$res['type'].'</a>';
				echo '</div>';	
				$a++;
			}
			echo "</div>";
		}
	?>	
	</div>
	</div>
<?php 
	$statement="SELECT p.id as id, p.designation as designation, p.descriptif as descriptif, p.prix as prix,".
		 " p.catalogue as catalogue, p.date_add as date,c.nom FROM produit p,catalogue c where p.id=".$_GET['id']." And c.id=".$_GET['c'] ;
$select=$bdd->query($statement);
while($res=$select->fetch()){	
?>
<div id="body">
<div class="bloc_produit">
<div class="titre">
<?php echo $res['designation'];?>
</div>
<div class="photo_produit"><img alt="<?php echo $res['designation']?>" src="../photos/<?php echo $res['catalogue']?>/<?php echo $res['id']?>.jpg"></div>
<div class="description">
<?php echo $res['descriptif']?>
</div>
	<table>
	<tr>
		<th></th>
		<th></th>
	</tr>
	<tr>
		<td>Taille:</td>
		<td>
			<form action="categorie.php?c=1&amp;&t=1">
			<?php
			$statement="SELECT taille FROM disponibilite d, produit p where d.nprod=".$_GET['id']." And d.quantite<>0" ;
			$s=$bdd->query($statement); 
			?>
			<select name="pointure">
				<option value="none" selected>Selectionez votre taille</option>
				<?php
				while($r=$select->fetch()){ 
				?>
				<option value="<?php echo $r['taille']?>"><?php echo $r['taille']?></option>
				<?php }?>
			</select>
			</form>
		</td>
	</tr>
	<tr>
		<td>Prix:</td>
		<td><?php echo $res['prix']?>€</td>
	</tr>
	</table>
<br><a href="../produit/ajouter.php"?><div class="confirmer">Ajouter</div></a>
</div>
</div>
	<?php 
}
include_once '../bottom.php';?>
</body>
</html>
<?php }?>