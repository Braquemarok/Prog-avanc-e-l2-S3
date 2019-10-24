#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "World.h"
/*class arme {
public:

private:

};*/

int main()
{
	World world;
	sf::RenderWindow window(sf::VideoMode(512, 288), "Tilemap");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || world.isgameover())
				window.close();
		}
		world.handlevent();
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
	//merde
	return 0;
}
