#include <iostream>
#include <string>
#include "World.h"

class Game
{
public:
	//constructeur
  Game(){

  	window.create(sf::VideoMode(512, 256), "poopy gayme");
  	window.setFramerateLimit(60);
  }
  void play(){
    sf::Clock clock;
    while (window.isOpen())
  	{
  		sf::Event event;
  		while (window.pollEvent(event))
  		{
  			if (event.type == sf::Event::Closed || world.isgameover())
  				window.close();
  		}
  		world.handlevent(clock.getElapsedTime().asMilliseconds());

  		window.draw(world.getMap());
  		window.draw(world.sp());
  		for(int i=0; i<world.nbm();i++){
  			window.draw(world.sm(i));
  		}
  		for(int i=0; i<world.je();i++){
  			window.draw(world.st(i));
  		}
  		window.display();
  		window.clear();
  	}
  }
  void draw(){}

private:
  World world;
	sf::RenderWindow window;

};