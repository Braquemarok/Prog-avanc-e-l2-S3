#ifndef DEF_ENTITE
#define DEF_ENTITE

#include <iostream>
#include "Tirs/Tir.h"
#include "Tirs/Tir1.h"
#include "Tirs/Tir2.h"
#include "../List.cpp"
#include "Animation.h"
#include "Tirs/mth.h"

class Entite
{
public:

	Entite() ;
	Entite(int v) ;
	bool mort() const ;
	int getdegat();
	//detection collision plus degat si vrai
	void damage(Tir* m, int x);
  	void damage(sf::Sprite m, int x);
	void collision(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	void collision(sf::Sprite m);
	//action du joueur
  	virtual void actions();
	virtual void actions( int z, int t);
  	//action monstre en fonction du joueur
	virtual void actions(Entite* j, int h, int l);

	//getters
  	sf::Sprite getEntite();
	sf::Sprite getCanon();
	sf::Sprite getstir(int i);
	int gettaillet();
	Tir* getTir(int i);
	int getAlive();
	int getType();
	~Entite();

protected:

	sf::Texture perso;
	sf::Texture canon;
	sf::Sprite sperso;
	sf::Sprite scanon;
	bool alive;
	int type;
	int degats;
	int anim = 0;
	int sens;
	sf::Clock* clock;
	List<Tir> tirs;

};
#endif
