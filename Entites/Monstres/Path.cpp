#include "Path.h"
int calcG(int x1, int x2, int y1, int y2){
  return sqrtf((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
int calcH(int** t, int x1,int x2, int y1, int y2, int l, int h){
  int calc[4];
  int x=0;
  int res=0;
  int** mp;
  t[x1][y1]=1;
  if(x1==x2 && y1==y2){
    res = 1;
  }
  else{
    for(int i=0; i<l; i++){
      for(int j=0; j<h; j++){
        if(((i==x1-1 || i==x1+1) && j==y1) || ((j==y1-1 || j==y1+1) && i==x1)){
          if(x1>=0 && x1<l && y1>=0 && y1<h && t[i][j]>=3 && res==0){
            res = calcH(t, i, x2, j,y2, l, h);
            if(res>=1){
              res++;
            }
          }
        }
      }
    }
  }
  return res;
}
int pathExists(int** t, int x1,int x2, int y1, int y2, int l, int h){
  int res=0;
  int calc[4]={0,0,0,0};
  int** mp;
  mp=new int* [l];
  for(int i=0; i<l; i++){
    mp[i]=new int[h];
  }
  for(int i=0; i<l; i++){
    for(int j=0; j<h; j++){
      mp[i][j]= t[i][j];
    }
  }
  mp[x1][y1]=1;
  if(x1==x2 && y1==y2){
    res = 1;
  }
  else{
    int** mp2;
    mp2=new int* [l];
    for(int i=0; i<l; i++){
      mp2[i]=new int[h];
    }
    for(int i=0; i<l; i++){
      for(int j=0; j<h; j++){
        mp2[i][j]= mp[i][j];
      }
    }
    calc[0]=calcH(mp2, x1-1,x2, y1, y2, l, h);
    for(int i=0; i<l; i++){
      for(int j=0; j<h; j++){
        mp2[i][j]= mp[i][j];
      }
    }
    calc[1]=calcH(mp2, x1+1,x2, y1, y2, l, h);
    for(int i=0; i<l; i++){
      for(int j=0; j<h; j++){
        mp2[i][j]= mp[i][j];
      }
    }
    calc[2]=calcH(mp2, x1,x2, y1-1, y2, l, h);
    for(int i=0; i<l; i++){
      for(int j=0; j<h; j++){
        mp2[i][j]= mp[i][j];
      }
    }
    calc[3]=calcH(mp2, x1,x2, y1+1, y2, l, h);
    for(int i=0; i<l; i++){
      delete[] mp2[i];
    }
    delete[] mp2;
    for(int i=0; i<4; i++){
      if(calc[i]==0){
        calc[i]+=1000;
      }
    }
    calc[0]+=calcG(x1-1,x2,y1,y2);
    calc[1]+=calcG(x1+1,x2,y1,y2);
    calc[2]+=calcG(x1,x2,y1-1,y2);
    calc[3]+=calcG(x1,x2,y1+1,y2);
    int inter[4]={0,0,0,0};
    int cond;
    while(res==0){
      cond=100000000;
      for(int i=0; i<4; i++){
        if(inter[i]==0){
          if(cond>calc[i]){
            cond=calc[i];
          }
        }
      }
      for(int i=0; i<4; i++){
        if(cond==calc[i]){
          if(i==0){
            if(t[x1-1][y1]>=3 && res==0){
              res = pathExists(mp, x1-1, x2, y1,y2, l, h);
            }
          }
          if(i==1){
            if(t[x1+1][y1]>=3 && res==0){
              res = pathExists(mp, x1+1, x2, y1,y2, l, h);
            }
          }
          if(i==2){
            if(t[x1][y1-1]>=3 && res==0){
              res = pathExists(mp, x1, x2, y1-1,y2, l, h);
            }
          }
          if(i==3){
            if(t[x1][y1+1]>=3 && res==0){
              res = pathExists(mp, x1, x2, y1+1,y2, l, h);
            }
          }
          if(res==0){
            inter[i]=1;
          }
        }
      }
      int verif=0;
      for(int i=0; i<4; i++){
        if(inter[i]==0){
          verif++;
        }
      }
      if(verif<=0){
        res=-1;
      }
    }
    int i=0;
    while(inter[i]==1 || cond!=calc[i]){
      i++;
    }
    if(i==0){
      res=1;
    }
    if(i==1){
      res=2;
    }
    if(i==2){
      res=3;
    }
    if(i==3){
      res=4;
    }
  }
  for(int i=0; i<l; i++){
    delete[] mp[i];
  }
  delete[] mp;
  return res;
}
