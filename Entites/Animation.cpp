#include "Animation.h"

using namespace std;

void animation( sf::Sprite* sprite, int* anim, int sens ){
  
  sf::Sprite sprit = *sprite;

  switch(sens){
    
    case 0:
      sprit.setTextureRect(sf::IntRect(64 * *anim, 0, 64, 64));
    break;

    case 1:
      sprit.setTextureRect(sf::IntRect(64 * *anim, 64, 64, 64));
    break;

    case 2:
      sprit.setTextureRect(sf::IntRect(64 * *anim, 128, 64, 64));
    break;

    case 3:
      sprit.setTextureRect(sf::IntRect(64 * *anim, 192, 64, 64));
    break;
  }

  *sprite = sprit;
  
  int a = *anim;

  a++;

  if ( a > 3) {
    
    a = 0;
  }

  *anim = a;
}

void rotation( sf::Sprite* canon ){


}