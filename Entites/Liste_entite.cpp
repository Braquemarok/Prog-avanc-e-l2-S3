#include "Liste_entite.h"


using namespace std;

// Constructeur

/**
 * \brief Construit une liste d'entité vide
*/
Liste_entite::Liste_entite(){

  list = NULL;
  lvar = NULL;
  taille = 0;
}

//Méthodes d'accès et autres

/**
 * \brief Ajoute une entité dans la liste
 * \param e une entité
*/
void Liste_entite::ajouter( Entite* e ){

  //On créer la liste à insérer dans la liste principale
  liste res = new Liste;
  res->suivant = NULL;
  res->premier = e;

  if ( list != NULL ){

    lvar = list;

    while( lvar->suivant != NULL ){

      lvar = lvar->suivant;
    }

    //On ajoute la liste à la fin
    lvar->suivant = res;
  }

  else{

    list = res;
  }

  taille++;
}

/**
 * \brief Retourne l'entité à la case i de la liste
 * \param i la position de l'entité dans la liste
 * \return L'entité à la position i
*/
Entite* Liste_entite::get( int i ){

  if ( list == NULL ){

    cout << "Impossible de retourner un élément d'une liste vide !\n";
    exit(0);
  }

  lvar = list;

  //On cherche à atteindre la position i
  while(( i > 0 )&&( lvar->suivant != NULL )){

    lvar = lvar->suivant;
    i--;
  }

  return lvar->premier;
}

/**
 * \brief Retourne la taille de la liste
 * \return La taille de la liste
*/
int Liste_entite::size(){

  return taille;
}

/**
 * \brief Supprime l'entité à la case i de la liste
 * \param i la position de l'entité dans la liste
*/
void Liste_entite::supprimer( int i ){

  if ( list == NULL ){

    cout << "Impossible de supprimer un élément d'une liste vide !\n";
    exit(0);
  }

  lvar = list;
  liste tmp = new Liste;
  liste suppr = new Liste;

  //On cherche à atteindre la position i
  while(( i > 0 )&&( lvar->suivant != NULL )){

    tmp = lvar;
    lvar = lvar->suivant;
    i--;
  }

  //On récupère l'élément à supprimer
  suppr = lvar;
  //On sauvegarde la suite de la liste
  lvar = lvar->suivant;
  //On sauvegarde les éléments précèdents de celui qu'on supprime
  tmp->suivant = lvar;

  //Si c'est le premier élément que l'on veut supprimer
  if ( suppr == list ){
    list = list->suivant;
    //aucune sauvegarde d'élément précèdent à effectuer, on libère la liste temporaire
    tmp = NULL;
    delete tmp;
  }

  delete suppr->premier;

  delete suppr;

  taille--;
}

/**
 * \brief Libère la liste L de la mémoire
 * \param L la liste à libérer
*/
void Liste_entite::liberer_liste( liste L ){

  if ( L != NULL ){

    liberer_liste( L->suivant );
    delete L;
  }
}

/**
 * \brief Libère toutes les listes de l'objet
*/
void Liste_entite::free(){

  liberer_liste(list);
  liberer_liste(lvar);
}


/**
 * \brief Affiche la liste d'entité
*/
void Liste_entite::to_string(){

  if ( list != NULL ){

    cout << "[ ";

    lvar = list;

    int i = 0;

    //On affiche un nombre croissant pour chaque entité
    while( lvar->suivant != NULL ){

      cout << i << " ";
      lvar = lvar->suivant;
    }

    cout << "]\n";
  }

  else{

    cout << "Liste vide\n";
  }
}
Liste_entite::~Liste_entite(){
  free();
}
