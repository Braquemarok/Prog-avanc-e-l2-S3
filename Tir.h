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
		degats=10;
    sens=-1;

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
	}

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
	}
	sf::Sprite getSprite(){
		return stir;
	}
	int getnbtir(){
		return nbtir;
	}
	int gettimer(){
		return timer;
	}
  /*bool colli(int x, int y){
    return false;
  }*/

private:

	int degats;
  int sens;
	int nbtir=1000;
	int timer=500;

};
