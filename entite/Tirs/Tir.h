#ifndef DEF_TIR
#define DEF_TIR

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Tir
{
public:

	Tir(int z);
	//action du tir
	virtual void actions()=0;

	void setdead();
	//getters
	sf::Sprite getSprite();
	bool done();

protected:

	int degats;
  int sens;
	int longueur;
	bool ded=false;
	int vitesse;
	sf::Texture tir;
	sf::Sprite stir;
};

#endif
