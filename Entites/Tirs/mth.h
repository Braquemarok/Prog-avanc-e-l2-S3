#ifndef DEF_MATH
#define DEF_MATH

#include <math.h>

/**
 * \brief Calcule la distance entre deux points
 * \param x la position x du point 1
 * \param y la position y du point 1
 * \param z la position x du point 2
 * \param t la position y du point 2
 * \return la distance entre deux points
*/
double distance( int x, int y, int z, int t);

/**
 * \brief Détermine le mur touché par l'entité
 * \param x la position x de l'entite
 * \param y la position y du l'entite
 * \return le mur touché par l'entité
*/
double mur(int x, int y);

#endif
