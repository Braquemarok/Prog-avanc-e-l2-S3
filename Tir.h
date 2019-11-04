class Tir
{
public:
	sf::Texture tir;
	sf::Sprite stir;
  Tir() {
    if (!tir.loadFromFile("sprites/sprite.png")) {
			std::cout << "erreur" << std::endl;
		}
		tir.setSmooth(true);
		stir.setTexture(tir);
		stir.setTextureRect(sf::IntRect(32, 0, 32, 32));
		stir.setPosition(-32, -32);
		nbtir=10;
		degats=10;
    sens=-1;
		longueur=300;

	}
	Tir(int x, int y, int z) {
    if (!tir.loadFromFile("sprites/sprite.png")) {
			std::cout << "erreur" << std::endl;
		}
		tir.setSmooth(true);
		stir.setTexture(tir);
		stir.setTextureRect(sf::IntRect(32, 0, 32, 32));
		stir.setPosition(x, y);
    sens=z;
		degats=10;
		nbtir=10;
		longueur=300;
	}
	//action du tir
	void actions() {
		if (sens==0) {
			stir.move(0, -7);
		}
		if (sens==1) {
			stir.move(0, 7);
		}
		if (sens==2) {
			stir.move(-7, 0);
		}
		if (sens==3) {
			stir.move(7, 0);
		}
		longueur-=7;
		if(longueur<=0){
			setdead();
		}
	}
	void setdead(){
		ded=true;
	}
	//getters
	sf::Sprite getSprite(){
		return stir;
	}
	int getnbtir(){
		return nbtir;
	}
	bool done(){
		return ded;
	}

private:

	int degats;
  int sens;
	int nbtir;
	int longueur;
	bool ded=false;

};
