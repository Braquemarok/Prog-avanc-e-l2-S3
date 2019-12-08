#include "List.h"


using namespace std;


// Constructeur

/**
 * \brief Construit une liste d'entité vide
*/
template <class T>
List<T>::List(){

  list = NULL;
  lvar = NULL;
  taille = 0;
}

//Méthodes d'accès et autres

/**
 * \brief Ajoute une entité dans la liste
 * \param e une entité
*/
template <class T>
void List<T>::ajouter( T* e ){

  //On créer la liste à insérer dans la liste principale
  Liste<T>* res = new Liste<T>;
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
template <class T>
T* List<T>::get( int i ){

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
template <class T>
int List<T>::size(){

  return taille;
}

/**
 * \brief Supprime l'entité à la case i de la liste
 * \param i la position de l'entité dans la liste
*/
template <class T>
void List<T>::supprimer( int i ){

  if ( list == NULL ){

    cout << "Impossible de supprimer un élément d'une liste vide !\n";
    exit(0);
  }

  lvar = list;
  Liste<T>* tmp = new Liste<T>;
  Liste<T>* suppr = new Liste<T>;

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
template <class T>
void List<T>::liberer_liste( Liste<T> L ){

  if ( L != NULL ){

    liberer_liste( L->suivant );
    delete L;
  }
}

/**
 * \brief Libère toutes les listes de l'objet
*/
template <class T>
void List<T>::free(){

  liberer_liste(list);
  liberer_liste(lvar);
}


/**
 * \brief Affiche la liste d'entité
*/
template <class T>
void List<T>::to_string(){

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

