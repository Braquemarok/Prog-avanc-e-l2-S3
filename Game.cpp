#include "Game.h"

Game::Game(){

  window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "I Wanna Be The Boshy");
  window.setFramerateLimit(60);
}
void Game::play(){
  sf::Clock clock;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed || world.isgameover())
        window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){

    }
    world.handlevent(clock.getElapsedTime().asMilliseconds());

    window.clear();

    draw();

    window.display();
  }
}
void Game::draw(){
  window.draw(world.getMap());
  window.draw(world.sp());
  for(int i=0; i<world.nbm();i++){
    window.draw(world.sm(i));
  }
  for(int i=0; i<world.je();i++){
    window.draw(world.st(i));
  }
}
