#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Joueur.h"
#include "Monstre.h"
#include "Map.h"

/*class arme {
public:

private:

};*/

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 288), "Tilemap");

	const int level[] =
	{
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 3,
		3, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 3,
		3, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 3,
		3, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 3,
		3, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 3,
		3, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	};
	Joueur j;
	Monstre m;
	TileMap map;
	if (!map.load("C:/Users/unpet/Desktop/tileset.png", sf::Vector2u(32, 32), level, 16, 9)) {
		std::cout << "erreur map" << std::endl;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		j.actions();
		m.actions(j);
		window.clear();
		window.draw(map);
		window.draw(j.sperso);
		window.draw(m.sperso);
		window.display();
	}

	return 0;
}