#ifndef DEF_MENU
#define DEF_MENU

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Menu
{
public:

  /**
   * \brief Construit le menu
   * \param x la longueur de la fenetre
   * \param y la hauteur de la fenetre
   */
  Menu(int x, int y);

  virtual void handleMenu();

  /**
   * \brief Renvoie si le menu est fermé ou non
   * \return le menu est fermé ou non 
   */
  bool isMenuOver();

  /**
   * \brief Renvoie le texte du menu
   * \return le texte du menu
   */
  sf::Text getText(int i);

  /**
   * \brief Renvoie le fond du menu
   * \return le fond du menu
   */
  sf::Sprite getfond();

  /**
   * \brief Définie le menu
   */
  void setMenu();

  /**
   * \brief Renvoie l'option du menu
   * \return l'option du menu
   */
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
