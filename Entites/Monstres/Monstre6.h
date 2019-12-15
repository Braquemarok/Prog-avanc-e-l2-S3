#ifndef DEF_MST6
#define DEF_MST6

#include "../Entite.h"


class Monstre6 : public Entite
{
public:

	/**
	 * \brief Construit un Monstre
	 * \param x la position x du monstre
	 * \param y la position y du monstre
	*/
	Monstre6(int x, int y);
	
	/**
	 * \brief action monstre en fonction du joueur
	 * \param j le joueur
	 * \param map la map
	 * \param h la hauteur de la map
	 * \param l la longueur de la map
	*/
	void actions(Entite* j, int* map, int h, int l);
};
#endif
