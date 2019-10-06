#include "tir.h"

class Joueur
{
public:
	sf::Texture perso;
	sf::Sprite sperso;

	Joueur() {
		vie = 20;
		armure = 0;
		arme = "baton";
		degats = 3;
		sens=0;
		if (!perso.loadFromFile("/home/chocolat/Bureau/progtest/sprites/sprite.png")) {
			std::cout << "erreur" << std::endl;
		}
		perso.setSmooth(true);
		sperso.setTexture(perso);
		sperso.setTextureRect(sf::IntRect(32, 0, 32, 32));
		sperso.setPosition(256, 128);

	}
	void nbdegats(int nb) {
		vie -= nb - armure;
	}
	void atk(Joueur &monstre) {
		monstre.nbdegats(degats);
	}
	void armes(std::string nom, int dgt) {
		arme = nom;
		degats = dgt;
	}
	bool mort() const {
		return vie > 0;
	}
	void actions() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sperso.move(0, -0.1);
			sperso.setTextureRect(sf::IntRect(32 * x, 96, 32, 32));
			x++;
			sens=0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			sperso.move(0, 0.1);
			sperso.setTextureRect(sf::IntRect(32 * x, 0, 32, 32));
			x++;
			sens=1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			sperso.move(-0.1, 0);
			sperso.setTextureRect(sf::IntRect(32 * x, 32, 32, 32));
			x++;
			sens=2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			sperso.move(0.1, 0);
			sperso.setTextureRect(sf::IntRect(32 * x, 64, 32, 32));
			x++;
			sens=3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			tir[j].setpd(sperso.getPosition().x, sperso.getPosition().y, sens);
			j++;
			if(j>=9){
				j=0;
			}
		}
		if (x > 2) {
			x = 0;
		}
		if ((sperso.getPosition().x > 512) || (sperso.getPosition().x < 0) || (sperso.getPosition().y > 256) || (sperso.getPosition().y < 0)) {
			sperso.setPosition(256, 128);
		}
		for(int i=0; i<10; i++){
			tir[i].actions();
		}
	}
	sf::Sprite gettir(){
		for(int i=0; i<10; i++){
				return tir[i].stir;
		}
	}

private:

	int j=0;
	int x = 0;
	int vie;
	int armure;
	std::string arme;
	int degats;
	Tir tir[10];
	int sens;

};
