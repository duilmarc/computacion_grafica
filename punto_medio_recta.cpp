#include <iostream>
#include <stdlib.h> 
#include <math.h> 
#include <GL/glut.h> 


using namespace std;

void init(void); 

void display(void); 
void draw_recta_punto_medio(float,float,float,float);

int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
	glutInitWindowSize(500,500); 

	glutInitWindowPosition(100,100); 
	glutCreateWindow(argv[0]); 
	init(); 
	glutDisplayFunc(display); 
	glutMainLoop(); 
	return 0; 
} 

void init(void) 
{ 
	glClearColor(0.0,0.0,0.0,0.0);  //parametros: rojo, amarillo, azul, el cuarto es el parametro alpha 
	glShadeModel(GL_FLAT); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluOrtho2D(-10.0,20.0,-10.0,20); 

} 

void draw_recta_punto_medio(float x_0, float y_0, float x_f, float y_f)
{
	GLfloat x,y,dx,dy,incrementoE,incrementoNE,d,inc_x,inc_y; 
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

}
void display(void) 
{ 
	
	glClear(GL_COLOR_BUFFER_BIT); 
	glPushMatrix();// salva el estado actual de la matriz 
	draw_recta_punto_medio(1,1,4,6);
	glPopMatrix();   // reecupera el estado del matriz 
	glFlush(); 
} 


