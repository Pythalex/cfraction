#include "cfraction.h"

/// CONSTRUCTEURS

/** Constructeur par défaut de cfraction
**/
cfraction::cfraction() {
	m_numerateur = 1;
	m_denominateur = 1;
}

/** Constructeur de cfraction
* @param a : numérateur de la fraction
**/
cfraction::cfraction(int a) {
	m_numerateur = a;
	m_denominateur = 1;
}

/** Constructeur de cfraction
* @param a : numérateur de la fraction
* @param b : dénominateur de la fraction
**/
cfraction::cfraction(int a, int b) {
	int pgcd = PGCD(a, b);
	m_numerateur   = a / pgcd;
	m_denominateur = b / pgcd;
}


/// METHODES

/** Additionne deux fractions et renvoie la fraction somme
* @param : fraction1 et fraction2 les cfraction à additionner
* @return : fraction somme
**/
cfraction cfraction::ajouter(cfraction fraction) const{
	int num1 = m_numerateur;
	int den1 = m_denominateur;
	int num2 = fraction.m_numerateur;
	int den2 = fraction.m_denominateur;
	// On met sur le même dénominateur
	if (den1 != den2) {
		num1 = m_numerateur * fraction.m_denominateur;
		den1 = m_denominateur * fraction.m_denominateur;
		num2 = fraction.m_numerateur * m_denominateur;
		den2 = fraction.m_denominateur * m_denominateur;
	}

	// On calcule la somme
	num1 = num1 + num2;

	// On réduit
	int pgcd = PGCD(num1, den1);
	num1 /= pgcd;
	den1 /= pgcd;

	// On renvoie la somme
	cfraction fraction_somme(num1, den1);
	return fraction_somme;
}

/** Soustrait deux fractions et renvoie la fraction difference
* @param : fraction1 et fraction2 les cfraction à soustraire
* @return : fraction difference
**/
cfraction cfraction::soustraire(cfraction fraction) const {
	int num1 = m_numerateur;
	int den1 = m_denominateur;
	int num2 = fraction.m_numerateur;
	int den2 = fraction.m_denominateur;
	// On met sur le même dénominateur
	if (den1 != den2) {
		num1 = m_numerateur * fraction.m_denominateur;
		den1 = m_denominateur * fraction.m_denominateur;
		num2 = fraction.m_numerateur * m_denominateur;
		den2 = fraction.m_denominateur * m_denominateur;
	}

	// On calcule la différence
	num1 = num1 - num2;

	// On réduit
	int pgcd = PGCD(num1, den1);
	num1 /= pgcd;
	den1 /= pgcd;

	// On renvoie la différence
	cfraction fraction_difference(num1, den1);
	return fraction_difference;
}

/** Multiplie deux fractions et renvoie la fraction produit
* @param : fraction1 et fraction2 les cfraction à multiplier
* @return : fraction produit
**/
cfraction cfraction::multiplier(cfraction fraction) const {
	int num1 = m_numerateur;
	int den1 = m_denominateur;
	int num2 = fraction.m_numerateur;
	int den2 = fraction.m_denominateur;

	// On calcule le produit
	num1 *= num2;
	den1 *= den2;

	// On réduit
	int pgcd = PGCD(num1, den1);
	num1 /= pgcd;
	den1 /= pgcd;

	// On renvoie le produit
	cfraction fraction_produit(num1, den1);
	return fraction_produit;
}

/** Divise deux fractions et renvoie la fraction quotient
* @param : fraction1 et fraction2 les cfraction à diviser
* @return : fraction quotient
**/
cfraction cfraction::diviser(cfraction fraction) const {
	int num1 = m_numerateur;
	int den1 = m_denominateur;
	int num2 = fraction.m_numerateur;
	int den2 = fraction.m_denominateur;

	// On calcule le produit
	num1 *= den2;
	den1 *= num2;

	// On réduit
	int pgcd = PGCD(num1, den1);
	num1 /= pgcd;
	den1 /= pgcd;

	// On renvoie le produit
	cfraction fraction_quotient(num1, den1);
	return fraction_quotient;
}


/** Affiche la valeur de la fraction
* @param flux : flux de sortie cout 
* @return : flux
**/
void cfraction::afficher(std::ostream &flux) const{
	// On affiche sous forme de fraction que si le dénominateur est
	// différent de 1
	if(m_denominateur > 1) flux << m_numerateur << "/" << m_denominateur;
	else				   flux << m_numerateur;
}


/// OPERATEURS

cfraction operator+(cfraction fraction1, cfraction fraction2) {
	cfraction somme = fraction1.ajouter(fraction2);
	return somme;
}

cfraction operator-(cfraction fraction1, cfraction fraction2) {
	cfraction difference = fraction1.soustraire(fraction2);
	return difference;
}

cfraction operator*(cfraction fraction1, cfraction fraction2) {
	cfraction produit = fraction1.multiplier(fraction2);
	return produit;
}

cfraction operator/(cfraction fraction1, cfraction fraction2) {
	cfraction quotient = fraction1.diviser(fraction2);
	return quotient;
}

std::ostream& operator<<(std::ostream &flux, cfraction const& fraction) {
	fraction.afficher(flux);
	return flux;
}


/// FONCTIONS

/** Calcule le PGCD de deux nombres et le renvoie
* @param : a nombre 1
* @param : b nombre 2
* @return : pgcd
**/
int PGCD(int a, int b) {
	int reste = 1;
	// Algorithme d'Euclide
	while (reste != 0) {
		reste = a % b;
		if (reste != 0) {
			a = b;
			b = reste;
		}
	}
	return b;
}