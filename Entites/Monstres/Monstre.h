#ifndef DEF_MST
#define DEF_MST

#include "../Entite.h"

class Monstre : public Entite
{
public:

	Monstre(int x, int y);
	//action monstre en fonction du joueur
	void actions(Entite* j, int clock);
};
#endif
