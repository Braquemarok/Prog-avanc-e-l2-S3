#ifndef DEF_LV
#define DEF_LV

#include "Menu.h"

class Lvend : public Menu
{
public:

  /**
   * \brief Construit le menu
   * \param x la longueur de la fenetre
   * \param y la hauteur de la fenetre
   */
  Lvend(int x, int y);
  
  void handleMenu();
};
#endif
