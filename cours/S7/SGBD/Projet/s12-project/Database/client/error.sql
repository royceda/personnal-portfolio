DROP table error;


CREATE TABLE error(
       id INTEGER PRIMARY KEY NOT NULL AUTO_INCREMENT,
       message VARCHAR(64))
       CHARSET=UTF8;
     

INSERT INTO error(id, message)
       values(1, 'error: Produit indisponible');

INSERT INTO error(id, message)
       values(2, 'error: Commande non confirm�');

INSERT INTO error(id, message)
       values(3, 'error: Impossible, prosuit non command�');
