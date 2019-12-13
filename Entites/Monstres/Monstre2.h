#ifndef DEF_MST2
#define DEF_MST2

#include "../Entite.h"

class Monstre2 : public Entite
{
public:

	Monstre2(int x, int y);
	//action monstre en fonction du joueur
	void actions(Entite* j, int h, int l);
};
#endif
