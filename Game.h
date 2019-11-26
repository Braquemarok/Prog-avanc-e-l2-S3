#ifndef DEF_G
#define DEF_G

#include <iostream>
#include <string>
#include "World.h"
#include "Menu.h"

class Game
{
public:
	//constructeur
  Game();
  void play();
  void draw();
  void drawm();

private:
  World* world;
  Menu menu;
	sf::RenderWindow window;

};
#endif
