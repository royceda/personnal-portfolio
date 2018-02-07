<?php
session_start();
if (!isset($_SESSION['ad'])){
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title><?php echo $designation?></title>

<link href="../head.css" rel="stylesheet" type="text/css">
</head>
<form
<div><label for="login">Login</label><input id="login" name="login" type="text"></div>
<div><label for="password">Pass</label><input id="password" name="password" type="password"></div>
<div class="connexion">
<input type="submit" value="Log in" class="login"/>
</div>

<?php 
}