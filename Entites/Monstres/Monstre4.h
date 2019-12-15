#ifndef DEF_MST4
#define DEF_MST4

#include "../Entite.h"

class Monstre4 : public Entite
{
public:

	/**
	 * \brief Construit un Monstre
	 * \param x la position x du monstre
	 * \param y la position y du monstre
	*/
	Monstre4(int x, int y);
	
	
	/**
	 * \brief action monstre en fonction du joueur
	 * \param j le joueur
	*/
	void actions(Entite* j);
};
#endif
