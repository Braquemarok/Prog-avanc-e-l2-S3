#ifndef DEF_MST6
#define DEF_MST6

#include "../Entite.h"
#include "Path.h"

class Monstre6 : public Entite
{
public:

	Monstre6(int x, int y);
	//action monstre en fonction du joueur
	void actions(Entite* j, int* map, int h, int l);
};
#endif
