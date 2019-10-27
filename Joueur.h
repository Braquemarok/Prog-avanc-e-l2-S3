#include "Tir.h"
#include <vector>

class Joueur
{
public:
	//constructeur
	Joueur() {
		vie = 2000;
		armure = 0;
		arme = "baton";
		degats = 3;
		sens=0;
		Tir tir;
		tirs.push_back(&tir);
		nbtir=tirs[0]->getnbtir();
		if (!perso.loadFromFile("sprites/sprite.png")) {
			std::cout << "erreur" << std::endl;
		}
		perso.setSmooth(true);
		sperso.setTexture(perso);
		sperso.setTextureRect(sf::IntRect(32, 0, 32, 32));
		sperso.setPosition(256, 128);
	}
	//degat recus
	void nbdegats(int nb) {
		vie -= nb - armure;
	}
	void armes(std::string nom, int dgt) {
		arme = nom;
		degats = dgt;
	}
	bool mort() const {
		return vie <= 0;
	}
	int getdegat(){
		return degats;
	}
	//detection collision plus degat si vrai
	void damage(sf::Sprite m, int x){
		sf::FloatRect boundingBox = sperso.getGlobalBounds();
		sf::FloatRect otherBox = m.getGlobalBounds();
		if (boundingBox.intersects(otherBox))
		{
    	nbdegats(x);
		}
	}
	//action du joueur
	void actions() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sperso.move(0, -5);
			sperso.setTextureRect(sf::IntRect(32 * x, 96, 32, 32));
			x++;
			sens=0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			sperso.move(0, 5);
			sperso.setTextureRect(sf::IntRect(32 * x, 0, 32, 32));
			x++;
			sens=1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			sperso.move(-5, 0);
			sperso.setTextureRect(sf::IntRect(32 * x, 32, 32, 32));
			x++;
			sens=2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			sperso.move(5, 0);
			sperso.setTextureRect(sf::IntRect(32 * x, 64, 32, 32));
			x++;
			sens=3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			//action de tir
			if(j<nbtir){
				Tir* tir= new Tir(sperso.getPosition().x, sperso.getPosition().y, sens);
				tirs.push_back(tir);
				j++;
			}
			else{
				tirs.erase(tirs.begin());
				j--;
			}
		}
		if (x > 2) {
			x = 0;
		}
		if ((sperso.getPosition().x > 512) || (sperso.getPosition().x < 0) || (sperso.getPosition().y > 256) || (sperso.getPosition().y < 0)) {
			sperso.setPosition(256, 128);
		}
		for(int i=0; i<j; i++){
			tirs[i]->actions();
		}
	}
	//getters
	sf::Sprite getsperso(){
		return sperso;
	}
	sf::Sprite getstir(int i){
		return tirs[i]->getSprite();
	}
	int gettaillet(){
		return j;
	}

private:

	int j=1;
	int x = 0;
	int vie;
	int armure;
	std::string arme;
	int degats;
	int sens;
	std::vector<Tir*> tirs;
	int nbtir;
	sf::Texture perso;
	sf::Sprite sperso;
};
