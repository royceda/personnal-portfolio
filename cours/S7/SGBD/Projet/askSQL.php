<?php
// on se connecte � MySQL
$db = mysql_connect('localhost', 'login', 'password');

// on s�lectionne la base
mysql_select_db('nom_de_la_base',$db);

// on cr�e la requ�te SQL
$sql = 'SELECT nom,prenom,statut,date FROM famille_tbl';

// on envoie la requ�te
$req = mysql_query($sql) or die('Erreur SQL !<br>'.$sql.'<br>'.mysql_error());

// on fait une boucle qui va faire un tour pour chaque enregistrement
while($data = mysql_fetch_assoc($req))
    {
    // on affiche les informations de l'enregistrement en cours
    echo '<b>'.$data['nom'].' '.$data['prenom'].'</b> ('.$data['statut'].')';
    echo ' <i>date de naissance : '.$data['date'].'</i><br>';
    }

// on ferme la connexion � mysql
mysql_close();
?> 
