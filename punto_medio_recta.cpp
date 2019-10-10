#include <iostream>
#include <stdlib.h> 
#include <math.h> 
#include <GL/glut.h> 


using namespace std;

void init(void); 

void display(void); 

void reshape(int,int); 

int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
	glutInitWindowSize(500,500); 

	glutInitWindowPosition(100,100); 
	glutCreateWindow(argv[0]); 
	init(); 
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape); 
	glutMainLoop(); 
	return 0; 
} 

void init(void) 
{ 
	glClearColor(0.0,0.0,0.0,0.0);  //parametros: rojo, amarillo, azul, el cuarto es el parametro alpha 
	glShadeModel(GL_FLAT); 
} 
 
void display(void) 
{ 
	float x_0 = 1, y_0 = 2, x_f= 10, y_f= 10;

	GLfloat x,y,dx,dy,incrementoE,incrementoNE,d,inc_x,inc_y; 
	glClear(GL_COLOR_BUFFER_BIT); 
	glPushMatrix();// salva el estado actual de la matriz 
	
	x = x_0;
	y = y_0;

	dx = x_f - x_0;
	dy = y_f - y_0;

	incrementoE = 2 * dy;
	incrementoNE = 2 * ( dy - dx);
	
	d = 2 * dy - dx;
	

	inc_x = 0.0001;
	inc_y = dy * inc_x / dx ;

	glColor3f( 0.5 , 0.5 , 0.5);
	glVertex2f(x, y);
	glBegin(GL_POINTS);
		glVertex2f(x, y);
		while( x < x_f)
		{
			cout<<x<< "x ";
			cout<<y<< "y ";
			cout<<endl;
			if ( d <= 0 )
			{
				d = d + incrementoE;
				x = x + inc_x;
				y = y + inc_y;

			}
			else
			{	
				d = d + incrementoNE;
				x = x + inc_x;
				y = y + inc_y;

			}
			glVertex2f(x, y);
		}
	glEnd();
	glPopMatrix();   // reecupera el estado del matriz 
	glFlush(); 
} 

void reshape(int w, int h) 
{ 
	glViewport(0,0,(GLsizei)w, (GLsizei)h); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glOrtho(-10.0,10.0,-10.0,10,-10.0,10.0); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
} 
