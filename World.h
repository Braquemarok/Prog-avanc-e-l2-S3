#ifndef DEF_W
#define DEF_W

#include <string.h>
#include "Entites/Joueur/Joueur.h"
#include "Entites/Monstres/Monstre.h"
#include "Entites/Monstres/Monstre2.h"
#include "Entites/Monstres/Monstre3.h"
#include "Entites/Monstres/Monstre4.h"
#include "Entites/Monstres/Monstre5.h"
#include "Entites/Monstres/Monstre6.h"
#include "Entites/Monstres/Monstre7.h"
#include "Sound.h"
#include "Map.h"
#include "Lecteur.h"

class World{

public:

	/**
	 * \brief Construit le monde
	 * \param num le numéro du niveau
	 */
  World(int num);

  /**
	 * \brief Construit le monde
	 * \param s la sauvegarde
	 */
  World(string s);

  /**
	 * \brief Gère les évènements du monde
	 * \param x la position x du curseur
   * \param y la position y du curseur
	 */
  void handlevent(int x, int y);

  /**
	 * \brief Retourne le sprite du mob i
	 * \param i le mob à la position i
   * \return le sprite du mob i
	 */
  sf::Sprite spriteMob(int i);

  /**
	 * \brief Retourne le sprite du canon du mob i
	 * \param i le mob à la position i
   * \return le sprite du canon du mob i
	 */
  sf::Sprite spriteMcanon(int i);

  /**
	 * \brief Retourne le nombre de mobs
   * \return le nombre de mobs
	 */
  int nbMobs();

  /**
	 * \brief Retourne le sprite du joueur
   * \return le sprite du joueur
	 */
  sf::Sprite spritePlayer();

  /**
	 * \brief Retourne le sprite du canon du joueur
   * \return le sprite du canon du joueur
	 */
  sf::Sprite spritePcanon();

  /**
	 * \brief Retourne le sprite du tir du joueur
	 * \param i la position du tir dans la liste
   * \return le sprite du tir du joueur
	 */
  sf::Sprite st(int i);

  /**
	 * \brief Retourne le sprite du tir du mob à la position i
   * \param i le mob à la position i
	 * \param j la position du tir dans la liste
   * \return le sprite du tir du mob à la position i
	 */
  sf::Sprite sm(int i, int j);

  /**
	 * \brief Retourne la map
   * \return la map
	 */
  TileMap getMap();

  /**
	 * \brief Retourne la taille de la liste de tir du joueur
   * \return la taille de la liste de tir du joueur
	 */
  int je();

  /**
	 * \brief Retourne la taille de la liste de tir du mob à la position i
   * \param i le mob à la position i
   * \return la taille de la liste de tir du mob à la position i
	 */
  int me(int i);

  /**
	 * \brief Retourne l'état du jeu
   * \return vrai si le jeu est fini, faux sinon
	 */
  bool isgameover();

  /**
	 * \brief Retourne l'entité Joueur
   * \return l'entité Joueur
	 */
  Joueur* getPlayer();

  /**
	 * \brief Retourne la hauteur de la map
   * \return la hauteur de la map
	 */
  int geth();

  /**
	 * \brief Retourne la largeur de la map
   * \return la largeur de la map
	 */
  int getl();

  /**
	 * \brief Retourne une tile du niveau
   * \return une tile du niveau du niveau
	 */
  int getlv(int i);

  /**
	 * \brief Retourne le type du mob à la position i
   * \param i le mob à la position i
   * \return le type du mob à la position i
	 */
  int getMT(int i);
  
  ~World();

private:

	Joueur* j;
  List<Entite> m;
  int nbmonstre;
	TileMap map;
  int* level;
  int height;
  int length;
  bool gameover;
};

#endif
