#ifndef DEF_G
#define DEF_G

#include <iostream>
#include <string>
#include "World.h"

class Game
{
public:
	//constructeur
  Game();
  void play();
  void draw();

private:
  World world;
	sf::RenderWindow window;

};
#endif
