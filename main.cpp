#ifndef DEF_MAIN
#define DEF_MAIN

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "Game.h"

int main()
{
	Game* game= new Game();
	game->play();
	return 0;
}
#endif
