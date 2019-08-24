#ifndef NODOABB_H
#define NODOABB_H

#include <string>
using namespace std;

class nodoabb
{
    public:
        string nombre;
        nodoabb *hi;
        nodoabb *hd;

        nodoabb(string n)
        {
            nombre = n;
            hi = NULL;
            hd = NULL;
        }
};

#endif // NODOABB_H