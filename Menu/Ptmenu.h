#ifndef DEF_PM
#define DEF_PM

#include "Menu.h"

class Ptmenu : public Menu
{
public:

  /**
   * \brief Construit le menu
   * \param x la longueur de la fenetre
   * \param y la hauteur de la fenetre
   */
  Ptmenu(int x, int y);

  void handleMenu();
};
#endif
