#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;


class Punto {
public:
    float x, y;
    void setxy(float x2, float y2)
    {
        x = x2; y = y2;
    }
    const Punto & operator=(const Punto &rPunto)
    {
        x = rPunto.x;
        y = rPunto.y;
        return *this;
    }

};

Punto vector_puntos[20]; // capacidad maxima 20
int tamanio_pantalla = 500;
int puntos = 0;
int clicks; // por defecto


void myInit() {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,500.0);

}

int factorial(int n) 
{ 
    
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

float binomial_coff(float n,float k)
{
    float ans;
    ans = factorial(n) / (factorial(k)*factorial(n-k));
    return ans;
}

Punto punto_beizer(Punto PT[], double t) {
        Punto P;
        P.x = 0; P.y = 0;   
        for (int i = 0; i<clicks; i++)
        {
            P.x = P.x + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].x;
            P.y = P.y + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].y;
        }
        return P;
    }


void insertar_por_mouse(int button, int state, int x, int y) {
  
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

    y= tamanio_pantalla-y;
    vector_puntos[puntos].setxy((float)x,(float)(y));
    puntos++;

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
 
    // Si se llega a la cantidad de clicks estipulada al comienzo
    if(puntos == clicks) 
    {
        glColor3f(0,0.6,0.4);
        // Drawing the control lines
        for(int k=0;k<clicks-1;k++)
        {
        	glBegin(GL_LINES);
              glVertex2f(vector_puntos[k].x, vector_puntos[k].y);
              glVertex2f(vector_puntos[k+1].x,  vector_puntos[k+1].y);
            glEnd();
            glFlush();  
        }
        	 
        Punto p1 = vector_puntos[0];
      	// Dibujar cada segmento de la curva 
        for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            Punto p2 = punto_beizer(vector_puntos,t);
            glColor3f(0.0,0.0,0.0);
            glBegin(GL_LINES);
              glVertex2f(p1.x, p1.y);
              glVertex2f(p2.x, p2.y);
            glEnd();
            glFlush();
            p1 = p2;
        } 
        glColor3f(0.0,1.0,0.0);
        cout<<"Inserte la cantidad de clicks para realizar la curva de Bezier: "<<endl;
		cin>>clicks;
        puntos = 0;
    }
  }
}


void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char *argv[]) {
	cout<<"Inserte la cantidad de clicks para realizar la curva de Bezier: "<<endl;
	cin>>clicks;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,500);
    glutInitWindowPosition(100,150);
    glutCreateWindow("CURVA DE BEZIER EJEMPLO");
    glutMouseFunc(insertar_por_mouse);
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    return 0;
}