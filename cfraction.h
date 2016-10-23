#ifndef CFRACTION_H_INCLUDED
#define CFRACTION_H_INCLUDED

/***
*	Classe écrite dans le contexte du TP d'OpenClassrooms https://openclassrooms.com/courses/programmez-avec-le-langage-c/tp-la-poo-en-pratique-avec-zfraction
*	Alexandre BONIN
*	2016
***/

#include <iostream>

class cfraction {

	public:
		// Constructeurs
		cfraction();
		cfraction(int a);
		cfraction(int a, int b);

		void verifier_signe();

		// Operateurs arithmétiques raccourcies
		void ajouter(cfraction fraction);
		void ajouter(int number);
		void enlever(cfraction fraction);
		void multiplier(cfraction fraction);
		void diviser(cfraction fraction);
		void afficher(std::ostream &flux) const;

		// Operateurs arithmétiques classiques
		cfraction additionner(cfraction fraction) const;
		cfraction soustraire(cfraction fraction) const;
		cfraction produit(cfraction fraction) const;
		cfraction quotient(cfraction fraction) const;

		// Operateurs de comparaison
		bool est_egal(cfraction fraction) const;
		bool est_superieur(cfraction fraction) const;
		bool est_inferieur(cfraction fraction) const;

	private:
		int m_numerateur;
		int m_denominateur;

};


/// OPERATEURS

// Operateurs arithmétiques raccourcis
void operator+=(cfraction& fraction1, cfraction fraction2);
void operator+=(cfraction& fraction1, int number);
void operator-=(cfraction& fraction1, cfraction fraction2);
void operator*=(cfraction& fraction1, cfraction fraction2);
void operator/=(cfraction& fraction1, cfraction fraction2);
std::ostream& operator<<(std::ostream &flux, cfraction const& fraction);

// Operateurs arithmétiques classiques
cfraction operator+(cfraction fraction1, cfraction fraction2);
cfraction operator-(cfraction fraction1, cfraction fraction2);
cfraction operator*(cfraction fraction1, cfraction fraction2);
cfraction operator/(cfraction fraction1, cfraction fraction2);

// Operateurs de comparaison
bool operator==(cfraction fraction1, cfraction fraction2);
bool operator>(cfraction fraction1, cfraction fraction2);
bool operator<(cfraction fraction1, cfraction fraction2);

/// FONCTIONS

int PGCD(int a, int b);

#endif // CFRACTION_H_INCLUDED
