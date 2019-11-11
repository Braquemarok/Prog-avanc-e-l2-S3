#ifndef DEF_ENTITE
#define DEF_ENTITE

class Entite
{
public:

	Entite() {
		vie = 2000;
		degats = 3;

	}
	bool mort() const {
		return vie <= 0;
	}
	int getdegat(){
		return degats;
	}
	//detection collision plus degat si vrai
	void damage(Tir* m, int x){
		sf::FloatRect boundingBox = sperso.getGlobalBounds();
		sf::FloatRect otherBox = m->getSprite().getGlobalBounds();
		if (boundingBox.intersects(otherBox))
		{
    	vie-=x;
			m->setdead();
		}
	}
  void damage(sf::Sprite m, int x){
		sf::FloatRect boundingBox = sperso.getGlobalBounds();
		sf::FloatRect otherBox = m.getGlobalBounds();
		if (boundingBox.intersects(otherBox))
		{
    	vie-=x;
		}
	}
	//action du joueur
  virtual void actions(int clock){
    Tir* tir;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock%200<=17) {
			//action de tir
			tir= new Tir1(sperso.getPosition().x, sperso.getPosition().y, sens);
			tirs.push_back(tir);
		}
  }
  //action monstre en fonction du joueur
	virtual void actions(Entite j, int clock){
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

	//getters
  sf::Sprite getEntite(){
		return sperso;
	}
	sf::Sprite getstir(int i){
		return tirs[i]->getSprite();
	}
	int gettaillet(){
		return tirs.size();
	}
	Tir* getTir(int i){
		return tirs[i];
	}


protected:
	sf::Texture perso;
	sf::Sprite sperso;
	int vie;
	int degats;
  int x = 0;
	int y=96;
	int sens;
	std::vector<Tir*> tirs;

};
#endif
