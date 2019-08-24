#ifndef ABB_H
#define ABB_H

#include "nodoabb.h"

#include <iostream>

class abb
{
    public:
        nodoabb *raiz;

        abb();
        void insertar(string name);
        void add(nodoabb *r, string name);
        void eliminar(string name);
        nodoabb* del(nodoabb *r, string name);
        nodoabb* maxMin(nodoabb *r);
        void graficar();
        void nodos(nodoabb *r, FILE **f);
        void link(nodoabb *r, FILE **f);
};

#endif // ABB_H