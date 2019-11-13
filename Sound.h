#ifndef DEF_SOUND
#define DEF_SOUND

#include <SFML/Audio.hpp>
#include <iostream>

class Sound{
public:
  sf::Music music;

<<<<<<< HEAD
  Sound();
  void play();
  void stop();
=======
  Sound(){
    if (!music.openFromFile("Sounds/music.ogg")){
      std::cout << "erreur" << std::endl;
    }
  }
  void play(){
    music.play();
  }
  void stop(){
    music.stop();
  }
>>>>>>> v2
};
#endif
