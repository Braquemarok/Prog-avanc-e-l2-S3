#ifndef DEF_TIR2
#define DEF_TIR2

#include "Tir.h"

class Tir2 : public Tir
{
public:

	Tir2(int x, int y, int z) : Tir(z){
		if (!tir.loadFromFile("sprites/sprite.png")) {
			std::cout << "erreur" << std::endl;
		}
		tir.setSmooth(true);
		stir.setTexture(tir);
		stir.setTextureRect(sf::IntRect(32, 0, 32, 32));
		stir.setPosition(x, y);
		degats=10;
		longueur=500;
		vitesse=15;
	}
	void actions(){
		if (sens==0) {
			stir.move(0, -vitesse);
		}
		if (sens==1) {
			stir.move(0, vitesse);
		}
		if (sens==2) {
			stir.move(-vitesse, 0);
		}
		if (sens==3) {
			stir.move(vitesse, 0);
		}
		longueur-=vitesse;
		if(longueur<=0){
			setdead();
		}
	}
};
#endif