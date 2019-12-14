#ifndef DEF_MST5
#define DEF_MST5

#include "../Entite.h"
#include "Path.h"

class Monstre5 : public Entite
{
public:

	Monstre5(int x, int y);
	//action monstre en fonction du joueur
	void actions(Entite* j, int* map, int h, int l);
};
#endif
