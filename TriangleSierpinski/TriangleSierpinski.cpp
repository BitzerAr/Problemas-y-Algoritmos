#include <GL/glut.h>
#include <unistd.h>
#include "TriangleSierpinski.h"
float *pos1,*pos2,*pos3,*pos4;
Point *Punto1=NULL;
Point *Punto2=NULL;
Point *Punto3=NULL;
Point *Punto4=NULL;
void initgl(){
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,0.0);

	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	Punto1 =new Point(0.0,0.8,0.0);
	Punto2 =new Point(-0.7,-0.4,0.0);
	Punto3 =new Point(0.7,-0.4,0.0);
	Punto4 = new Point(0.0,0.0,0.0);
	glBegin(GL_POINTS);
		glColor3f(0.0,0.0,1.0);
		pos1=Punto1->getNewPoint();
		glVertex3f(pos1[0],pos1[1],pos1[2]);
		pos2=Punto2->getNewPoint();
		glVertex3f(pos2[0],pos2[1],pos2[2]);
		pos3=Punto3->getNewPoint();
		glVertex3f(pos3[0],pos3[1],pos3[2]);
	glEnd();

}
void display(void){
	int c;

	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_POINTS);
		glColor3f(0.0,0.0,1.0);
		pos4=Punto4->getNewPoint();
		for(int i=0; i< 10000 ; i++){		
			c=rand()%3+1;
			if(c%3==0){
				pos4[0]=(pos4[0]+pos1[0])/2;
				pos4[1]=(pos4[1]+pos1[1])/2;
				pos4[2]=(pos4[2]+pos1[2])/2;
				glVertex3f(pos4[0],pos4[1],pos4[2]);
				
			}else if(c%3==1){
				pos4[0]=(pos4[0]+pos2[0])/2;
				pos4[1]=(pos4[1]+pos2[1])/2;
				pos4[2]=(pos4[2]+pos2[2])/2;
				glVertex3f(pos4[0],pos4[1],pos4[2]);
			}else{
				pos4[0]=(pos4[0]+pos3[0])/2;
				pos4[1]=(pos4[1]+pos3[1])/2;
				pos4[2]=(pos4[2]+pos3[2])/2;
				glVertex3f(pos4[0],pos4[1],pos4[2]);
			}
		}
	glEnd();
	glFlush();
}
void idle(void){

	usleep(33);
	glutPostRedisplay();
}
int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(20,20);
	glutInitWindowSize(900,900);
	glutCreateWindow("Rebotes");
	initgl();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}

