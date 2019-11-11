#ifndef DEF_MST
#define DEF_MST

#include "../Entite.h"

class Monstre : public Entite
{
public:

	Monstre(int x, int y) : Entite() {
		vie=1;
		if (!perso.loadFromFile("sprites/monster1.png")) {
			std::cout << "erreur" << std::endl;
		}
		perso.setSmooth(true);
		sperso.setTexture(perso);
		sperso.setTextureRect(sf::IntRect(32, 0, 32, 32));
		sperso.setPosition(x, y);

	}
	//action monstre en fonction du joueur
	void actions(Joueur j, int clock) {
		if (j.getEntite().getPosition().y < sperso.getPosition().y) {
			sperso.move(0, -3);
			sperso.setTextureRect(sf::IntRect(32 * x, 96, 32, 32));
			//x++;
		}
		if (j.getEntite().getPosition().y > sperso.getPosition().y) {
			sperso.move(0, 3);
			sperso.setTextureRect(sf::IntRect(32 * x, 0, 32, 32));
			//x++;
		}
		if (j.getEntite().getPosition().x < sperso.getPosition().x) {
			sperso.move(-3, 0);
			sperso.setTextureRect(sf::IntRect(32 * x, 32, 32, 32));
			//x++;
		}
		if (j.getEntite().getPosition().x > sperso.getPosition().x) {
			sperso.move(3, 0);
			sperso.setTextureRect(sf::IntRect(32 * x, 64, 32, 32));
			//x++;
		}
		if (clock > 2) {
			x = 0;
		}
		if ((sperso.getPosition().x > 512) || (sperso.getPosition().x < 0) || (sperso.getPosition().y > 256) || (sperso.getPosition().y < 0)) {
			sperso.setPosition(256, 128);
		}
	}
};
#endif
