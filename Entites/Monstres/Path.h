#ifndef DEF_PATH
#define DEF_PATH

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

/**
 * \brief Calcule la distance entre le monstre et le joueur
 * \param x1 la position x du monstre
 * \param y1 la position y du monstre
 * \param x2 la position x du joueur
 * \param y2 la position y du joueur
 * \return la distance entre le monstre et le joueur
*/
int calcG(int x1, int y1, int x2, int y2);

/**
 * \brief Calcule le nombre de coups pour atteindre la tile du joueur
 * \param t la map
 * \param x1 la position x du monstre
 * \param y1 la position y du monstre
 * \param x2 la position x du joueur
 * \param y2 la position y du joueur
 * \param l la longueur de la map
 * \param h la hauteur de la map
 * \return Renvoie le nombre de coups pour atteindre la tile du joueur
*/
int calcH(int** t, int x1,int x2, int y1, int y2, int l, int h);

/**
 * \brief Renvoie le chemin pour atteindre le joueur
 * \param t la map
 * \param x1 la position x du monstre
 * \param y1 la position y du monstre
 * \param x2 la position x du joueur
 * \param y2 la position y du joueur
 * \param l la longueur de la map
 * \param h la hauteur de la map
 * \return Renvoie le chemin pour atteindre le joueur
*/
int pathExists(int** t, int x1,int x2, int y1, int y2, int l, int h);

#endif
