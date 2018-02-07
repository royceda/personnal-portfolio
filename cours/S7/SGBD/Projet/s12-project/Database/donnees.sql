SHOW DATABASES;
USE rrl_test;


-- adresse

INSERT INTO adresse (id, ville, rue, code_postale, pays) 
       VALUES (1,'LH', '12 rue du beau', 76000, 'FRANCE'); 

INSERT INTO adresse (id, ville, rue, code_postale, pays) 
       values(2, 'PARIS', '12 rue Rivoli', 1000, 'FRANCE'); 

INSERT INTO adresse (id, ville, rue, code_postale, pays) 
       values(3, 'BERLIN', '12 Munich', 9890, 'ALLEMAGNE'); 

INSERT INTO adresse ( ville, rue, code_postale, pays) 
       values( 'ROME', '12 Vatican', 1231, 'ITALIE'); 

INSERT INTO adresse ( ville, rue, code_postale, pays) 
       values( 'LIEGE', '12 rue Ste Catherine', 33000, 'BELGIQUE'); 

INSERT INTO adresse ( ville, rue, code_postale, pays) 
       values( 'SEVILLE', '12 rue Ste Catherine', 33000, 'ESPAGNE'); 

INSERT INTO adresse ( ville, rue, code_postale, pays) 
       values( 'MUNICH', '12 rue Ste Catherine', 33000, 'ALLEMAGNE'); 

INSERT INTO adresse ( ville, rue, code_postale, pays) 
       values( 'ZURICH', '12 rue Ste Catherine', 33000, 'SUISSE'); 

INSERT INTO adresse ( ville, rue, code_postale, pays) 
       values( 'GENOA', '12 rue Ste Catherine', 33000, 'ITALIE'); 

INSERT INTO adresse ( ville, rue, code_postale, pays) 
       values( 'NICE', '12 Place Massenat', 06000, 'FRANCE'); 


-- client

INSERT INTO membre (id, nom, prenom, telephone, mail, adresse)
       VALUES (1, 'Brown', 'Charlie', 0676753452, 'allo@gmail.ch', 1);

INSERT INTO membre (id,nom, prenom, telephone,mail, adresse)
       VALUES (2,'VAN PEE', 'LINUS', 0676753452, 'aaaaaa@bb.fr', 3);

INSERT INTO membre (nom, prenom, telephone, mail, adresse)
       VALUES ('Shakur', 'Tupac', 0676753452, 'B.panther@licos.com', 2);

INSERT INTO membre (nom, prenom, telephone, mail, adresse)
       VALUES ('Combs', 'Sean', 0676753452, 'DIDDY@licos.com', 7);

INSERT INTO membre (nom, prenom, telephone, mail, adresse)
       VALUES ('Machiavel', 'Nicolas', 0676753452, 'N.Machiavel@licos.com', 9);

INSERT INTO membre (nom, prenom, telephone, mail, adresse)
       VALUES ('Presley', 'Elvis', 0676753452, 'E.Presley@licos.com', 10);

INSERT INTO membre (nom, prenom, telephone, mail, adresse)
       VALUES ('Endrix', 'Jimmy', 0676753452, 'J.Endrix@licos.com', 8);

INSERT INTO membre (nom, prenom, telephone, mail, adresse)
       VALUES ('Kant', 'Emmanuel', 0676753452, 'E.Kant@licos.com', 6);

INSERT INTO membre (nom, prenom, telephone, mail, adresse)
       VALUES ('Bryant', 'Kobe', 0676753452, 'K.Bryant@aol.com', 8);

INSERT INTO membre (nom, prenom, telephone, mail, adresse)
       VALUES ('Wiggings', 'Andrew', 0676753452, 'A.Wiggings@licos.com', 4);

INSERT INTO membre (nom, prenom, telephone, mail, adresse)
       VALUES ('Benzema', 'Karim', 0676753452, 'K.benzema@aol.com', 5);

 
-- identifiant

INSERT INTO identifiant (login, password)
       VALUES ('allo@gmail.ch', 'blahblah');

INSERT INTO identifiant (login, password)
       VALUES ('aaaaaa@bb.fr', 'blablabla');

INSERT INTO identifiant (login, password)
       VALUES ('B.panther@licos.com', 'blahblah');

INSERT INTO identifiant (login, password)
       VALUES ('DIDDY@licos.com', 'blahblah');

INSERT INTO identifiant (login, password)
       VALUES ('N.Machiavel@licos.com', 'blahblah');

INSERT INTO identifiant (login, password)
       VALUES ('E.Presley@licos.com', 'blahblah');

INSERT INTO identifiant (login, password)
       VALUES ('J.Endrix@licos.com', 'kakakakaka');

INSERT INTO identifiant (login, password)
       VALUES ('E.Kant@licos.com', 'kakakakaka');

INSERT INTO identifiant (login, password)
       VALUES ('K.Bryant@aol.com', 'kakakakaka');

INSERT INTO identifiant (login, password)
       VALUES ('A.Wiggings@licos.com', 'kakakakaka');

INSERT INTO identifiant (login, password)
       VALUES ('K.benzema@aol.com', 'kakakakaka');



-- catalogue

INSERT INTO catalogue(id, nom, maj)
       VALUES (1, 'CHAUSSURES', '2014-04-20');

INSERT INTO catalogue(id, nom, maj)
       VALUES (2, 'VESTES', NOW());

INSERT INTO catalogue(id, nom, maj)
       VALUES (3, 'CHEMISES', NOW());

INSERT INTO catalogue(id, nom, maj)
       VALUES (4, 'CRAVATES', NOW());

INSERT INTO catalogue(id, nom, maj)
       VALUES ('PANTALON', NOW());

INSERT INTO catalogue(id, nom, maj)
       VALUES ('ACCESSOIRES', NOW());



-- produit

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (1, 'NIKE LEBRON XI', 'basket', 180, 1, '2014-11-22','./photos/chaussure/1.jpg');

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES (1, 42, 12); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1, 44, 10); 

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (2,'AIR JORDAN XXI PE', 'basket', 240, 1, '2014-04-20','./photos/chaussure/2.jpg');

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(2, 42, 14); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1, 45, 5); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 


INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (3, 'NIKE KD VII', 'basket', 110, 1, NOW(), ,'./photos/chaussure/3.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (4, 'AIR JORDAN III', 'basket', 110, 1, NOW(),'./photos/chaussure/4.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (5, 'AIR JORDAN VII', 'basket', 110, 1, NOW(),'./photos/chaussure/5.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (6, 'AIR JORDAN XI', 'basket', 110, 1, NOW(),'./photos/chaussure/6.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (7, 'NIKE HYPPERFUSE 2014', 'basket' , 110, 1, NOW(),'./photos/chaussure/7.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (8, 'NIKE AIR ZOOM HYPERDUNK', 'basket', 110, 1, NOW(),'./photos/chaussure/8.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (9,'NIKE LUNAR FLYNIT RED', 'basket', 120, 1, NOW(),'./photos/chaussure/9.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (10, 'NIKE AIR FORCE ONE WHITE', 'basket ', 110, 1, NOW(),'./photos/chaussure/10.jpg');

INSERT INTO produit (id, designation, descriptif,  prix, catalogue, date_add, photo)
       VALUES (11, 'ADIDAS D-ROSE 4', 'basket', 90, 1, NOW(),'./photos/chaussure/11.jpg');

INSERT INTO produit (id, designation, descriptif,  prix, catalogue, date_add, photo)
       VALUES (12, 'ADIDAS HOWARD II', 'basket', 110, 1, NOW(),'./photos/chaussure/12.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (13, 'LOUBOUTIN RED', 'basket', 985, 1, NOW(),'./photos/chaussure/13.jpg');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('LOUBOUTIN WHITE', 'basket', 1010, 1, NOW(),'./photos/chaussure/14.jpg');

INSERT INTO produit (designation, descriptif,  prix, catalogue, date_add, photo)
       VALUES ('LOUBOUTIN BLACK', 'basket', 823, 1, NOW(),'./photos/chaussure/15.jpg');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('G.ZANOTTI', 'basket', 823, 1, NOW(),'./photos/chaussure/16.jpg');

INSERT INTO produit (designation, descriptif,  prix, catalogue, date_add, photo)
       VALUES ('G.ZANOTI GOLD/WHITE', 'basket', 800, 1, NOW(),'./photos/chaussure/17.jpg');

INSERT INTO produit (designation, descriptif,  prix, catalogue, date_add, photo)
       VALUES ('JIMMY CHOO BLACK', 'basket', 800, 1, NOW(),'./photos/chaussure/18.jpg');

INSERT INTO produit (designation, descriptif,  prix, catalogue, date_add, photo)
       VALUES ('PAUL SMITH', 'costume bleu marine', 1200, 4, NOW(), null);

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('BURBERRY', 'costume noir', 1200, 4, NOW(), null);



-- disponibilite


-- commande
INSERT INTO commande (nprod,quantite,nclient)
       VALUES (floor(RAND(16)*10),3, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (floor(RAND(16)*10), 7, 1);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (floor(RAND(16)*10), 2, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (floor(RAND(16)*10), 3, 3);
 
INSERT INTO commande (nprod,quantite,nclient)
       VALUES (floor(RAND(16)*10), 1, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (floor(RAND(16)*10), 1, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (floor(RAND(16)*10), 3, 1);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (10, 1, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (13, 1, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (13, 1, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (10, 1, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (16, 1, 3);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (14, 1, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (floor(RAND(16)*154/10), 1, 1);


-- promo catalogue

INSERT INTO promo (id, catalogue, reduction, deadline)
       VALUES (1, floor(RAND()*5), floor(RAND()*100), '2014-12-25');



