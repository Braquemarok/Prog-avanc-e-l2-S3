#ifndef DEF_TIR
#define DEF_TIR

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "mth.h"
#define TSIZE 64

class Tir
{
public:

	/**
	 * \brief Construit un Tir
	 * \param z la position x de ce que l'on vise
	 * \param v la position y de ce que l'on vise
	*/
	Tir(int z,int v);

	/**
	 * \brief Actions du Tir
	*/
	virtual void actions();

	/**
	 * \brief Construit un Tir
	 * \param tiles le tileset (map)
	 * \param witdh la largeur de la map
	 * \param height la hauteur de la map
	*/
	void collision(const int* tiles, unsigned int width, unsigned int height);

	/**
	 * \brief Défini un tir comme mort
	*/
	void setdead();

	//getters

	/**
	 * \brief Renvoie le sprite du tir
	 * \return le sprite du tir
	 */
	sf::Sprite getSprite();

	/**
	 * \brief Renvoie le sprite du tir
	 * \return le sprite du tir
	 */
	sf::Sprite* getSTir();

	/**
	 * \brief Défini l'état d'un tir
	 * \return l'état d'un tir
	 */
	bool done();
	
	virtual ~Tir();

protected:

	int degats;
  	int sens;
	int longueur;
	bool ded=false;
	int vitesse;
	sf::Texture tir;
	sf::Sprite stir;
	int t;
	int u;
	int mousex;
	int mousey;
};

#endif
