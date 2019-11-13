#include "Sound.h"

Sound::Sound(){
  if (!music.openFromFile("Sounds/music.ogg")){
    std::cout << "erreur" << std::endl;
  }
}
void Sound::play(){
  music.play();
}
void Sound::stop(){
  music.stop();
}
