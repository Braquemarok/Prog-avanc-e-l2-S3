
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

   int z=0, t, u;
   if(fichier)
   {
      string ligne;
      while(getline(fichier, ligne))
      {
        istringstream iss (ligne);
        string y=iss.str();
        for(unsigned int i=0; i<y.size(); i++){
          t=0;
          if((int)y.at(i)-'0'>=0 && (int)y.at(i)-'0'<=9){
             while(i<y.size() && (int)y.at(i)-'0'>=0 && (int)y.at(i)-'0'<=9){
               z++;
               i++;
             }
             for(int j=0; j<z; j++){
               u=1;
               for(int w=0; w<j; w++){
                 u*=10;
               }
               t+=((int)y.at(i-j-1)-'0')*u;
             }
             x.push_back(t);
             z=0;
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
