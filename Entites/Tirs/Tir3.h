#ifndef DEF_TIR3
#define DEF_TIR3

#include "Tir.h"

class Tir3 : public Tir
{
public:

	/**
	 * \brief Construit un Tir
	 * \param x la position x de départ du tir
	 * \param y la position y de départ du tir
	 * \param z la position x de ce que l'on vise
	 * \param v la position y de ce que l'on vise
	*/
	Tir3(int x, int y, int z, int v);
};
#endif
