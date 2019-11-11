#ifndef DEF_TIR
#define DEF_TIR

class Tir
{
public:

	Tir(int z) {

    sens=z;
		degats=10;
		longueur=300;
		vitesse=10;
	}
	//action du tir
	virtual void actions()=0;
	
	void setdead(){
		ded=true;
	}
	//getters
	sf::Sprite getSprite(){
		return stir;
	}
	bool done(){
		return ded;
	}

protected:

	int degats;
  int sens;
	int longueur;
	bool ded=false;
	int vitesse;
	sf::Texture tir;
	sf::Sprite stir;
};

#endif
