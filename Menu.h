#ifndef DEF_MENU
#define DEF_MENU

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Menu
{
public:

  Menu();
  void handleMenu();
  bool isMenuOver();
  sf::Text getText(int i);
  void setMenu();
  int getOpt();

private:

  bool over=false;
  sf::Text text[4];
  sf::Font font;
  int option=0;

};

#endif
