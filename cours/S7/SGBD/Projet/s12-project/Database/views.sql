-- Produit star

-- Classement des stars

drop view plus_moins;

CREATE VIEW plus_moins (ventes, nprod, designation) AS
SELECT count(nprod) AS ventes, p.id as nprod, designation 
FROM commande right outer join produit p
ON p.id = commande.nprod	        
GROUP BY nprod 
ORDER BY ventes DESC;

SELECT *
FROM plus_moins;


-- Classement des flops
drop view moins_plus;

CREATE VIEW moins_plus (ventes, nprod, designation) AS
SELECT count(nprod) AS ventes, p.id AS nprod, designation
FROM commande RIGHT OUTER JOIN produit p 
ON p.id = commande.nprod
GROUP BY nprod 
ORDER BY ventes;

SELECT *
FROM moins_plus;


-- classement par prix
drop view cheap_to_expensive;

CREATE VIEW cheap_to_expensive (id, designation, prix) AS
SELECT id, designation, prix
FROM produit
ORDER BY prix desc;

SELECT * FROM cheap_to_expensive;


-- Liste des meilleurs clients
drop view best_clients;

CREATE VIEW best_clients (ncl, nom, prenom, nb_achats) AS
SELECT cl.id as ncl, cl.nom as nom, cl.prenom as prenom, count(nclient) as nb_achats 
FROM membre cl, commande c
WHERE cl.id = c.nclient
GROUP BY cl.id
ORDER BY nb_achats desc;


SELECT *
FROM best_clients; 


-- info client sur une commande


SELECT m.nom as Nom, m.prenom as prenom, a.rue as Rue, a.ville as Ville, a.code_postale as Postale, a.pays as Pays, count(c.nclient)
FROM adresse a, commande c, membre m
WHERE c.nclient = m.id
AND m.adresse = a.id;


-- d'autre requete utiile
-- historique d'achat du client 2

select * 
from commande, produit, disponibilite d
 where commande.nprod = produit.id
 and nclient = 2 
and commande.nprod = d.nprod ;
