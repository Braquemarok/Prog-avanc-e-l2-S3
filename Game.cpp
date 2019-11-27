#include "Game.h"

Game::Game(){

  window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "poopy gayme");
  window.setFramerateLimit(60);
  world= new World();
}
void Game::play(){
  sf::Clock clock;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed || menu.getOpt()==2)
        window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || world->isgameover()){
      while(!menu.isMenuOver()){
        menu.handleMenu();
        drawm();
      }
      if(menu.getOpt()==1){
        world= new World();
      }
    }
    menu.setMenu();
    world->handlevent(clock.getElapsedTime().asMilliseconds(), sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

    draw();

  }
}
void Game::draw(){
  window.clear();
  window.draw(world->getMap());
  window.draw(world->sp());
  window.draw(world->jvie());
  for(int i=0; i<world->nbm();i++){
    window.draw(world->sm(i));
  }
  for(int i=0; i<world->je();i++){
    window.draw(world->st(i));
  }
  window.display();
}
void Game::drawm(){
  window.clear();
  for(int i=0; i<4; i++){
      window.draw(menu.getText(i));
  }
  window.display();
}
