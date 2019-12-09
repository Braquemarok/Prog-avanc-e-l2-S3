#include "Animation.h"

using namespace std;

void animation( sf::Sprite sprite, int anim, int sens ){
  
  switch(sens){

    case 0:
      sprite.setTextureRect(sf::IntRect(64 * anim, 0, 64, 64));
    break;

    case 1:
      sprite.setTextureRect(sf::IntRect(64 * anim, 64, 64, 64));
    break;

    case 2:
      sprite.setTextureRect(sf::IntRect(64 * anim, 128, 64, 64));
    break;

    case 3:
      sprite.setTextureRect(sf::IntRect(64 * anim, 192, 64, 64));
    break;
  }
  
  anim++;

  if ( anim > 3) {
    
    anim = 0;
  }
}

void rotation( sf::Sprite canon ){


}