#ifndef ANIM_H
#define ANIM_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h> 

#define PI 3.14159265

void animation( sf::Sprite* sprite, int* anim, int sens );
void rotation( sf::Sprite* canon, double cursorx, double cursory );

#endif
