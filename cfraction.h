#ifndef CFRACTION_H_INCLUDED
#define CFRACTION_H_INCLUDED

#include <iostream>

class cfraction {

	public:
		// Constructeurs
		cfraction();
		cfraction(int a);
		cfraction(int a, int b);
		// Operateurs
		cfraction ajouter(cfraction fraction) const;
		cfraction soustraire(cfraction fraction) const;
		cfraction multiplier(cfraction fraction) const;
		cfraction diviser(cfraction fraction) const;
		void afficher(std::ostream &flux) const;

	private:
		int m_numerateur;
		int m_denominateur;

};

/// OPERATEURS

cfraction operator+(cfraction fraction1, cfraction fraction2);
cfraction operator-(cfraction fraction1, cfraction fraction2);
cfraction operator*(cfraction fraction1, cfraction fraction2);
cfraction operator/(cfraction fraction1, cfraction fraction2);
std::ostream& operator<<(std::ostream &flux, cfraction const& fraction);

/// FONCTIONS

int PGCD(int a, int b);

#endif // CFRACTION_H_INCLUDED
