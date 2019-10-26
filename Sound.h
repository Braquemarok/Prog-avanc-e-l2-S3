class Sound{
public:
  sf::Music music;

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
};
