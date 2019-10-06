#include <SFML/Audio.hpp>

int main()
{
  sf::Music music;
    if (!music.openFromFile("/home/chocolat/Bureau/progtest/music.ogg")){
      return -1; // erreur
    }
    music.play();
    return 0;
}
