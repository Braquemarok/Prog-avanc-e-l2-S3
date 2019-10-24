class Monstre
{
public:

	Monstre() {
		vie = 20;
		armure = 0;
		degats = 3;
		if (!perso.loadFromFile("sprites/sprite.png")) {
			std::cout << "erreur" << std::endl;
		}
		perso.setSmooth(true);
		sperso.setTexture(perso);
		sperso.setTextureRect(sf::IntRect(32, 0, 32, 32));
		sperso.setPosition(256, 128);

	}
	Monstre(int x, int y) {
		vie = 20;
		armure = 0;
		degats = 3;
		if (!perso.loadFromFile("sprites/sprite.png")) {
			std::cout << "erreur" << std::endl;
		}
		perso.setSmooth(true);
		sperso.setTexture(perso);
		sperso.setTextureRect(sf::IntRect(32, 0, 32, 32));
		sperso.setPosition(x, y);

	}
	bool mort() const {
		return vie <= 0;
	}
	int getdegat(){
		return degats;
	}
	void damage(sf::Sprite m, int x){
		sf::FloatRect boundingBox = sperso.getGlobalBounds();
		sf::FloatRect otherBox = m.getGlobalBounds();
		if (boundingBox.intersects(otherBox))
		{
    	vie-=x;
		}
	}
	void actions(Joueur j) {
		if (j.getsperso().getPosition().y < sperso.getPosition().y) {
			sperso.move(0, -3);
			sperso.setTextureRect(sf::IntRect(32 * x, 96, 32, 32));
			x++;
		}
		if (j.getsperso().getPosition().y > sperso.getPosition().y) {
			sperso.move(0, 3);
			sperso.setTextureRect(sf::IntRect(32 * x, 0, 32, 32));
			x++;
		}
		if (j.getsperso().getPosition().x < sperso.getPosition().x) {
			sperso.move(-3, 0);
			sperso.setTextureRect(sf::IntRect(32 * x, 32, 32, 32));
			x++;
		}
		if (j.getsperso().getPosition().x > sperso.getPosition().x) {
			sperso.move(3, 0);
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
	sf::Sprite getsmonstre(){
		return sperso;
	}

private:
	sf::Texture perso;
	sf::Sprite sperso;
	int x = 0;
	int vie;
	int armure;
	int degats;

};
