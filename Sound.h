#ifndef DEF_SOUND
#define DEF_SOUND

#include <SFML/Audio.hpp>
#include <iostream>

class Sound{
public:
  sf::Music music;

  Sound();
  void play();
  void stop();
};
#endif
