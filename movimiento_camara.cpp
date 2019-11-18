#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <time.h>
#include <cstring>


using namespace std;


static int estado_vista = 1; // Ortho view = 1, Perspective = 0

GLfloat xi = 0.0;
GLfloat yi = 0.0;


bool tecla_presionado;
double mouse_x_anterior, mouse_y_anterior, actual_mouse_x, actual_mouse_y;


void init(void)
{

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);




}

void tecla(int tecla, int x, int y) {
	switch (tecla)
	{
	case GLUT_KEY_RIGHT:
		if (xi < 10)
			xi += 0.5;
		break;

	case GLUT_KEY_LEFT:
		if (xi > -10)
			xi -= 0.5;
		break;

	case GLUT_KEY_UP:
		if (yi < 10)
			yi += 0.5;
		break;

	case GLUT_KEY_DOWN:
		if (yi > -10)
			yi -= 0.5;
		break;

	default:
		break;
	}


}

void mouse(int mouse, int state, int x, int y)
{

	if (mouse == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		actual_mouse_x= x;
		actual_mouse_y = y;
		tecla_presionado = true;
	}
	else if (mouse == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		mouse_x_anterior = x;
		mouse_y_anterior = y;
		tecla_presionado = false;
	}

}


void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-8.0, 8.0, 8.0, -8.0, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(xi, yi, 0);

	// Turn Perspective mode on/off
	if (estado_vista == 0)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, 1, 1.0, 30.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	if (tecla_presionado) {

		double x = mouse_x_anterior - actual_mouse_x;
		double y = mouse_y_anterior - actual_mouse_y;

		double lenVector = sqrt(pow(x, 2) + pow(y, 2));

		if (lenVector != 0) {
			xi -= (x / lenVector) * 0.1;
			yi -= (y / lenVector) * 0.1;
		}
		cout << xi << "\t" << yi << endl;

		gluLookAt(0, 0, -5, xi, yi, 0, 0, 1, 0);
	}
	

	glPushMatrix();

	glTranslatef(0, 0, -14);
	glRotatef(180, 1.0, 0.0, 0.0);


	glPushMatrix();// Draw next arm axis.
	glColor3f(0.0, 1.0, 1.0); // give it a color
	glTranslatef(2.0, 2.0, 0.0);
	glutSolidCube(1.0);

    glPushMatrix();// Draw next arm axis.
	glColor3f(0.0, 1.0, 1.0); // give it a color
	glTranslatef(-2.0, -2.0, 0.5);
	glutSolidCube(1.0);


	glPushMatrix();// Draw next arm axis.
	glColor3f(0.0, 1.0, 1.0); // give it a color
	glTranslatef(0.0, -2.0, 5);
	glutSolidCube(1.0);
	

	glEnd();
	glPopMatrix(); // Cierra la matriz
	glFlush();
	glutSwapBuffers();




}






void reshape(int w, int h) 
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.00, 10.0, 0.1, 20.0); 
	glMatrixMode(GL_MODELVIEW); //

}

void keyboard(unsigned char tecla, int x, int y) 
{
	if (tecla == 'c' || tecla == 'C') {
		estado_vista = abs(estado_vista - 1);
		cout << estado_vista << endl;
	}
}


int main(int argc, char** argv)
{
	cout << "Teclas de direccion para moverse " << endl;
	cout << "Tecla c para cambiar la perspectiva" << endl;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Movimiento de Camara");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(tecla);
	glutMouseFunc(mouse);
	glutMainLoop();



	return 0;
}
