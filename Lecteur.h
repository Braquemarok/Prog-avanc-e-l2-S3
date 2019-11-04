
#include <fstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> lecteur (string s)
{
   ifstream fichier(s);
   vector<int> x;
   if(fichier)
   {
      string ligne;
      while(getline(fichier, ligne))
      {
        istringstream iss (ligne);
        string y=iss.str();
        for(unsigned int i=0; i<y.size(); i++){
           if((int)y.at(i)-'0'>=0 && (int)y.at(i)-'0'<=9){
             x.push_back((int)y.at(i)-'0');
           }
         }
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
   return x;
}
