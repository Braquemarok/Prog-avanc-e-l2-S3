#ifndef DEF_JOUEUR
#define DEF_JOUEUR

#include "../Entite.h"

class Joueur : public Entite
{
public:
	//constructeur
	Joueur();
	Joueur(int x, int y);

	//action du joueur
	void actions( int z, int t);

private:

	int armure;
	std::string arme;

};
#endif
