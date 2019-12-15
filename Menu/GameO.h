#ifndef DEF_GO
#define DEF_GO

#include "Menu.h"

class GameO : public Menu
{
public:

  /**
   * \brief Construit le menu
   * \param x la longueur de la fenetre
   * \param y la hauteur de la fenetre
   */
  GameO(int x, int y);

  void handleMenu();
};
#endif
