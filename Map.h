#ifndef DEF_MAP
#define DEF_MAP

#include <SFML/Graphics.hpp>
#include <iostream>

class TileMap : public sf::Drawable, public sf::Transformable{

public:

	/**
	 * \brief Load la map à partir du tileset
	 * \param tileset le nom des ressources du tileset
	 * \param tileSize la taille commune des tiles 
	 * \param tiles le tileset
	 * \param width la largeur de la map
	 * \param height la hauteur de la map
	 * \return vrai si la map est load, faux sinon
	 */
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:

	/**
	 * \brief SFML
	 * \param target composante SFML
	 * \param states composante SFML
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

#endif
