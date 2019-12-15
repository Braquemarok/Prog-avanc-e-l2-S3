#ifndef DEF_MENU
#define DEF_MENU

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Menu
{
public:

  Menu(int x, int y);
  virtual void handleMenu();
  bool isMenuOver();
  sf::Text getText(int i);
  sf::Sprite getfond();
  void setMenu();
  int getOpt();
  virtual ~Menu();

protected:

  bool over=false;
  sf::Text text[4];
  sf::Font font;
  int option=0;
  sf::Clock* clock;
  sf::Texture fond;
  sf::Sprite sfond;
};

#endif
