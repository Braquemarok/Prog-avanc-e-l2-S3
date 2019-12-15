#ifndef ANIM_H
#define ANIM_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h> 

#define PI 3.14159265

/**
 * \brief Anime un tank
 * \param sprite le sprite à animer
 * \param anim l'état d'animation
 * \param sens le sens du sprite
*/
void animation( sf::Sprite* sprite, int* anim, int sens );

/**
 * \brief Anime le canon d'un tank
 * \param canon le canon à animer
 * \param cursorx la position x de ce que l'on vise
 * \param cursory la position y de ce que l'on vise
*/
void rotation( sf::Sprite* canon, double cursorx, double cursory );

#endif
