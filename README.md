# RESULTADOS TRABAJO EN COMPUTACION GRAFICA

## Tabla de contenido
- [Algoritmo Incremental](#algoritmo-incremental).
  - [Imagen](#imagen).
  - [Codigo](#codigo).
- [Recta Punto Medio](#grafica-de-la-recta-con-punto-medio).
  - [Imagen](#imagen).
  - [Codigo](#codigo).
  

  
  
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


