#ifndef DEF_MST2
#define DEF_MST2

#include "../Entite.h"

class Monstre2 : public Entite
{
public:

	/**
	 * \brief Construit un Monstre
	 * \param x la position x du monstre
	 * \param y la position y du monstre
	*/
	Monstre2(int x, int y);
	
	
	/**
	 * \brief action monstre en fonction du joueur
	 * \param j le joueur
	*/
	void actions(Entite* j);
};
#endif
