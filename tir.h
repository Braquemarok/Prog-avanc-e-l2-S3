class Tir
{
public:
	sf::Texture tir;
	sf::Sprite stir;
  Tir() {
    if (!tir.loadFromFile("/home/chocolat/Bureau/progtest/sprites/sprite.png")) {
			std::cout << "erreur" << std::endl;
		}
		tir.setSmooth(true);
		stir.setTexture(tir);
		stir.setTextureRect(sf::IntRect(32, 0, 32, 32));
		stir.setPosition(-32, -32);
    sens=-1;

	}
	void setpd(int x, int y, int z) {
		stir.setPosition(x, y);
    sens=z;

	}
	void actions() {
		if (sens==0) {
			stir.move(0, -0.5);
			x++;
		}
		if (sens==1) {
			stir.move(0, 0.5);
			x++;
		}
		if (sens==2) {
			stir.move(-0.5, 0);
			x++;
		}
		if (sens==3) {
			stir.move(0.5, 0);
			x++;
		}
		if (x > 2) {
			x = 0;
		}
	}
  bool colli(int x, int y){
    return false;
  }

private:

	int x = 0;
	int degats;
  int sens;

};
