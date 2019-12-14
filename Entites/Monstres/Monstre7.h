#ifndef DEF_MST7
#define DEF_MST7

#include "../Entite.h"
#include "Path.h"

class Monstre7 : public Entite
{
public:

	Monstre7(int x, int y);
	//action monstre en fonction du joueur
	void actions(Entite* j, int* map, int h, int l);
};
#endif
