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
    Punto topLeft; // delimitacion
    Punto botRight; // delimitacion
  
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
  
int main() 
{ 

    return 0; 
} 
