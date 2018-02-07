-- inscription


-- on entre l'adresse
INSERT INTO adresse(rue, ville, code_postale, pays)
       VALUES('aaaa', 'aaaa', 00000, 'FRANCE');
		 
-- on rentre les noms et coord
INSERT INTO membre(nom, prenom, mail, telephone, adresse)
       VALUES('XXXXX', 'XXXX', 'XXXX@G.COM',00000000,NULL);


-- on creer l'identification
INSERT INTO identifiant(login, password)
       VALUES('XXXX@G.COM', 'PASSS');



-- login

SELECT password
FROM identification
WHERE login = VAR;

