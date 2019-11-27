#include "Game.h"

Game::Game(){

  window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "poopy gayme");
  window.setFramerateLimit(60);
  mmenu = new MainMun(window.getSize().x,window.getSize().y);
  menu = new Ptmenu(window.getSize().x,window.getSize().y);
}
void Game::play(){
  int deb=0;
  sf::Clock clock;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed || mmenu->getOpt()==2){
        window.close();
      }
    }
    while(!mmenu->isMenuOver()){
      mmenu->handleMenu();
      drawm(mmenu);
    }
    if((mmenu->getOpt()==0 || mmenu->getOpt()==2) && deb==0){
      world = new World();
      deb++;
    }
    else if(mmenu->getOpt()==1 && deb==0){
      ifstream fichier("SAVE/save.txt");
      if(!fichier.fail()){
        world = new World("SAVE/save.txt");
        deb++;
      }
      else{
        mmenu->setMenu();
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || world->isgameover()){
      while(!menu->isMenuOver()){
        menu->handleMenu();
        drawm(menu);
      }
      if(menu->getOpt()==1){
        world = new World();
      }
      if(menu->getOpt()==2){
        mmenu = new MainMun(window.getSize().x,window.getSize().y);
        deb=0;
        writer(world->getPlayer());
      }
      menu->setMenu();
    }
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
void Game::drawm(Menu* mm){
  window.clear();
  window.draw(mm->getfond());
  for(int i=0; i<4; i++){
      window.draw(mm->getText(i));
  }
  window.display();
}
