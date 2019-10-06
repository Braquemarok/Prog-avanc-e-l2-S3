class Sound{
public:
  sf::Music music;

  Sound(){
    if (!music.openFromFile("/home/chocolat/Bureau/progtest/music.ogg")){
      std::cout << "erreur" << std::endl;
    }
  }
  void play(){
    music.play();
  }
};
