#include <SFML/Graphics.hpp>
#include <iostream>

#pragma region variables
sf::Texture perso;
sf::Sprite sperso;
#pragma endregion variables

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
	{
		// on charge la texture du tileset
		if (!m_tileset.loadFromFile(tileset))
			return false;

		// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);

		// on remplit le tableau de vertex, avec un quad par tuile
		for (unsigned int i = 0; i < width; ++i)
			for (unsigned int j = 0; j < height; ++j)
			{
				// on récupère le numéro de tuile courant
				int tileNumber = tiles[i + j * width];

				// on en déduit sa position dans la texture du tileset
				int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				// on récupère un pointeur vers le quad à définir dans le tableau de vertex
				sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

				// on définit ses quatre coins
				quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				// on définit ses quatre coordonnées de texture
				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			}

		return true;
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// on applique la transformation
		states.transform *= getTransform();

		// on applique la texture du tileset
		states.texture = &m_tileset;

		// et on dessine enfin le tableau de vertex
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};
	int x = 0;

	TileMap map;
	if (!map.load("C:/Users/unpet/Desktop/tileset.png", sf::Vector2u(32, 32), level, 16, 8)) {
		std::cout << "erreur map" << std::endl;
	}
	if (!perso.loadFromFile("C:/Users/unpet/Desktop/sprite.png")) {
		std::cout << "erreur" << std::endl;
	}
	perso.setSmooth(true);
	sperso.setTexture(perso);
	sperso.setTextureRect(sf::IntRect(32, 0, 32, 32));
	sperso.setPosition(256, 128);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sperso.move(0, -0.1);
			sperso.setTextureRect(sf::IntRect(32*x, 96, 32, 32));
			x++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			sperso.move(0, 0.1);
			sperso.setTextureRect(sf::IntRect(32*x, 0, 32, 32));
			x++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			sperso.move(-0.1, 0);
			sperso.setTextureRect(sf::IntRect(32*x, 32, 32, 32));
			x++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			sperso.move(0.1, 0);
			sperso.setTextureRect(sf::IntRect(32*x, 64, 32, 32));
			x++;
		}
		if (x > 2) {
			x = 0;
		}
		if ((sperso.getPosition().x > 512) || (sperso.getPosition().x < 0) || (sperso.getPosition().y > 256) || (sperso.getPosition().y < 0)) {
			sperso.setPosition(256, 128);
		}

		window.clear();
		window.draw(map);
		window.draw(sperso);
		window.display();
	}

	return 0;
}