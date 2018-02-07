-- phpMyAdmin SQL Dump
-- version 4.1.12
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Ven 12 Décembre 2014 à 23:01
-- Version du serveur :  5.6.16
-- Version de PHP :  5.5.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `rrl`
--

-- --------------------------------------------------------

--
-- Structure de la table `adresse`
--

CREATE TABLE IF NOT EXISTS `adresse` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ville` varchar(100) NOT NULL,
  `rue` varchar(255) NOT NULL,
  `code_postale` int(5) NOT NULL,
  `pays` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=14 ;

--
-- Contenu de la table `adresse`
--

INSERT INTO `adresse` (`id`, `ville`, `rue`, `code_postale`, `pays`) VALUES
(1, 'LH', '12 rue du beau', 76000, 'FRANCE'),
(2, 'PARIS', '12 rue Rivoli', 1000, 'FRANCE'),
(3, 'BERLIN', '12 Munich', 9890, 'ALLEMAGNE'),
(4, 'ROME', '12 Vatican', 1231, 'ITALIE'),
(5, 'LIEGE', '12 rue Ste Cathe', 33000, 'BELGIQUE'),
(6, 'SEVILLE', '12 rue Ste Cathe', 33000, 'ESPAGNE'),
(7, 'MUNICH', '12 rue Ste Cathe', 33000, 'ALLEMAGNE'),
(8, 'ZURICH', '12 rue Ste Cathe', 33000, 'SUISSE'),
(9, 'GENOA', '12 rue Ste Cathe', 33000, 'ITALIE'),
(10, 'NICE', '12 Place Massena', 6000, 'FRANCE'),
(11, 'Talence', 'Avenue des Facul', 33400, 'France '),
(12, 'villa', '11', 33000, 'france'),
(13, '', '', 0, 'france');

-- --------------------------------------------------------

--
-- Structure de la table `avis`
--

CREATE TABLE IF NOT EXISTS `avis` (
  `nprod` int(11) DEFAULT NULL,
  `nclient` int(11) DEFAULT NULL,
  `note` int(11) DEFAULT NULL,
  `comment` varchar(64) DEFAULT NULL,
  KEY `nprod` (`nprod`),
  KEY `nclient` (`nclient`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `best_clients`
--
CREATE TABLE IF NOT EXISTS `best_clients` (
`ncl` int(11)
,`nom` varchar(12)
,`prenom` varchar(12)
,`nb_achats` bigint(21)
);
-- --------------------------------------------------------

--
-- Structure de la table `catalogue`
--

CREATE TABLE IF NOT EXISTS `catalogue` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(12) NOT NULL,
  `maj` date NOT NULL,
  `type` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=9 ;

--
-- Contenu de la table `catalogue`
--

INSERT INTO `catalogue` (`id`, `nom`, `maj`, `type`) VALUES
(1, 'CHAUSSURES', '2014-12-10', 'baskets'),
(2, 'VETEMENTS', '2014-12-04', 'vestes'),
(3, 'VETEMENTS', '2014-12-04', 'chemises'),
(4, 'ACCESSOIRES', '2014-12-04', 'cravates'),
(5, 'VETEMENTS', '2014-12-04', 'pantalons'),
(6, 'ACCESSOIRES', '2014-12-04', 'ceintures'),
(7, 'VETEMENTS', '2014-12-04', 'chemises'),
(8, '', '2014-12-10', '');

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `cheap_to_expensive`
--
CREATE TABLE IF NOT EXISTS `cheap_to_expensive` (
`id` int(11)
,`designation` varchar(32)
,`prix` int(11)
);
-- --------------------------------------------------------

--
-- Structure de la table `code_promo`
--

CREATE TABLE IF NOT EXISTS `code_promo` (
  `ncl` int(11) NOT NULL,
  `pourcentage` int(11) NOT NULL,
  `ncmd` int(11) DEFAULT NULL,
  KEY `ncl` (`ncl`),
  KEY `ncmd` (`ncmd`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `code_promo`
--

INSERT INTO `code_promo` (`ncl`, `pourcentage`, `ncmd`) VALUES
(4, 15, 9);

-- --------------------------------------------------------

--
-- Structure de la table `commande`
--

CREATE TABLE IF NOT EXISTS `commande` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nprod` int(11) DEFAULT NULL,
  `quantite` int(11) DEFAULT NULL,
  `nclient` int(11) DEFAULT NULL,
  `confirme` int(11) DEFAULT '0',
  `date` datetime DEFAULT NULL,
  `taille` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  KEY `nprod` (`nprod`),
  KEY `nclient` (`nclient`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=68 ;

--
-- Contenu de la table `commande`
--

INSERT INTO `commande` (`id`, `nprod`, `quantite`, `nclient`, `confirme`, `date`, `taille`) VALUES
(1, 2, 3, 2, 0, NULL, ''),
(3, 2, 2, 2, 0, NULL, ''),
(4, 2, 3, 3, 0, NULL, ''),
(5, 2, 1, 2, 0, NULL, ''),
(6, 2, 1, 2, 0, NULL, ''),
(8, 10, 1, 2, 0, NULL, ''),
(9, 13, 1, 2, 0, NULL, ''),
(10, 13, 1, 2, 0, NULL, ''),
(11, 10, 1, 2, 0, NULL, ''),
(12, 16, 1, 3, 0, NULL, ''),
(13, 14, 1, 2, 0, NULL, ''),
(15, 4, 1, 5, 1, '2014-12-04 00:00:00', ''),
(16, 16, 1, 6, 0, '2014-12-04 00:00:00', ''),
(17, 4, 1, 2, 0, '2014-12-04 00:00:00', ''),
(19, 8, 1, 7, 0, '2014-12-04 00:00:00', ''),
(20, 10, 1, 2, 1, '2014-12-04 00:00:00', ''),
(21, 17, 1, 5, 0, '2014-12-04 00:00:00', ''),
(22, 17, 1, 4, 0, '2014-12-04 00:00:00', ''),
(24, 9, 1, 5, 1, '2014-12-04 00:00:00', ''),
(25, 14, 1, 6, 0, '2014-12-04 00:00:00', ''),
(27, 11, 1, 7, 0, '2014-12-04 00:00:00', ''),
(28, 15, 1, 5, 0, '2014-12-04 00:00:00', ''),
(29, 17, 1, 6, 0, '2014-12-04 00:00:00', ''),
(30, 9, 1, 7, 0, '2014-12-04 00:00:00', ''),
(31, 17, 1, 5, 1, '2014-12-04 00:00:00', ''),
(32, 9, 1, 7, 1, '2014-12-04 00:00:00', ''),
(33, 38, 1, 2, 1, '2014-12-04 00:00:00', ''),
(34, 46, 1, 4, 0, '2014-12-04 00:00:00', ''),
(36, 38, 1, 4, 0, '2014-12-04 00:00:00', ''),
(37, 5, 1, 3, 1, '2014-12-04 00:00:00', ''),
(38, 36, 1, 2, 1, '2014-12-04 00:00:00', ''),
(40, 38, 1, 6, 1, '2014-12-04 00:00:00', '');

-- --------------------------------------------------------

--
-- Structure de la table `disponibilite`
--

CREATE TABLE IF NOT EXISTS `disponibilite` (
  `nprod` int(11) NOT NULL,
  `taille` int(11) DEFAULT NULL,
  `quantite` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `disponibilite`
--

INSERT INTO `disponibilite` (`nprod`, `taille`, `quantite`) VALUES
(2, 42, 14),
(12, 42, 8),
(3, 43, 3),
(13, 41, 9),
(3, 39, 5),
(11, 41, 4),
(9, 40, 11),
(4, 47, 2),
(18, 47, 2),
(17, 46, 6),
(5, 42, 9),
(8, 43, 9),
(10, 45, 3),
(2, 43, 9),
(4, 42, 6),
(11, 47, 4),
(10, 42, 10),
(6, 44, 4),
(17, 47, 7),
(18, 43, 3),
(11, 47, 3),
(6, 44, 6),
(7, 40, 4),
(16, 38, 8),
(10, 41, 3),
(17, 44, 8),
(12, 45, 2),
(12, 42, 8),
(2, 39, 7),
(10, 44, 8),
(14, 40, 3),
(4, 41, 1),
(5, 38, 7),
(16, 39, 3),
(19, 45, 2),
(58, 41, 12),
(59, 41, 12),
(70, 30, 100),
(71, 45, 12),
(71, 65, 12),
(72, 65, 12),
(60, 40, 50),
(61, 40, 50),
(57, 10, 20),
(54, 40, 11),
(53, 40, 20),
(52, 44, 30);

-- --------------------------------------------------------

--
-- Structure de la table `expedition`
--

CREATE TABLE IF NOT EXISTS `expedition` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `addr` int(11) NOT NULL,
  `date` date DEFAULT NULL,
  `ncmd` int(11) DEFAULT NULL,
  UNIQUE KEY `id` (`id`),
  KEY `addr` (`addr`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Structure de la table `identifiant`
--

CREATE TABLE IF NOT EXISTS `identifiant` (
  `login` varchar(32) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  UNIQUE KEY `login` (`login`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `identifiant`
--

INSERT INTO `identifiant` (`login`, `password`) VALUES
('sabiretude@gmail.com', '$2y$10$uH0j8WDJB'),
('sabiretud@gmail.com', '$2y$10$R1PECNgAE'),
('sabirreda@gmail.com', '$2y$10$s5j3hL28tB7d2xNjpjs0g.prH5WgS1SF8rtlxFiBdWHSoQ7kSjOn.');

-- --------------------------------------------------------

--
-- Structure de la table `membre`
--

CREATE TABLE IF NOT EXISTS `membre` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(12) DEFAULT NULL,
  `prenom` varchar(12) DEFAULT NULL,
  `mail` varchar(32) DEFAULT NULL,
  `telephone` int(10) DEFAULT NULL,
  `adresse` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  UNIQUE KEY `mail` (`mail`),
  KEY `adresse` (`adresse`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=29 ;

--
-- Contenu de la table `membre`
--

INSERT INTO `membre` (`id`, `nom`, `prenom`, `mail`, `telephone`, `adresse`) VALUES
(2, 'VAN PEE', 'LINUS', 'aaaaaa@bb.fr', 676753452, 3),
(3, 'Shakur', 'Tupac', 'B.panther@licos.com', 676753452, 2),
(4, 'Combs', 'Sean', 'DIDDY@licos.com', 676753452, 7),
(5, 'Machiavel', 'Nicolas', 'N.Machiavel@licos.com', 676753452, 9),
(6, 'Presley', 'Elvis', 'E.Presley@licos.com', 676753452, 10),
(7, 'Endrix', 'Jimmy', 'J.Endrix@licos.com', 676753452, 8),
(8, 'Kant', 'Emmanuel', 'E.Kant@licos.com', 676753452, 6),
(9, 'Bryant', 'Kobe', 'K.Bryant@aol.com', 676753452, 8),
(10, 'Wiggings', 'Andrew', 'A.Wiggings@licos.com', 676753452, 4),
(11, 'Benzema', 'Karim', 'K.benzema@aol.com', 676753452, 5),
(23, 'Reda', 'Sabir', 'sabiretude@gmail.com', 1111111111, 12),
(24, 'Reda', 'Sabir', 'sabiretud@gmail.com', 1111111111, 12),
(28, 'Reda', 'Reda Rahal', 'sabirreda@gmail.com', 1111111111, 12);

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `moins_plus`
--
CREATE TABLE IF NOT EXISTS `moins_plus` (
`ventes` bigint(21)
,`nprod` int(11)
,`designation` varchar(32)
);
-- --------------------------------------------------------

--
-- Structure de la table `photo`
--

CREATE TABLE IF NOT EXISTS `photo` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `type` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `photo`
--

INSERT INTO `photo` (`id`, `name`, `type`) VALUES
(0, '01', '');

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `plus_moins`
--
CREATE TABLE IF NOT EXISTS `plus_moins` (
`ventes` bigint(21)
,`nprod` int(11)
,`designation` varchar(32)
);
-- --------------------------------------------------------

--
-- Structure de la table `produit`
--

CREATE TABLE IF NOT EXISTS `produit` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `designation` varchar(32) DEFAULT NULL,
  `descriptif` varchar(64) DEFAULT NULL,
  `prix` int(11) DEFAULT NULL,
  `catalogue` int(11) DEFAULT NULL,
  `date_add` date DEFAULT NULL,
  `photo` varchar(64) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  KEY `catalogue` (`catalogue`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=73 ;

--
-- Contenu de la table `produit`
--

INSERT INTO `produit` (`id`, `designation`, `descriptif`, `prix`, `catalogue`, `date_add`, `photo`) VALUES
(2, 'AIR JORDAN XXI PE', 'basket', 240, 1, '2014-04-20', './photos/CHAUSSURES/2.jpg'),
(3, 'NIKE KD VII', 'basket', 110, 1, '2014-12-04', './photos/CHAUSSURES/3.jpg'),
(4, 'AIR JORDAN III', 'basket', 110, 1, '2014-12-04', './photos/chaussure/4.jpg'),
(5, 'AIR JORDAN VII', 'basket', 110, 1, '2014-12-04', './photos/CHAUSSURES/5.jpg'),
(6, 'AIR JORDAN XI', 'basket', 110, 1, '2014-12-04', './photos/CHAUSSURES/6.jpg'),
(7, 'NIKE HYPPERFUSE 2014', 'basket', 110, 1, '2014-12-04', './photos/CHAUSSURES/7.jpg'),
(8, 'NIKE AIR ZOOM HYPERDUNK', 'basket', 110, 1, '2014-12-04', './photos/chaussure/8.jpg'),
(9, 'NIKE LUNAR FLYNIT RED', 'basket', 120, 1, '2014-12-04', './photos/chaussure/9.jpg'),
(10, 'NIKE AIR FORCE ONE WHITE', 'basket ', 110, 1, '2014-12-04', './photos/chaussure/10.jpg'),
(11, 'ADIDAS D-ROSE 4', 'basket', 90, 1, '2014-12-04', './photos/chaussure/11.jpg'),
(12, 'ADIDAS HOWARD II', 'basket', 110, 1, '2014-12-04', './photos/CHAUSSURES/12.jpg'),
(13, 'LOUBOUTIN RED', 'basket', 985, 1, '2014-12-04', './photos/chaussure/13.jpg'),
(14, 'LOUBOUTIN WHITE', 'basket', 1010, 1, '2014-12-04', './photos/chaussure/14.jpg'),
(15, 'LOUBOUTIN BLACK', 'basket', 823, 1, '2014-12-04', './photos/chaussure/15.jpg'),
(16, 'G.ZANOTTI', 'basket', 823, 1, '2014-12-04', './photos/CHAUSSURES/16.jpg'),
(17, 'G.ZANOTI GOLD/WHITE', 'basket', 800, 1, '2014-12-04', './photos/CHAUSSURES/17.jpg'),
(18, 'JIMMY CHOO BLACK', 'basket', 800, 1, '2014-12-04', './photos/CHAUSSURES/18.jpg'),
(19, 'PAUL SMITH', 'costume bleu marine', 1200, 4, '2014-12-04', './photos/VETEMENTS/18.jpg'),
(20, 'BURBERRY', 'costume noir', 1200, 4, '2014-12-04', './photos/CHAUSSURES/10.jpg'),
(21, 'YVES SAINT LAURENT', 'Cravate en soie unie noir', 99, 6, '2014-12-04', './photos/cravates/1'),
(22, 'YVES SAINT LAURENT', 'Cravate en soie petites goutelette bleu marine', 99, 4, '2014-12-04', './photos/cravates/2'),
(23, 'YVES SAINT LAURENT', 'Cravate en soie jacquard tresse bleu marine', 99, 4, '2014-12-04', './photos/cravates/3'),
(24, 'YVES SAINT LAURENT', 'Cravate en soie jacquard pois noir', 99, 4, '2014-12-04', './photos/cravates/3'),
(25, 'YVES SAINT LAURENT', 'Cravate en soie monogramme noir', 99, 4, '2014-12-04', './photos/cravates/4'),
(26, 'YVES SAINT LAURENT', 'Cravate en soie motifs pois bleu marine', 99, 4, '2014-12-04', './photos/cravates/5'),
(27, 'YVES SAINT LAURENT', 'Cravate en soie unie rouge', 99, 4, '2014-12-04', './photos/cravates/6'),
(28, 'YVES SAINT LAURENT', 'Cravate en soie rayure oblique noir et gris', 99, 4, '2014-12-04', './photos/cravates/7'),
(29, 'YVES SAINT LAURENT', 'Cravate en soie rayure oblique bleu et noir', 99, 4, '2014-12-04', './photos/cravates/8'),
(30, 'YVES SAINT LAURENT', 'Cravate pure soie logo lettre bordeaux', 99, 4, '2014-12-04', './photos/cravates/9'),
(31, 'YVES SAINT LAURENT', 'Cravate en soie jacquard tresse bleu nuit', 99, 4, '2014-12-04', './photos/cravates/10'),
(32, 'YVES SAINT LAURENT', 'Cravate en soie rayure oblique rouge et bordeaux', 99, 4, '2014-12-04', './photos/cravates/11'),
(33, 'YVES SAINT LAURENT', 'Cravate en soie jacquard noir', 99, 4, '2014-12-04', './photos/cravates/12'),
(34, 'YVES SAINT LAURENT', 'Cravate en soie jacquard bleu ciel', 99, 4, '2014-12-04', './photos/cravates/13'),
(35, 'YVES SAINT LAURENT', 'Cravate en soie pois fantaisie noir', 99, 4, '2014-12-04', './photos/cravates/14'),
(36, 'YVES SAINT LAURENT', 'Cravate en soie rayure diagonales gris noir', 99, 4, '2014-12-04', './photos/cravates/15'),
(37, 'YVES SAINT LAURENT', 'Cravate en soie motifs pois noir et blanc', 99, 4, '2014-12-04', './photos/cravates/16'),
(38, 'YVES SAINT LAURENT', 'Cravate en soie jacquard "bulles"', 99, 4, '2014-12-04', './photos/cravates/17'),
(39, 'THE KOOPLES', 'veste de costume en laine noir', 385, 4, '2014-12-04', './photos/cravates/18'),
(40, 'YVES SAINT LAURENT', 'Cravate en soie unie', 99, 4, '2014-12-04', './photos/cravates/18'),
(41, 'YVES SAINT LAURENT', 'Cravate en soie unie', 99, 4, '2014-12-04', './photos/VETEMENTS/19.jpg'),
(42, 'THE KOOPLES', 'pantalon de costume en pique laine noir', 195, 4, '2014-12-04', './photos/VETEMENTS/1.jpg'),
(43, 'THE KOOPLES', 'veste de costume Pinpoint', 425, 4, '2014-12-04', './photos/VETEMENTS/1.jpg'),
(44, 'THE KOOPLES', 'Veste de costume en twill de laine', 425, 4, '2014-12-04', './photos/VETEMENTS/20.jpg'),
(45, 'THE KOOPLES', 'Veste de costume en laine pied-de-poule', 425, 4, '2014-12-04', './photos/VETEMENTS/3.jpg'),
(46, 'THE KOOPLES', 'Veste de costume en piqu? de laine bleu marine', 425, 4, '2014-12-04', './photos/VETEMENTS/4.jpg'),
(47, 'THE KOOPLES', 'Veste de costume en laine pied-de-poule', 425, 4, '2014-12-04', './photos/VETEMENTS/5.jpg'),
(48, 'THE KOOPLES', 'Veste de smoking ajust?e en laine ? motifs Prince de Galles Gris', 395, 4, '2014-12-04', './photos/VETEMENTS/6.jpg'),
(49, 'THE KOOPLES', 'Veste de smoking ajust?e ? un bouton d?tails en velours noir', 425, 4, '2014-12-04', './photos/VETEMENTS/7.jpg'),
(50, 'THE KOOPLES', 'Veste de costume en laine iris', 425, 4, '2014-12-04', './photos/VETEMENTS/8.jpg'),
(51, 'THE KOOPLES', 'Pantalon de costume imprim? Prince de Galles en laine slim fit g', 175, 4, '2014-12-04', './photos/VETEMENTS/1.jpg'),
(52, 'THE KOOPLES', 'Pantalon de costume en laine ceintur', 175, 4, '2014-12-04', './photos/VETEMENTS/2.jpg'),
(53, 'THE KOOPLES', 'Pantalon de costume ceintur? en laine slim fit gris', 175, 4, '2014-12-04', './photos/VETEMENTS/3.jpg'),
(54, 'THE KOOPLES', 'Pantalon de costume ajust? en laine', 175, 4, '2014-12-04', './photos/VETEMENTS/4.jpg'),
(55, 'THE KOOPLES', 'Pantalon de costume en piqu? de laine noir', 175, 4, '2014-12-04', './photos/VETEMENTS/5.jpg'),
(56, 'THE KOOPLES', 'Pantalon de costume en laine micro pied-de-poule', 175, 4, '2014-12-04', './photos/VETEMENTS/6.jpg'),
(57, 'THE KOOPLES', 'Pantalon de costume imprim? pied de poule en laine slim fit', 175, 4, '2014-12-04', './photos/VETEMENTS/7.jpg'),
(60, 'THE KOOPLES', 'Pantalon de costume imprimï¿½ pied de poule en laine slim fit', 175, 4, '2014-12-08', './photos/VETEMENTS/16.jpg'),
(61, 'THE KOOPLES', 'Pantalon de costume imprimï¿½ pied de poule en laine slim fit', 175, 4, '2014-12-08', './photos/VETEMENTS/16.jpg');

-- --------------------------------------------------------

--
-- Structure de la table `promo`
--

CREATE TABLE IF NOT EXISTS `promo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `catalogue` int(11) DEFAULT NULL,
  `reduction` int(11) DEFAULT NULL,
  `startline` date NOT NULL,
  `deadline` date DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  KEY `catalogue` (`catalogue`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=20 ;

--
-- Contenu de la table `promo`
--

INSERT INTO `promo` (`id`, `catalogue`, `reduction`, `startline`, `deadline`) VALUES
(1, 4, 70, '0000-00-00', '0000-00-00'),
(2, 5, 13, '0000-00-00', '2014-12-31'),
(3, 1, 71, '0000-00-00', '2014-12-31'),
(4, 3, 29, '0000-00-00', '2014-12-31'),
(5, 5, 2, '2014-12-17', '2014-12-16'),
(6, 1, 57, '0000-00-00', '2014-12-31'),
(7, 3, 73, '0000-00-00', '2014-12-31'),
(8, 1, 60, '0000-00-00', '2014-12-31'),
(9, 3, 76, '0000-00-00', '2014-12-31'),
(10, 2, 10, '0000-00-00', '2014-12-31'),
(11, 4, 7, '0000-00-00', '2014-12-04'),
(12, 1, 50, '2014-12-22', '2014-12-16'),
(13, 1, 50, '2014-12-22', '2014-12-16');

-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `statCatalogue`
--
CREATE TABLE IF NOT EXISTS `statCatalogue` (
`nom` varchar(12)
,`total` decimal(65,4)
);
-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `statClient`
--
CREATE TABLE IF NOT EXISTS `statClient` (
`client` int(11)
,`prix` decimal(42,0)
);
-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `statMoinsVendu`
--
CREATE TABLE IF NOT EXISTS `statMoinsVendu` (
`produit` int(11)
,`achats` decimal(52,0)
);
-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `statPlusVendu`
--
CREATE TABLE IF NOT EXISTS `statPlusVendu` (
`produit` int(11)
,`achats` decimal(52,0)
);
-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `statProduit`
--
CREATE TABLE IF NOT EXISTS `statProduit` (
`id` int(11)
,`designation` varchar(32)
,`total` decimal(65,4)
);
-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `stattmp`
--
CREATE TABLE IF NOT EXISTS `stattmp` (
`date` datetime
,`nprod` int(11)
,`quantite` int(11)
,`nclient` int(11)
,`confirme` int(11)
,`pourcentage` bigint(11)
);
-- --------------------------------------------------------

--
-- Doublure de structure pour la vue `statType`
--
CREATE TABLE IF NOT EXISTS `statType` (
`type` varchar(255)
,`total` decimal(65,4)
);
-- --------------------------------------------------------

--
-- Structure de la vue `best_clients`
--
DROP TABLE IF EXISTS `best_clients`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `best_clients` AS select `cl`.`id` AS `ncl`,`cl`.`nom` AS `nom`,`cl`.`prenom` AS `prenom`,count(`c`.`nclient`) AS `nb_achats` from (`membre` `cl` join `commande` `c`) where (`cl`.`id` = `c`.`nclient`) group by `cl`.`id` order by `nb_achats` desc;

-- --------------------------------------------------------

--
-- Structure de la vue `cheap_to_expensive`
--
DROP TABLE IF EXISTS `cheap_to_expensive`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `cheap_to_expensive` AS select `produit`.`id` AS `id`,`produit`.`designation` AS `designation`,`produit`.`prix` AS `prix` from `produit` order by `produit`.`prix` desc;

-- --------------------------------------------------------

--
-- Structure de la vue `moins_plus`
--
DROP TABLE IF EXISTS `moins_plus`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `moins_plus` AS select count(`commande`.`nprod`) AS `ventes`,`p`.`id` AS `nprod`,`p`.`designation` AS `designation` from (`produit` `p` left join `commande` on((`p`.`id` = `commande`.`nprod`))) group by `commande`.`nprod` order by `ventes`;

-- --------------------------------------------------------

--
-- Structure de la vue `plus_moins`
--
DROP TABLE IF EXISTS `plus_moins`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `plus_moins` AS select count(`commande`.`nprod`) AS `ventes`,`p`.`id` AS `nprod`,`p`.`designation` AS `designation` from (`produit` `p` left join `commande` on((`p`.`id` = `commande`.`nprod`))) group by `commande`.`nprod` order by `ventes` desc;

-- --------------------------------------------------------

--
-- Structure de la vue `statCatalogue`
--
DROP TABLE IF EXISTS `statCatalogue`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `statCatalogue` AS select `ca`.`nom` AS `nom`,sum(((`p`.`prix` * `c`.`quantite`) * (1 - (`c`.`pourcentage` / 100)))) AS `total` from ((`produit` `p` join `stattmp` `c`) join `catalogue` `ca`) where ((`c`.`nprod` = `p`.`id`) and (`ca`.`id` = `p`.`catalogue`)) group by `ca`.`nom` order by `total` desc;

-- --------------------------------------------------------

--
-- Structure de la vue `statClient`
--
DROP TABLE IF EXISTS `statClient`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `statClient` AS select `c`.`nclient` AS `client`,sum((`c`.`quantite` * `p`.`prix`)) AS `prix` from (`commande` `c` join `produit` `p`) where (`c`.`nprod` = `p`.`id`) group by `c`.`nclient` order by `prix` desc;

-- --------------------------------------------------------

--
-- Structure de la vue `statMoinsVendu`
--
DROP TABLE IF EXISTS `statMoinsVendu`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `statMoinsVendu` AS select `p`.`id` AS `produit`,(count(0) * sum(`c`.`quantite`)) AS `achats` from (`commande` `c` join `produit` `p`) where (`c`.`nprod` = `p`.`id`) group by `p`.`id` order by `achats`;

-- --------------------------------------------------------

--
-- Structure de la vue `statPlusVendu`
--
DROP TABLE IF EXISTS `statPlusVendu`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `statPlusVendu` AS select `p`.`id` AS `produit`,(count(0) * sum(`c`.`quantite`)) AS `achats` from (`commande` `c` join `produit` `p`) where (`c`.`nprod` = `p`.`id`) group by `p`.`id` order by `achats` desc;

-- --------------------------------------------------------

--
-- Structure de la vue `statProduit`
--
DROP TABLE IF EXISTS `statProduit`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `statProduit` AS select `p`.`id` AS `id`,`p`.`designation` AS `designation`,sum(((`p`.`prix` * `c`.`quantite`) * (1 - (`c`.`pourcentage` / 100)))) AS `total` from (`produit` `p` join `stattmp` `c`) where (`c`.`nprod` = `p`.`id`) group by `p`.`id` order by `total` desc;

-- --------------------------------------------------------

--
-- Structure de la vue `stattmp`
--
DROP TABLE IF EXISTS `stattmp`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `stattmp` AS select `c`.`date` AS `date`,`c`.`nprod` AS `nprod`,`c`.`quantite` AS `quantite`,`c`.`nclient` AS `nclient`,`c`.`confirme` AS `confirme`,ifnull(`cd`.`pourcentage`,0) AS `pourcentage` from (`commande` `c` left join `code_promo` `cd` on((`c`.`id` = `cd`.`ncmd`))) group by `c`.`id`;

-- --------------------------------------------------------

--
-- Structure de la vue `statType`
--
DROP TABLE IF EXISTS `statType`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `statType` AS select `ca`.`type` AS `type`,sum(((`p`.`prix` * `c`.`quantite`) * (1 - (`c`.`pourcentage` / 100)))) AS `total` from ((`produit` `p` join `stattmp` `c`) join `catalogue` `ca`) where ((`c`.`nprod` = `p`.`id`) and (`ca`.`id` = `p`.`catalogue`)) group by `ca`.`type` order by `total` desc;

--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `avis`
--
ALTER TABLE `avis`
  ADD CONSTRAINT `avis_ibfk_1` FOREIGN KEY (`nprod`) REFERENCES `produit` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `avis_ibfk_2` FOREIGN KEY (`nclient`) REFERENCES `membre` (`id`) ON DELETE CASCADE;

--
-- Contraintes pour la table `code_promo`
--
ALTER TABLE `code_promo`
  ADD CONSTRAINT `code_promo_ibfk_1` FOREIGN KEY (`ncl`) REFERENCES `membre` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `code_promo_ibfk_2` FOREIGN KEY (`ncmd`) REFERENCES `commande` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `commande`
--
ALTER TABLE `commande`
  ADD CONSTRAINT `commande_ibfk_1` FOREIGN KEY (`nprod`) REFERENCES `produit` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `commande_ibfk_2` FOREIGN KEY (`nclient`) REFERENCES `membre` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `expedition`
--
ALTER TABLE `expedition`
  ADD CONSTRAINT `expedition_ibfk_1` FOREIGN KEY (`addr`) REFERENCES `adresse` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `identifiant`
--
ALTER TABLE `identifiant`
  ADD CONSTRAINT `identifiant_ibfk_1` FOREIGN KEY (`login`) REFERENCES `membre` (`mail`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `membre`
--
ALTER TABLE `membre`
  ADD CONSTRAINT `membre_ibfk_1` FOREIGN KEY (`adresse`) REFERENCES `adresse` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `produit`
--
ALTER TABLE `produit`
  ADD CONSTRAINT `produit_ibfk_1` FOREIGN KEY (`catalogue`) REFERENCES `catalogue` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `promo`
--
ALTER TABLE `promo`
  ADD CONSTRAINT `promo_ibfk_1` FOREIGN KEY (`catalogue`) REFERENCES `catalogue` (`id`) ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
