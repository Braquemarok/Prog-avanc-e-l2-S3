#ifndef DEF_MST
#define DEF_MST

#include "../Entite.h"

class Monstre : public Entite
{
public:

	/**
	 * \brief Construit un Monstre
	 * \param x la position x du monstre
	 * \param y la position y du monstre
	*/
	Monstre(int x, int y);

	/**
	 * \brief action monstre en fonction du joueur
	 * \param j le joueur
	*/
	void actions(Entite* j);
};
#endif
