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

/** Simplifie l'expression du signe de la fraction
NOTA : La méthode est non utilisée pour l'instant puisque 
le pgcd simplifie automatiquement les négatifs en dénominateur
**/
void cfraction::verifier_signe() {
	// Fraction du type -a/-b  ==> a/b
	if (m_numerateur < 0 && m_denominateur < 0) {
		m_numerateur *= -1;
		m_denominateur *= -1;
	}
	// Fraction du type a/-b ==> -a/b
	if (m_numerateur > 0 && m_denominateur < 0) {
		m_numerateur *= -1;
		m_denominateur *= -1;
	}
}


// Methodes arithmétiques raccourcies


/** Additionne deux fractions et stockent le résultat dans la première
* @param : fraction la valeur à ajouter
**/
void cfraction::ajouter(cfraction fraction){
	int num1 = m_numerateur;
	int den1 = m_denominateur;
	int num2 = fraction.m_numerateur;
	int den2 = fraction.m_denominateur;

	// On met sur le même dénominateur
	if (den1 != den2) {
		num1 *= fraction.m_denominateur;
		den1 *= fraction.m_denominateur;
		num2 *= m_denominateur;
		den2 *= m_denominateur;
	}

	// On calcule la somme
	num1 = num1 + num2;

	// On réduit
	int pgcd = PGCD(num1, den1);
	num1 /= pgcd;
	den1 /= pgcd;

	// On stocke le résultat
	m_numerateur = num1;
	m_denominateur = den1;
	verifier_signe();
}

/** Additionne une fraction et un entier et stockent le résultat dans la fraction
* @param : number le nombre entier à ajouter à la fraction
**/
void cfraction::ajouter(int number) {
	int num1 = m_numerateur;
	int den1 = m_denominateur;
	int num2 = number;
	int den2 = 1;

	// On met sur le même dénominateur
	if (den1 != den2) {
		num2 *= m_denominateur;
		den2 *= m_denominateur;
	}

	// On calcule la somme
	num1 = num1 + num2;

	// On réduit
	int pgcd = PGCD(num1, den1);
	num1 /= pgcd;
	den1 /= pgcd;

	// On stocke le résultat
	m_numerateur = num1;
	m_denominateur = den1;
	verifier_signe();
}

/** Soustrait deux fractions et stockent le résultat dans la première
* @param : fraction la valeur à soustraire
**/
void cfraction::enlever(cfraction fraction) {
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

	// On stocke le résultat
	m_numerateur = num1;
	m_denominateur = den1;
	verifier_signe();
}

/** Multiplie deux fractions et stocke la fraction
* @param : fraction la valeur à multiplier
**/
void cfraction::multiplier(cfraction fraction){

	// On calcule le produit
	m_numerateur *= fraction.m_numerateur;
	m_denominateur *= fraction.m_denominateur;

	// On réduit
	int pgcd = PGCD(m_numerateur, m_denominateur);
	m_numerateur /= pgcd;
	m_denominateur /= pgcd;
	verifier_signe();
}

/** Divise deux fractions et stocke la fraction
* @param : fraction la valeur dont on divise la fraction
**/
void cfraction::diviser(cfraction fraction) {

	// On calcule le produit
	m_numerateur *= fraction.m_denominateur;
	m_denominateur *= fraction.m_numerateur;

	// On réduit
	int pgcd = PGCD(m_numerateur, m_denominateur);
	m_numerateur /= pgcd;
	m_denominateur /= pgcd;
	verifier_signe();
}

/** Affiche la valeur de la fraction
* @param flux : flux de sortie cout
* @return : flux
**/
void cfraction::afficher(std::ostream &flux) const {
	// On affiche sous forme de fraction que si le dénominateur est
	// différent de 1
	//if (m_denominateur != 1) 
	flux << m_numerateur << "/" << m_denominateur;
	//else				   flux << m_numerateur;
}


// Methodes arithmétiques classiques


/** Additionne deux fractions et renvoie la fraction somme
* @param : fraction1 et fraction2 les cfraction à additionner
* @return : fraction somme
**/
cfraction cfraction::additionner(cfraction fraction) const{
	int num1 = m_numerateur;
	int den1 = m_denominateur;
	int num2 = fraction.m_numerateur;
	int den2 = fraction.m_denominateur;
	// On met sur le même dénominateur
	if (den1 != den2) {
		num1 *= fraction.m_denominateur;
		den1 *= fraction.m_denominateur;
		num2 *= m_denominateur;
		den2 *= m_denominateur;
	}

	// On calcule la somme
	num1 = num1 + num2;

	// On réduit
	int pgcd = PGCD(num1, den1);
	num1 /= pgcd;
	den1 /= pgcd;

	// On renvoie la somme
	cfraction fraction_somme(num1, den1);
	fraction_somme.verifier_signe();
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
	fraction_difference.verifier_signe();
	return fraction_difference;
}

/** Multiplie deux fractions et renvoie la fraction produit
* @param : fraction1 et fraction2 les cfraction à multiplier
* @return : fraction produit
**/
cfraction cfraction::produit(cfraction fraction) const {
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
	fraction_produit.verifier_signe();
	return fraction_produit;
}

/** Divise deux fractions et renvoie la fraction quotient
* @param : fraction1 et fraction2 les cfraction à diviser
* @return : fraction quotient
**/
cfraction cfraction::quotient(cfraction fraction) const {
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
	fraction_quotient.verifier_signe();
	return fraction_quotient;
}


// Methodes de comparaison


bool cfraction::est_egal(cfraction fraction) const {
	return (m_numerateur == fraction.m_numerateur &&
			m_denominateur == fraction.m_denominateur);
}

bool cfraction::est_superieur(cfraction fraction) const {
	// On calcule la difference des fractions
	cfraction diff = soustraire(fraction);

	// On verifie le signe de la fraction et on
	// renvoie la valeur du booléen en conséquence
	return ((diff.m_numerateur > 0 && diff.m_denominateur > 0));
}

bool cfraction::est_inferieur(cfraction fraction) const {
	// On calcule la difference des fractions
	cfraction diff = soustraire(fraction);

	// On verifie le signe de la fraction et on
	// renvoie la valeur du booléen en conséquence
	return ((diff.m_numerateur < 0 && diff.m_denominateur > 0));
}


/// OPERATEURS

// Operateurs arithmétiques raccourcies
void operator+=(cfraction& fraction1, cfraction fraction2) {
	fraction1.ajouter(fraction2);
}

void operator+=(cfraction& fraction1, int number) {
	fraction1.ajouter(number);
}

void operator-=(cfraction& fraction1, cfraction fraction2) {
	fraction1.enlever(fraction2);
}

void operator*=(cfraction& fraction1, cfraction fraction2) {
	fraction1.multiplier(fraction2);
}

void operator/=(cfraction& fraction1, cfraction fraction2) {
	fraction1.diviser(fraction2);
}

std::ostream& operator<<(std::ostream &flux, cfraction const& fraction) {
	fraction.afficher(flux);
	return flux;
}

// Operateurs arithmétiques classiques
cfraction operator+(cfraction fraction1, cfraction fraction2) {
	cfraction somme = fraction1.additionner(fraction2);
	return somme;
}

cfraction operator-(cfraction fraction1, cfraction fraction2) {
	cfraction difference = fraction1.soustraire(fraction2);
	return difference;
}

cfraction operator*(cfraction fraction1, cfraction fraction2) {
	cfraction produit = fraction1.produit(fraction2);
	return produit;
}

cfraction operator/(cfraction fraction1, cfraction fraction2) {
	cfraction quotient = fraction1.quotient(fraction2);
	return quotient;
}

// Operateurs de comparaison
bool operator==(cfraction fraction1, cfraction fraction2) {
	return fraction1.est_egal(fraction2);
}

bool operator>(cfraction fraction1, cfraction fraction2) {
	return fraction1.est_superieur(fraction2);
}

bool operator<(cfraction fraction1, cfraction fraction2) {
	return fraction1.est_inferieur(fraction2);
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