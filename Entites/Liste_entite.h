#ifndef DEF_LISTE_ENTITE
#define DEF_LISTE_ENTITE

#include <iostream>
#include "Entite.h"

class Liste_entite{

    private:

    //Définition du type liste
    typedef struct Liste{

        Entite* premier;
        Liste* suivant;
    }*liste;

    //La liste principale
    liste list;

    //La liste de 'travail'
    liste lvar;

    void liberer_liste( liste L );

    public:

    //Constructeur
    Liste_entite();

    //Méthodes d'accès et autres
    void ajouter( Entite* e );
    Entite* get( int i );
    void supprimer( int i );
    void free();    
    void to_string();

};

#endif