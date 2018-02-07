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