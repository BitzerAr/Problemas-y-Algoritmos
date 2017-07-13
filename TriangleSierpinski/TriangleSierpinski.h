#ifndef TriangleSierpinski_h
#define TriangleSierpinski_h
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;

class Point{
	private:
		float pos[3];
		float res[3];
	public:
		Point(float x,float y,float z);
		float * getNewPoint();
		
};
#endif