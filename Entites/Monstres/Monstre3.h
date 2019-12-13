#ifndef DEF_MST3
#define DEF_MST3

#include "../Entite.h"

class Monstre3 : public Entite
{
public:

	Monstre3(int x, int y);
	//action monstre en fonction du joueur
	void actions(Entite* j, int h, int l);
};
#endif
