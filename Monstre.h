class Monstre
{
public:
	sf::Texture perso;
	sf::Sprite sperso;

	Monstre() {
		vie = 20;
		armure = 0;
		arme = "baton";
		degats = 3;
		if (!perso.loadFromFile("sprites/sprite.png")) {
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
	void actions(Joueur j) {
		if (j.sperso.getPosition().y < sperso.getPosition().y) {
			sperso.move(0, -0.01);
			sperso.setTextureRect(sf::IntRect(32 * x, 96, 32, 32));
			x++;
		}
		if (j.sperso.getPosition().y > sperso.getPosition().y) {
			sperso.move(0, 0.01);
			sperso.setTextureRect(sf::IntRect(32 * x, 0, 32, 32));
			x++;
		}
		if (j.sperso.getPosition().x < sperso.getPosition().x) {
			sperso.move(-0.01, 0);
			sperso.setTextureRect(sf::IntRect(32 * x, 32, 32, 32));
			x++;
		}
		if (j.sperso.getPosition().x > sperso.getPosition().x) {
			sperso.move(0.01, 0);
			sperso.setTextureRect(sf::IntRect(32 * x, 64, 32, 32));
			x++;
		}
		if (x > 2) {
			x = 0;
		}
		if ((sperso.getPosition().x > 512) || (sperso.getPosition().x < 0) || (sperso.getPosition().y > 256) || (sperso.getPosition().y < 0)) {
			sperso.setPosition(256, 128);
		}
	}

private:

	int x = 0;
	int vie;
	int armure;
	std::string arme;
	int degats;

};
