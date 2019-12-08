#include "Game.h"

Game::Game(){

  vector<int> size=lecteur("Maps/ref.txt");
  window.create(sf::VideoMode(size[0]*64, size[1]*64), "poopy gayme");
  window.setFramerateLimit(60);
  mmenu = new MainMun(window.getSize().x,window.getSize().y);
  menu = new Ptmenu(window.getSize().x,window.getSize().y);
  world = new World(1);
}
void Game::play(){
  int state = 0;
  int lv=1;
  Menu* lvend;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed || (mmenu->getOpt()==2 && mmenu->isMenuOver())){
        window.clear();
        window.close();
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && mmenu->isMenuOver()){
      state=1;
    }
    if(state==0){
      mmenu->setMenu();
      mmenu->handleMenu();
      drawm(mmenu);
      if(mmenu->isMenuOver()){
        state=3;
        if((mmenu->getOpt()==0 || mmenu->getOpt()==2)){
          delete world;
          world = new World(lv);
        }
        else if(mmenu->getOpt()==1){
          ifstream fichier("Save/save.txt");
          if(!fichier.fail()){
            delete world;
            world = new World("Save/save.txt");
          }
          else{
            mmenu->setMenu();
          }
        }
      }
    }
    else if(state==1){
      menu->handleMenu();
      drawm(menu);
      if(menu->isMenuOver()){
        state=3;
        while(!menu->isMenuOver()){
          menu->handleMenu();
          drawm(menu);
        }
        if(menu->getOpt()==1){
          delete world;
          world = new World(lv);
        }
        if(menu->getOpt()==2){
          delete mmenu;
          mmenu = new MainMun(window.getSize().x,window.getSize().y);
          state=0;
          writer(world);
        }
        menu->setMenu();
      }
    }
    else if(state==2){
      drawm(lvend);
      lvend->handleMenu();
      if(lvend->isMenuOver()){
        state=3;
        delete lvend;
      }
    }
    else{
      world->handlevent(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
      draw();
      if(world->nbm()==0){
        lv++;
        if(lv>4){
          lv=1;
        }
        state=2;
        delete world;
        world = new World(lv);
        lvend=new Lvend(window.getSize().x,window.getSize().y);
      }
    }
    if(world->isgameover()){
      state=0;
      lv=1;
    }
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
Game::~Game(){
  delete menu;
  delete mmenu;
  delete world;
}
