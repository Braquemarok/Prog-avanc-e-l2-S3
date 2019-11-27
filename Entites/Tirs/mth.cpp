#include "mth.h"

double distance( int x, int y, int z, int t){

  double res = sqrt( pow(( z - x ), 2 ) + pow(( t - y ), 2) );
  if(res<=0){
    res=0.0001;
  }
  return res;
}
double mur(int x, int y){
  double res;
  if(x-y<0){
    res=y-x;
  }
  else{
    res=x-y;
  }
  return res;
}
