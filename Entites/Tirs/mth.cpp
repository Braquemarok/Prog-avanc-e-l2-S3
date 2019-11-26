#include "mth.h"

double distance( int x, int y, int z, int t){

  double res = sqrt( pow(( z - x ), 2 ) + pow(( t - y ), 2) );
  if(res<=0){
    res=0.0001;
  }
  return res;
}
