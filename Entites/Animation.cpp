#include "Animation.h"

using namespace std;

void animation( sf::Sprite* sprite, int* anim, int sens ){
  
  sf::Sprite sprit = *sprite;
  int a = *anim;

  switch(sens){
    
    case 0:
      sprit.setTextureRect(sf::IntRect(64 * a, 0, 64, 64));
    break;

    case 1:
      sprit.setTextureRect(sf::IntRect(64 * a, 64, 64, 64));
    break;

    case 2:
      sprit.setTextureRect(sf::IntRect(64 * a, 128, 64, 64));
    break;

    case 3:
      sprit.setTextureRect(sf::IntRect(64 * a, 192, 64, 64));
    break;
  }
  
  a++;

  if ( a > 3) {
    
    a = 0;
  }

  *sprite = sprit;
  *anim = a;
}

void rotation( sf::Sprite* canon, double cursorx, double cursory ){

  sf::Sprite can = *canon;

  double direction =(can.getPosition().y-cursory)/(can.getPosition().x-cursorx);

  double angle = fmod(atan(direction)-atan(can.getPosition().y),PI)*180/PI;

  if( can.getPosition().x-cursorx < 0 ){

    angle -= 180;
  }

  printf("%lf\n",angle);

  can.setRotation(angle);
  
  *canon = can;
}