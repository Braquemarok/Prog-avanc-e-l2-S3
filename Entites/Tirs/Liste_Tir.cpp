#include "Liste_Tir.h"


using namespace std;

// Constructeur

/**
 * \brief Construit une liste de tir vide
*/
Liste_tir::Liste_tir(){

  list = NULL;
  lvar = NULL;
  taille = 0;
}

//Méthodes d'accès et autres

/**
 * \brief Ajoute un tir dans la liste
 * \param t un tir
*/
void Liste_tir::ajouter( Tir* t ){

  //On créer la liste à insérer dans la liste principale
  liste res = new Liste;
  res->suivant = NULL;
  res->premier = t;

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
 * \brief Retourne le tir à la case i de la liste
 * \param i la position du tir dans la liste
*/
Tir* Liste_tir::get( int i ){

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
int Liste_tir::size(){

  return taille;
}

/**
 * \brief Supprime le tir à la case i de la liste
 * \param i la position du tir dans la liste
*/
void Liste_tir::supprimer( int i ){

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

  delete suppr;
    
  taille--;
}

/**
 * \brief Libère la liste L de la mémoire
 * \param L la liste à libérer
*/
void Liste_tir::liberer_liste( liste L ){

  if ( L != NULL ){

    liberer_liste( L->suivant );
    delete L;
  }
}

/**
 * \brief Libère toutes les listes de l'objet
*/
void Liste_tir::free(){

  liberer_liste(list);
  liberer_liste(lvar);
}


/**
 * \brief Affiche la liste de tir
*/
void Liste_tir::to_string(){

  if ( list != NULL ){
    
    cout << "[ ";

    lvar = list;

    int i = 0;

    //On affiche un nombre croissant pour chaque tir
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
