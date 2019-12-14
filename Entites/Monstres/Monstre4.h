#ifndef DEF_MST4
#define DEF_MST4

#include "../Entite.h"
#include "Path.h"

class Monstre4 : public Entite
{
public:

	Monstre4(int x, int y);
	//action monstre en fonction du joueur
	void actions(Entite* j, int* map, int h, int l);
};
#endif
