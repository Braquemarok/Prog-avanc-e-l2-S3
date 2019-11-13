#ifndef DEF_JOUEUR
#define DEF_JOUEUR

#include "../Entite.h"

class Joueur : public Entite
{
public:
	//constructeur
	Joueur();

	//action du joueur
	void actions(int clock);

private:

	int armure;
	std::string arme;

};
#endif
