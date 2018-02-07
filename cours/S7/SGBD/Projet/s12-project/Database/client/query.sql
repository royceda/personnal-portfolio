USE RRL;

-- Les tables 
SELECT *
FROM adresse; 

SELECT *
FROM membre;

SELECT *
FROM produit;

SELECT *
FROM disponibilite;

SELECT *
FROM promo;

SELECT *
FROM avis;

SELECT *
FROM identifiant;

SELECT *
FROM commande;

SELECT *
FROM code_promo;


-- requetes plus specifiques

-- les ventes entre maintenant et 1/11/2014

SELECT designation, prix
FROM produit 
WHERE date_add BETWEEN '2014-11-20' AND NOW();

SELECT *
FROM commande 
WHERE date BETWEEN '2014-11-20' AND NOW();

-- Benefices

SELECT sum(c.quantite*prix) as BENEFICE_total
FROM commande c LEFT OUTER JOIN produit p 
ON c.nprod = p.id;

SELECT sum(c.quantite*prix) as BENEFICE_date
FROM commande c LEFT OUTER JOIN produit p 
ON c.nprod = p.id
WHERE c.date BETWEEN '2014-11-20' AND NOW();

-- les promo finis

SELECT *
FROM promo
WHERE deadline < NOW();


-- code promo non utilisés

SELECT *
FROM code_promo
WHERE ncmd = null;

-- test des vues

SELECT *
FROM best_clients;

SELECT *
FROM cheap_to_expensive;

SELECT *
FROM code_promo;

