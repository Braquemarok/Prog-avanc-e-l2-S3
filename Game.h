#ifndef DEF_G
#define DEF_G

#include <iostream>
#include <fstream>
#include <string>
#include "World.h"
#include "Menu/Menu.h"
#include "Menu/MainMun.h"
#include "Menu/Ptmenu.h"
#include "Menu/Lvend.h"
#include "Menu/GameO.h"
#include "Save.h"

class Game
{
public:

  //constructeur

  /**
   * \brief Construit le jeu
   */
  Game();

  /**
   * \brief Lance le jeu
   */
  void play();

  /**
   * \brief Dessine le jeu dans la fenetre
   */
  void draw();

  /**
   * \brief Dessine le menu dans la fenetre
   * \param mm le menu à dessiner
   */
  void drawm(Menu* mm);
  ~Game();

private:

  World* world;
  Menu* menu;
  Menu* mmenu;
  int nblv;
	sf::RenderWindow window;
};
#endif
