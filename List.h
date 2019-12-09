#ifndef DEF_LISTE
#define DEF_LISTE

#include <iostream>

//Définition du type liste
template <class T>

struct Liste{

    T* premier;
    Liste<T>* suivant;
};

template <class T>

class List{

    private:

    //La liste principale
    Liste<T>* list;

    //La liste de 'travail'
    Liste<T>* lvar;

    //Taille de la liste principale
    int taille;

    void liberer_liste( Liste<T>* L );

    public:

    //Constructeur
    List();

    //Méthodes d'accès et autres
    void ajouter( T* e );
    T* get( int i );
    int size();
    void supprimer( int i );
    void free();
    void to_string();

};

#endif
