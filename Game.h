#ifndef DEF_G
#define DEF_G

#include <iostream>
#include <fstream>
#include <string>
#include "World.h"
#include "Menu/Menu.h"
#include "Menu/MainMun.h"
#include "Menu/Ptmenu.h"
#include "Save.h"

class Game
{
public:
	//constructeur
  Game();
  void play();
  void draw();
  void drawm(Menu* mm);
  ~Game();

private:
  World* world;
  Menu* menu;
  Menu* mmenu;
	sf::RenderWindow window;

};
#endif
