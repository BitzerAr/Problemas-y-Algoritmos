#include "TriangleSierpinski.h"
Point::Point(float x, float y, float z){
	pos[0]=x;
	pos[1]=y;
	pos[2]=z;
}

float * Point::getNewPoint(){
	return pos;
}