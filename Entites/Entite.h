#ifndef DEF_ENTITE
#define DEF_ENTITE

#include <iostream>
#include "Tirs/Tir.h"
#include "Tirs/Tir1.h"
#include "Tirs/Tir2.h"
#include "Tirs/Tir3.h"
#include "../List.cpp"
#include "Animation.h"
#include "Tirs/mth.h"
#include "Monstres/Path.h"

class Entite
{
public:

	/**
	 * \brief Construit une Entité
	*/
	Entite() ;

	/**
	 * \brief Obtient l'état de l'Entité
	*/
	bool mort() const ;

	/**
	 * \brief Gère la collision entre une entité et un Tir
	 * \param m un tir
	*/
	void damage(Tir* m);

	/**
	 * \brief Gère la collision entre une entité et un Tir
	 * \param m le sprite de l'entité
	*/
  	void damage(sf::Sprite m);

	/**
	 * \brief Gère la collision entre une entité et un mur
	 * \param tiles le tileset (la map) 
	 * \param width la largeur de la map
	 * \param height la hauteur de la map
	*/  
	void collision(const int* tiles, unsigned int width, unsigned int height);

	/**
	 * \brief Gère la collision entre une entité et un mur
	 * \param m le sprite de l'entité
	*/  
	void collision(sf::Sprite m);
	
	//action du joueur
  	virtual void actions();
	virtual void actions( int z, int t);
  	
	//action monstre en fonction du joueur
	virtual void actions(Entite* j,int* map, int h, int l);
	virtual void actions(Entite* j);

	//getters

	/**
	 * \brief Renvoie le sprite de l'entité
	 * \return le sprite de l'entité
	*/  
  	sf::Sprite getEntite();

	/**
	 * \brief Renvoie le sprite du canon de l'entité
	 * \return le sprite du canon de l'entité
	*/  
	sf::Sprite getCanon();

	/**
	 * \brief Renvoie le sprite du tir i
	 * \param i la position du tir dans la liste
	 * \return le sprite du tir
	*/  
	sf::Sprite getstir(int i);

	/**
	 * \brief Renvoie le nombre de tirs du Joueur
	 * \return le nombre de tirs du Joueur
	*/  
	int getSizeTir();

	/**
	 * \brief Renvoie le tir i appartenant à l'entité
	 * \param i la position du tir dans la liste
	 * \return le tir i appartenant à l'entité
	*/  
	Tir* getTir(int i);

	/**
	 * \brief Renvoie le type de l'entité
	 * \return le type de l'entité
	*/
	int getType();

	virtual ~Entite();

protected:

	sf::Texture perso;
	sf::Texture canon;
	sf::Sprite sperso;
	sf::Sprite scanon;
	bool alive;	//l'état de lentité
	int type;	//le type de l'entité
	int anim = 0;	//le numéro de l'animation
	int sens;	//le sens du sprite
	int res;	//le mouvement à effectuer
	int pth;   	//le temps d'attente pour effectuer le mouvement
	sf::Clock* clock;
	List<Tir> tirs; //la liste de tirs

};
#endif
