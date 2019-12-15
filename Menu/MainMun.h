#ifndef DEF_MM
#define DEF_MM

#include "Menu.h"

class MainMun : public Menu
{
public:

  /**
   * \brief Construit le menu
   * \param x la longueur de la fenetre
   * \param y la hauteur de la fenetre
   */
  MainMun(int x, int y);
  
  void handleMenu();
};
#endif
