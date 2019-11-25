#include "Sound.h"

Sound::Sound(){
  if (!music.openFromFile("Sounds/fun.ogg")){
    std::cout << "erreur" << std::endl;
  }
}
void Sound::play(){
  music.play();
}
void Sound::stop(){
  music.stop();
}
