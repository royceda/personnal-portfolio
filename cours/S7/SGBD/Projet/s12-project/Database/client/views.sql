Drop View if exists `stattmp`;

Create view `stattmp` as 
SELECT c.date, nprod, quantite, nclient, confirme, IFNULL(pourcentage, 0) as pourcentage
FROM commande c
LEFT JOIN code_promo cd 
ON c.id=cd.ncmd 
Group by c.id;



DROP VIEW IF EXISTS `statCatalogue`;

CREATE VIEW `statCatalogue` AS 
Select  ca.nom, sum((p.prix*quantite)*(1-pourcentage/100)) as total
From produit p,stattmp c, catalogue ca
Where c.nprod=p.id And ca.id=p.catalogue
Group by ca.nom
ORDER BY total DESC;

--
-- Structure de la vue statClient
--
DROP VIEW IF EXISTS `statClient`;

CREATE  VIEW `statClient` AS 
select `c`.`nclient` AS `client`,sum((`c`.`quantite` * `p`.`prix`)) AS `prix` 
from (`commande` `c` join `produit` `p`) 
where (`c`.`nprod` = `p`.`id`) 
group by `c`.`nclient` 
order by `prix` desc;

--
-- Structure de la vue statMoinsVendu
--
DROP VIEW IF EXISTS `statMoinsVendu`;

CREATE  VIEW `statMoinsVendu` AS 
select `p`.`id` AS `produit`, Count(*)*sum(`c`.`quantite`) AS `achats`
 from (`commande` `c` join `produit` `p`) 
where (`c`.`nprod` = `p`.`id`) 
group by `p`.`id` 
order by `achats`;

--
-- Structure de la vue statPlusVendu
--
DROP VIEW IF EXISTS `statPlusVendu`;

CREATE  VIEW `statPlusVendu` AS 
Select `p`.`id` AS `produit`,(count(*) * sum(`c`.`quantite`)) AS `achats` 
From (`commande` `c` join `produit` `p`)
Where (`c`.`nprod` = `p`.`id`) 
Group by `p`.`id` 
order by `achats` desc;

--
-- Structure de la vue statProduit
--
DROP VIEW IF EXISTS `statProduit`;

CREATE  VIEW `statProduit` AS 
Select p.id, p.designation as designation, sum((p.prix*quantite)*(1-pourcentage/100)) as total
From produit p,stattmp c
Where c.nprod=p.id
Group by p.id
ORDER BY total DESC;
--
-- Structure de la vue statType
--
DROP VIEW IF EXISTS `statType`;

Create View `statType` As
Select  ca.type, sum((p.prix*quantite)*(1-pourcentage/100)) as total
From produit p,stattmp c, catalogue ca
Where c.nprod=p.id And ca.id=p.catalogue
Group by ca.type
ORDER BY total DESC;

