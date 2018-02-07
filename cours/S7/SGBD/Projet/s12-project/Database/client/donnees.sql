USE RRL;


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


-- code promo

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, null);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, 1+RAND()*39);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, null);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, 1+RAND()*39);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, 1+RAND()*39);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, 1+RAND()*39);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, 1+RAND()*39);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, 1+RAND()*39);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, 1+RAND()*39);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*60, 1+RAND()*39);

INSERT INTO code_promo(ncl, pourcentage, ncmd)
       VALUES(1+RAND()*10, RAND()*70, 1+RAND()*39);




-- client

INSERT INTO membre (id, nom, prenom, telephone, mail, adresse)
       VALUES (1, 'Brown', 'Charlie', 0676753452, 'allo@gmail.ch', 1);

INSERT INTO membre (nom, prenom, telephone,mail, adresse)
       VALUES ('VAN PEE', 'LINUS', 0676753452, 'aaaaaa@bb.fr', 3);

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
       VALUES ('allo@gmail.ch', 'zfdj66ijdk');

INSERT INTO identifiant (login, password)
       VALUES ('aaaaaa@bb.fr', 'nfjklhs_879');

INSERT INTO identifiant (login, password)
       VALUES ('B.panther@licos.com', 'jfjh657sT');

INSERT INTO identifiant (login, password)
       VALUES ('DIDDY@licos.com', 'BUvdjf65e');

INSERT INTO identifiant (login, password)
       VALUES ('N.Machiavel@licos.com', 'klflkwe787');

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

INSERT INTO catalogue(nom, maj)
       VALUES ( 'VESTES', NOW());

INSERT INTO catalogue(nom, maj)
       VALUES ( 'CHEMISES', NOW());

INSERT INTO catalogue(nom, maj)
       VALUES ( 'CRAVATES', NOW());

INSERT INTO catalogue(nom, maj)
       VALUES ( 'PANTALON', NOW());

INSERT INTO catalogue(nom, maj)
       VALUES ( 'ACCESSOIRES', NOW());



-- produit

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (1, 'NIKE LEBRON XI', 'basket', 180, 1, '2014-11-22','./photos/chaussure/1.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (2,'AIR JORDAN XXI PE', 'basket', 240, 1, '2014-04-20','./photos/chaussure/2.jpg');

INSERT INTO produit (id, designation, descriptif, prix, catalogue, date_add, photo)
       VALUES (3, 'NIKE KD VII', 'basket', 110, 1, NOW(), './photos/chaussure/3.jpg');

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

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie unie noir', 99, 6, NOW(),'./photos/cravates/1');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie petites goutelette bleu marine', 99, 4, NOW(),'./photos/cravates/2');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie jacquard tresse bleu marine', 99, 4, NOW(),'./photos/cravates/3');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie jacquard pois noir', 99, 4, NOW(),'./photos/cravates/3');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie monogramme noir', 99, 4, NOW(),'./photos/cravates/4');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie motifs pois bleu marine', 99, 4, NOW(),'./photos/cravates/5');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie unie rouge', 99, 4, NOW(),'./photos/cravates/6');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie rayure oblique noir et gris', 99, 4, NOW(),'./photos/cravates/7');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie rayure oblique bleu et noir', 99, 4, NOW(),'./photos/cravates/8');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate pure soie logo lettre bordeaux', 99, 4, NOW(),'./photos/cravates/9');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie jacquard tresse bleu nuit', 99, 4, NOW(),'./photos/cravates/10');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie rayure oblique rouge et bordeaux', 99, 4, NOW(),'./photos/cravates/11');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie jacquard noir', 99, 4, NOW(),'./photos/cravates/12');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie jacquard bleu ciel', 99, 4, NOW(),'./photos/cravates/13');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie pois fantaisie noir', 99, 4, NOW(),'./photos/cravates/14');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie rayure diagonales gris noir', 99, 4, NOW(),'./photos/cravates/15');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie motifs pois noir et blanc', 99, 4, NOW(),'./photos/cravates/16');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie jacquard "bulles"', 99, 4, NOW(),'./photos/cravates/17');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'veste de costume en laine noir', 385, 4, NOW(),'./photos/cravates/18');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie unie', 99, 4, NOW(),'./photos/cravates/18');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('YVES SAINT LAURENT', 'Cravate en soie unie', 99, 4, NOW(),'./photos/cravates/19');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'pantalon de costume en pique laine noir', 195, 4, NOW(),'./photos/pantalon/1');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'veste de costume Pinpoint', 425, 4, NOW(),'./photos/veste/1');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Veste de costume en twill de laine', 425, 4, NOW(),'./photos/veste/2');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Veste de costume en laine pied-de-poule', 425, 4, NOW(),'./photos/veste/3');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Veste de costume en piqué de laine bleu marine', 425, 4, NOW(),'./photos/veste/4');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Veste de costume en laine pied-de-poule', 425, 4, NOW(),'./photos/veste/5');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Veste de smoking ajustée en laine à motifs Prince de Galles Gris', 395, 4, NOW(),'./photos/veste/6');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Veste de smoking ajustée à un bouton détails en velours noir', 425, 4, NOW(),'./photos/veste/7');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Veste de costume en laine irisée', 425, 4, NOW(),'./photos/veste/8');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Pantalon de costume imprimé Prince de Galles en laine slim fit gris et noir', 175, 4, NOW(),'./photos/pantalon/1');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Pantalon de costume en laine ceinturé', 175, 4, NOW(),'./photos/pantalon/2');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Pantalon de costume ceinturé en laine slim fit gris', 175, 4, NOW(),'./photos/pantalon/3');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Pantalon de costume ajusté en laine', 175, 4, NOW(),'./photos/pantalon/4');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Pantalon de costume en piqué de laine noir', 175, 4, NOW(),'./photos/pantalon/5');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Pantalon de costume en laine micro pied-de-poule', 175, 4, NOW(),'./photos/pantalon/6');

INSERT INTO produit (designation, descriptif, prix, catalogue, date_add, photo)
       VALUES ('THE KOOPLES', 'Pantalon de costume imprimé pied de poule en laine slim fit', 175, 4, NOW(),'./photos/pantalon/7');


-- disponibilite

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(2, 42, 14); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1, 45, 5); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 

INSERT iNTO disponibilite (nprod, taille, quantite)
       VALUES(1+floor(rand()*20), 38+floor(rand()*10), 1+rand()*10); 



-- commande

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (1+floor(RAND(16)*10),3, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (1+floor(RAND(16)*10), 7, 1);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (1+floor(RAND(16)*10), 2, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (1+floor(RAND(16)*10), 3, 3);
 
INSERT INTO commande (nprod,quantite,nclient)
       VALUES (1+floor(RAND(16)*10), 1, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (1+floor(RAND(16)*10), 1, 2);

INSERT INTO commande (nprod,quantite,nclient)
       VALUES (1+floor(RAND(16)*10), 3, 1);

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
       VALUES (1+floor(RAND(16)*154/10), 1, 1);

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1 + floor(RAND()*17), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1+floor(RAND()*50), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1+floor(RAND()*50), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1+floor(RAND()*50), 1, 1+floor(RAND()*7), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1+floor(RAND()*50), 1, 1+floor(RAND()*6), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1+floor(RAND()*50), 1, 1+floor(RAND()*6), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1+floor(RAND()*50), 1, 1+floor(RAND()*6), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1+floor(RAND()*50), 1, 1+floor(RAND()*6), now(), floor(rand()*2));

INSERT INTO commande (nprod, quantite, nclient, date, confirme)
       VALUES (1+floor(RAND()*50), 1, 1+floor(RAND()*6), now(), floor(rand()*2));



-- promo catalogue

INSERT INTO promo (id, catalogue, reduction, deadline)
       VALUES (1, 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-25');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-31');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-31');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-31');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-31');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-31');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-31');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-31');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-31');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), '2014-12-31');

INSERT INTO promo (catalogue, reduction, deadline)
       VALUES ( 1+floor(RAND()*5), 1+floor(RAND()*100), NOW());




-- VUES

-- Classement des stars


CREATE VIEW plus_moins (ventes, nprod, designation) AS
SELECT count(nprod) AS ventes, p.id as nprod, designation 
FROM commande right outer join produit p
ON p.id = commande.nprod	        
GROUP BY nprod 
ORDER BY ventes DESC;

SELECT *
FROM plus_moins;


-- Classement des flops


CREATE VIEW moins_plus (ventes, nprod, designation) AS
SELECT count(nprod) AS ventes, p.id AS nprod, designation
FROM commande RIGHT OUTER JOIN produit p 
ON p.id = commande.nprod
GROUP BY nprod 
ORDER BY ventes;



-- classement par prix

CREATE VIEW cheap_to_expensive (id, designation, prix) AS
SELECT id, designation, prix
FROM produit
ORDER BY prix desc;



-- Liste des meilleurs clients


CREATE VIEW best_clients (ncl, nom, prenom, nb_achats) AS
SELECT cl.id as ncl, cl.nom as nom, cl.prenom as prenom, count(nclient) as nb_achats 
FROM membre cl, commande c
WHERE cl.id = c.nclient
GROUP BY cl.id
ORDER BY nb_achats desc;



