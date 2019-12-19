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