#ifndef DEF_ENTITE
#define DEF_ENTITE

#include <iostream>
#include "Tirs/Tir.h"
#include "Tirs/Tir1.h"
#include "Tirs/Tir2.h"
#include "Animation.h"

class Entite
{
public:

	Entite() ;
	bool mort() const ;
	int getdegat();
	//detection collision plus degat si vrai
	void damage(Tir* m, int x);
  	void damage(sf::Sprite m, int x);
	//action du joueur
  	virtual void actions(int clock);
  	//action monstre en fonction du joueur
	virtual void actions(Entite j, int clock);
	//getters
  	sf::Sprite getEntite();
	sf::Sprite getstir(int i);
	int gettaillet();
	Tir* getTir(int i);

protected:

	sf::Texture perso;
	sf::Sprite sperso;
	int vie;
	int degats;
  	int x = 0;
	int y=96;
	int sens;
	std::vector<Tir*> tirs;

};
#endif
