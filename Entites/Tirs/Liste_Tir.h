#ifndef DEF_LISTE_TIR
#define DEF_LISTE_TIR

#include <iostream>
#include "Tir.h"

class Liste_tir{

    private:

    //Définition du type liste
    typedef struct Liste{

        Tir* premier;
        Liste* suivant;
    }*liste;

    //La liste principale
    liste list;

    //La liste de 'travail'
    liste lvar;

    void liberer_liste( liste L );

    public:

    //Constructeur
    Liste_tir();

    //Méthodes d'accès et autres
    void ajouter( Tir* t );
    Tir* get( int i );
    void supprimer( int i );
    void free();    
    void to_string();

};

#endif