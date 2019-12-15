#ifndef DEF_MST4
#define DEF_MST4

#include "../Entite.h"

class Monstre4 : public Entite
{
public:

	Monstre4(int x, int y);
	//action monstre en fonction du joueur
	void actions(Entite* j);
};
#endif
