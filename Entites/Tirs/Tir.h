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

	Tir(int z,int v);
	//action du tir
	virtual void actions();
	void collision(const int* tiles, unsigned int width, unsigned int height);
	void setdead();
	//getters
	sf::Sprite getSprite();
	sf::Sprite* getSTir();
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
