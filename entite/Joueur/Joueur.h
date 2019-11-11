#ifndef DEF_JOUEUR
#define DEF_JOUEUR

#include "../Tirs/Tir1.h"
#include "../Tirs/Tir2.h"
#include "../Entite.h"
#include <vector>

class Joueur : public Entite
{
public:
	//constructeur
	Joueur() : Entite(){
		arme = "baton";
		sens=0;
		if (!perso.loadFromFile("sprites/sprite.png")) {
			std::cout << "erreur" << std::endl;
		}
		perso.setSmooth(true);
		sperso.setTexture(perso);
		sperso.setTextureRect(sf::IntRect(32, 0, 32, 32));
		sperso.setPosition(256, 128);
	}

	//action du joueur
	void actions(int clock) {
		Tir* tir;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sens=0;
			y=96;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			sens=1;
			y=0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			sens=2;
			y=32;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			sens=3;
			y=64;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			sperso.move(5, 0);
			x++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			sperso.move(-5, 0);
			x++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			sperso.move(0, -5);
			x++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			sperso.move(0, 5);
			x++;
		}

		sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock%200<=17) {
			//action de tir
			tir= new Tir1(sperso.getPosition().x, sperso.getPosition().y, sens);
			tirs.push_back(tir);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && clock%200<=17) {
			//action de tir
			tir= new Tir2(sperso.getPosition().x, sperso.getPosition().y, sens);
			tirs.push_back(tir);
		}
		if (x > 2) {
			x = 0;
		}
		if ((sperso.getPosition().x > 512) || (sperso.getPosition().x < 0) || (sperso.getPosition().y > 256) || (sperso.getPosition().y < 0)) {
			sperso.setPosition(256, 128);
		}
		for(unsigned int i=0; i<tirs.size(); i++){
			tirs[i]->actions();
			if(tirs[i]->done()){
				tirs.erase(tirs.begin()+i);
			}
		}
	}

private:

	int armure;
	std::string arme;

};
#endif
