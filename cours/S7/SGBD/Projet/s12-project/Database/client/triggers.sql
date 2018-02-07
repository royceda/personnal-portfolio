
DROP TRIGGER control_expedition; 
-- T1: On commmande que si le produit est dispo en taille et en quantite 
DELIMITER //
CREATE TRIGGER control_expedition BEFORE INSERT ON commande
FOR EACH ROW
BEGIN
	IF EXISTS (select * from disponibilite d where d.id=new.nprod and d.taille = new.taille and d.quantite > new.quantite) 
	THEN 
	      INSERT INTO commande( nprod, taille, quantite, nclient, confirme, date)
	     	    values(new.nprod, new.taille, new.quantite, new.nclient, new.confirme, new.date);
	    UPDATE disponibilite
	    	SET quantite = quantite-1 WHERE nprod = NEW.nprod;		

	ELSE
		INSERT INTO error(message) VALUES ('error: Produit indisponible');	
	END IF;
END;
//
DELIMITER ;





DROP TRIGGER control_avis; 
DELIMITER //
-- T3: on expedit que si la commande est confirmer
CREATE TRIGGER control_avis BEFORE INSERT ON expedition
FOR EACH ROW
BEGIN
	IF EXISTS (select * from commande c where c.id=new.ncmd and c.confirme=1)
	THEN 
	     INSERT INTO expedition(id, addr, date, ncmd)
	     	    values(new.id, new.addr, new.date, new.ncmd);
	ELSE
		INSERT INTO error(message) VALUES ('error: Commande non confirmé');
	END IF;

END;
//
DELIMITER ;




DELIMITER //
-- T4: un membre donne son avis que si il  a deja commander le produit
CREATE TRIGGER control_commande BEFORE INSERT ON avis
FOR EACH ROW
BEGIN
	IF EXISTS (select * from commande where nprod=new.nprod and nclient=new.nclient)
	THEN 
	     INSERT INTO avis(nprod, nclient, note, comment)
	     	    values(new.nprod, new.nclient, new.note, new.comment);
	ELSE
		INSERT INTO error(message) VALUES('error: Impossible, prosuit non commandé');
	END IF;
END;
//
DELIMITER;
