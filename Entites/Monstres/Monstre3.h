#ifndef DEF_MST3
#define DEF_MST3

#include "../Entite.h"

class Monstre3 : public Entite
{
public:

	/**
	 * \brief Construit un Monstre
	 * \param x la position x du monstre
	 * \param y la position y du monstre
	*/
	Monstre3(int x, int y);
	
	
	/**
	 * \brief action monstre en fonction du joueur
	 * \param j le joueur
	*/
	void actions(Entite* j);
};
#endif
