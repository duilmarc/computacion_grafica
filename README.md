# RESULTADOS TRABAJO EN COMPUTACION GRAFICA

## Tabla de contenido
- [Algoritmo Incremental](#algoritmo-incremental).
  - Imagen.
  - Codigo.
- [Recta Punto Medio](#grafica-de-la-recta-con-punto-medio).
  - Imagen.
  - Codigo.
- [Circunferencia](#circunferencia-con-punto-medio).
  - Imagen.
  - Codigo.
- [Poligonos](#graficando-poligono).
  - Imagen.
  - Codigo.
- [Movimiento Camara](#movimiento-camara).
- [Curva Bezier](#bezier)
  - Formula Generalizada de Beizer
  - Imagen
  - Codigo.
  - Ejecutable y Codigo
- [Quadtree](#quadtree).
  - Implementación

   
  
### Algoritmo incremental

#### Imagen

![Imagen de la gràfica de la recta con algoritmo incremental](https://raw.githubusercontent.com/duilmarc/computacion_grafica/master/algoritmo_incremental.png)

#### Codigo

```
	float x, y;
	float a;
	int valor;

	a= ( y_f - y_0 ) / ( x_f - x_0 );

	glColor3f( 0.5 , 0.5 , 0.5);
	glBegin(GL_POINTS);
	for ( x = x_0; x <= x_f ;)
	{	
		y = ( y_0 + a * ( x- x_0));
		glVertex2f(x, y);
		x  = x + 0.01;
		cout << "x: "<< x <<" , y: " << y << endl;
	}
	glEnd();

```


### Grafica de la recta con punto medio 

#### Imagen
![Imagen de la gràfica de la recta con punto medio](https://raw.githubusercontent.com/duilmarc/computacion_grafica/master/linea_recta.png)

#### Codigo

		```c++
		
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
		
		```
### Circunferencia con punto medio

#### Imagen
![Imagen de la gràfica de la circunferencia con punto medio](https://raw.githubusercontent.com/duilmarc/computacion_grafica/master/circunferencia.png)

#### Codigo
```
void circunferencia(int radio)
{
    GLfloat x,y,d, x_inc,y_inc; 

    x = 0;
    y = radio;
    d = 1 - radio;

    int deltaE = 3;
    int deltaSE = -2*radio+5;

    x_inc = 1;
    y_inc = 1;

    glColor3f( 0.5 , 0.5 , 0.5);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    puntos_circulo(x,y);
    while (y > x)
    {
        if (d < 0)
        {
            d += deltaE;
            deltaE +=x_inc*2;
            deltaSE +=x_inc*2;
        }
        else
        {
	        d += deltaSE;
	        deltaE +=x_inc*2;
	        deltaSE +=x_inc*4;
	        y -= y_inc;
        }
        x += x_inc;
        cout<<"x: "<<x<<" y: "<<y<< endl;
        glVertex2f(x,y);
        puntos_circulo(x,y);

    }
    glEnd();
}

void puntos_circulo(float x,float y)
{
    
    glVertex2f(x,-y);
    glVertex2f(-x,y);
    glVertex2f(-x,-y);
    glVertex2f(y,x);
    glVertex2f(y,-x);
    glVertex2f(-y,x);
    glVertex2f(-y,-x);

}


```
### Graficando poligono

#### Imagen
![Imagen de la gràfica del poligono](https://raw.githubusercontent.com/duilmarc/computacion_grafica/master/poligono.png)

#### Codigo
```
void dibujar_poligono(int n_lados, float r)
{
	float pasos, angulo, posi_x,posi_y, posn_x, posn_y;
    pasos = 2 * 3.14159 / n_lados;
    angulo = 0.0;
    posi_x = 0.0;
    posi_y = r;
    posn_x = 0.0;
    posn_y = 0.0;
	glColor3f( 0.5 , 0.5 , 0.5);
    glBegin(GL_LINES);
    for(int i=0; i<n_lados; ++i) {
            angulo += pasos;
            posn_x = r * sin(angulo);
            posn_y = r * cos(angulo);
            glVertex2f(posi_x, posi_y);
            glVertex2f(posn_x, posn_y);
            cout<<"posicion inicial x: " <<posi_x << " posicion inicial y: "<< posi_y<< endl;
            cout<<"posicion final x: " <<posn_x << " posicion final y: "<< posn_y<< endl;
            posi_x = posn_x;
            posi_y = posn_y;
    }
    glEnd();

}

```

### Movimiento Camara

![Imagen de los objetos](https://raw.githubusercontent.com/duilmarc/computacion_grafica/master/inicial.png)
```
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
	
```

![Movimiento de camara](https://raw.githubusercontent.com/duilmarc/computacion_grafica/master/mover.png)

```
bool tecla_presionado;
double mouse_x_anterior, mouse_y_anterior, actual_mouse_x, actual_mouse_y;

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

```
![Traslacion de perspectiva camara](https://raw.githubusercontent.com/duilmarc/computacion_grafica/master/rotacion.png)
```

static int estado_vista = 1;

void keyboard(unsigned char tecla, int x, int y) 
{
	if (tecla == 'c' || tecla == 'C') {
		estado_vista = abs(estado_vista - 1);
		cout << estado_vista << endl;
	}
}
```

### Bezier

#### Formula Generalizada de la curva de Beizer

![Imagen de la gràfica de la recta con algoritmo incremental](https://raw.githubusercontent.com/duilmarc/computacion_grafica/master/formulabezier.png)


#### Codigo
```
// Definimos la estructura de punto

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

// Definimos la funcion de la binomial
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


```

#### Imagen de Resultados

![Imagen de la gràfica de la recta con algoritmo incremental](https://raw.githubusercontent.com/duilmarc/computacion_grafica/master/bezier_resultados.png)

#### Ejecutable y Codigo

Codigo del programa y ejecutable del programa en la carpeta trabajospracticos3Fase 
Para compilar g++ bezierr.cpp -o bezier -lglut -lGLU -lGL
Ejecutar ./bezier



### Quadtree

####Implementacion

```
#include <iostream>
#include <cmath>


using namespace std; 
  
class Punto {
public:
    int x, y;
   
    Punto() 
    { 
        x = 0; 
        y = 0; 
    }
    Punto(int x2, int y2) 
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

  
// Objetos que guardemos en el nodo del arbol
struct Nodo 
{ 
    Punto pos; 
    int datos; // color por ejemplo
    Nodo(Punto _pos, int informacion) 
    { 
        pos = _pos; 
        datos = informacion; 
    } 
    Nodo() 
    { 
        datos = 0; 
    } 
}; 
  
// Clase del Quadtree 
class Quadtree 
{ 
    // Contiene el boundary del arbol
    Punto topLeft; // importante para graficar los limites del boundary
    Punto botRight; // importante para graficar las limites del boundary
  
    // Detalles del Nodo
    Nodo *n; 
  
    // Hijos del Arbol 
    Quadtree *arbol_arriba_izquierdo; 
    Quadtree *arbol_arriba_derecho; 
    Quadtree *arbol_bajo_izquierdo; 
    Quadtree *arbol_bajo_derecho; 
  
public: 
    Quadtree() 
    { 
        topLeft = Punto(0, 0); 
        botRight = Punto(0, 0); 
        n = NULL; 
        arbol_arriba_izquierdo  = NULL; 
        arbol_arriba_derecho = NULL; 
        arbol_bajo_izquierdo  = NULL; 
        arbol_bajo_derecho = NULL; 
    } 
    Quadtree(Punto topL, Punto botR) 
    { 
        n = NULL; 
        arbol_arriba_izquierdo  = NULL; 
        arbol_arriba_derecho = NULL; 
        arbol_bajo_izquierdo  = NULL; 
        arbol_bajo_derecho = NULL; 
        topLeft = topL; 
        botRight = botR; 
    } 
    void insertar(Nodo*); 
    Nodo* buscar(Punto); 
    bool en_region(Punto); 
}; 
  
// Insertar un nodo en el Quadtree
void Quadtree::insertar(Nodo *node) 
{ 
    if (node == NULL) 
        return; 
  
    // El nodo no puede estar en el quadtree 
    if (!en_region(node->pos)) 
        return; 
  
    // En el hoja del Quadtree
    // Donde ya no se puede dividir mas
    if (abs(topLeft.x - botRight.x) <= 1 && 
        abs(topLeft.y - botRight.y) <= 1) 
    { 
        if (n == NULL) 
            n = node; 
        return; 
    } 
  
    if ((topLeft.x + botRight.x) / 2 >= node->pos.x) 
    { 
        // Indica arbol_arriba_izquierdo 
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y) 
        { 
            if (arbol_arriba_izquierdo == NULL) 
                arbol_arriba_izquierdo = new Quadtree( 
                    Punto(topLeft.x, topLeft.y), 
                    Punto((topLeft.x + botRight.x) / 2, 
                        (topLeft.y + botRight.y) / 2)); 
            arbol_arriba_izquierdo->insertar(node); 
        } 
  
        // Indica arbol_bajo_izquierdo 
        else
        { 
            if (arbol_bajo_izquierdo == NULL) 
                arbol_bajo_izquierdo = new Quadtree( 
                    Punto(topLeft.x, 
                        (topLeft.y + botRight.y) / 2), 
                    Punto((topLeft.x + botRight.x) / 2, 
                        botRight.y)); 
            arbol_bajo_izquierdo->insertar(node); 
        } 
    } 
    else
    { 
        // Indica arbol_arriba_derecho 
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y) 
        { 
            if (arbol_arriba_derecho == NULL) 
                arbol_arriba_derecho = new Quadtree( 
                    Punto((topLeft.x + botRight.x) / 2, 
                        topLeft.y), 
                    Punto(botRight.x, 
                        (topLeft.y + botRight.y) / 2)); 
            arbol_arriba_derecho->insertar(node); 
        } 
  
        // Indica arbol_bajo_derecho 
        else
        { 
            if (arbol_bajo_derecho == NULL) 
                arbol_bajo_derecho = new Quadtree( 
                    Punto((topLeft.x + botRight.x) / 2, 
                        (topLeft.y + botRight.y) / 2), 
                    Punto(botRight.x, botRight.y)); 
            arbol_bajo_derecho->insertar(node); 
        } 
    } 
} 
  
// Buscar un nodo en el Quadtree
Nodo* Quadtree::buscar(Punto p) 
{ 
    // El punto no pertenece al boundary del quadtree
    if (!en_region(p)) 
        return NULL; 
  
    // Si llegamos a estar en la unidad del Quadtree
    // Ya no se puede dividir mas el Quadtree 
    if (n != NULL) 
        return n; 
  
    if ((topLeft.x + botRight.x) / 2 >= p.x) 
    { 
        // Indicates arbol_arriba_izquierdo 
        if ((topLeft.y + botRight.y) / 2 >= p.y) 
        { 
            if (arbol_arriba_izquierdo == NULL) 
                return NULL; 
            return arbol_arriba_izquierdo->buscar(p); 
        } 
  
        // Indicates arbol_bajo_izquierdo 
        else
        { 
            if (arbol_bajo_izquierdo == NULL) 
                return NULL; 
            return arbol_bajo_izquierdo->buscar(p); 
        } 
    } 
    else
    { 
        // Indicates arbol_arriba_derecho 
        if ((topLeft.y + botRight.y) / 2 >= p.y) 
        { 
            if (arbol_arriba_derecho == NULL) 
                return NULL; 
            return arbol_arriba_derecho->buscar(p); 
        } 
  
        // Indicates arbol_bajo_derecho 
        else
        { 
            if (arbol_bajo_derecho == NULL) 
                return NULL; 
            return arbol_bajo_derecho->buscar(p); 
        } 
    } 
}; 
  
// Valora si el punto esta en el boundary del Quadtree 
bool Quadtree::en_region(Punto p) 
{ 
    return (p.x >= topLeft.x && 
        p.x <= botRight.x && 
        p.y >= topLeft.y && 
        p.y <= botRight.y); 
} 
  


```