package tec;

/**
 * Realisation d'une Jauge avec des entiers naturels positifs.
 *
 * <p>
 * Un objet Jauge definit un niveau dans un intervalle [0, vigieMax[. 
 * Le niveau d'une jauge n'est pas limite aux valeurs dans l'intervalle.
 * <p>
 * L'etat d'une jauge correspond a la position de son niveau par rapport a 
 * l'intervalle [0, vigieMax[.
 * Une jauge definit deux etats : 
 * <ul>
 * <li>vert niveau dans l'intervalle, 
 * <li>rouge niveau superieur a l'intervalle,
 * </ul>
 * 
 * @author Georgy
 * @since 2006-2013
 */
public class JaugeNaturel { 
    private long valeur;
    private final long max;

    /**
     * Construit une instance en precisant la valeur de depart de la Jauge
     * et l'intervalle de vigie.
     * 
     * @param vigieMax valeur maximale > 0 de l'intervalle de vigie.
     * @param depart       valeur initiale du niveau.
     */
    public JaugeNaturel(long vigieMax, long depart) {
	valeur = depart;
	max = vigieMax;
    }

    /**
     * Le niveau de la jauge est-il au-dessus de vigieMax ?
     *
     * @return vrai si niveau >=  vigieMax.
     *
     */
    public boolean estRouge() {
	return valeur >= max;
    }

    /**
     * Le niveau de la jauge est-il dans l'intervalle ?
     *
     * @return vrai si niveau appartient a [0, vigieMax[.
     *
     */
    public boolean estVert() {
	// if (valeur < 0)
	//   return true;
	return (valeur >= 0) && (valeur < max);
    }
    
    /**
     * L'etat de la jauge est-il bleu ?
     *
     * @return vrai si niveau <= vigieMin.
     */
    public boolean estBleu() {
	return valeur <= 0;
    }

    /**
     * Incremente le niveau d'une unite.
     * Le niveau peut devenir superieur a vigieMax.
     */
    public void incrementer() {
	valeur++;
    }

    /**
     * Decremente le niveau d'une unite.
     */
    public void decrementer() {
	valeur--;
    }

    /**
     * Cette methode est heritee de la classe {@link java.lang.Object}.
     * Tres utile pour le debogage, elle permet de fournir une 
     * chaine de caracteres correspondant a l'etat d'un objet.
     * <p> Un code par defaut est definit dans 
     * {@link java.lang.Object#toString() la classe Object} 
     * Il faut reecrire son code a chaque classe.
     *
     * Pour les chaines de caracteres, l'operateur + correspond a la concatenation. 
     * Les valeurs numeriques sont alors convertit en ascii.
     * Si l'etat d'une instance de cette classe max=23, valeur=7 ;
     * la concatenation donne la chaene "<7 [0,23]>".
     */
    @Override
    public String toString() {
	return "<" + valeur + " [0," + max + "[>"; 
    }
}
