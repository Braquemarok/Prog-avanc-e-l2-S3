#ifndef DEF_JOUEUR
#define DEF_JOUEUR

#include "../Entite.h"

class Joueur : public Entite
{
public:
	//constructeur

	/**
	 * \brief Construit Joueur
	 */
	Joueur();
	
	/**
	 * \brief Construit Joueur
	 * \param x la position x du monstre
	 * \param y la position y du monstre
	*/
	Joueur(int x, int y);
};
#endif
