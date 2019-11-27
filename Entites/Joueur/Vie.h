#ifndef DEF_VIE
#define DEF_VIE

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <string>

class Vie
{
public:
	//constructeur
	Vie();
  void handlevie(int nbvie);
  sf::Text getText();

private:

  sf::Text text;
  sf::Font font;

};
#endif
