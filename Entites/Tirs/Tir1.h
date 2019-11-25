#ifndef DEF_TIR1
#define DEF_TIR1

#include "Tir.h"

class Tir1 : public Tir
{
public:

	int z,t;

	Tir1(int x, int y, int z);
	void actions();
	double distance( int x, int y );
};
#endif
