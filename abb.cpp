#include "abb.h"

abb::abb()
{
    raiz = NULL;
}

void abb::insertar(string name)
{
    if(raiz != NULL)
    {
        add(raiz,name);
    } else
    {
        raiz = new nodoabb(name);
    }
    
}
void abb::add(nodoabb *r, string name)
{
    if(name < r->nombre)
    {
        if(r->hi != NULL)
        {
            add(r->hi,name);
        } else
        {
            r->hi = new nodoabb(name);
        }
    } else if(name > r->nombre)
    {
        if(r->hd != NULL)
        {
            add(r->hd,name);
        } else
        {
            r->hd = new nodoabb(name);
        }
        
    }
    
}

void abb::eliminar(string name)
{
    raiz = del(raiz,name);
}
nodoabb* abb::del(nodoabb *r, string name)
{
    if(r == NULL)
    {
        return r;
    }
    if(name < r->nombre)
    {
        r->hi = del(r->hi,name);
    } else if(name > r->nombre)
    {
        r->hd = del(r->hd,name);
    } else
    {
        if(r->hi == NULL)
        {
            nodoabb *temp = r->hd;
            free(r);
            return temp;
        } else if(r->hd == NULL)
        {
            nodoabb *temp = r->hi;
            free(r);
            return temp;
        }

        nodoabb *temp = maxMin(r->hi);
        r->nombre = temp->nombre;
        r->hi = del(r->hi,temp->nombre);
    }
    return r;
}

nodoabb* abb::maxMin(nodoabb *r)
{
    nodoabb *act = r;
    while(act && (act->hd != NULL))
    {
        act = act->hd;
    }
    return act;
}

void abb::graficar()
{
    FILE *f = fopen("ArbolABB.dot","w+");
    if(f)
    {
        fprintf(f,"digraph ABB \r\n");
        fprintf(f,"{\r\n");
        fprintf(f,"\trankdir=TB;\r\n");
        fprintf(f,"\tgraph [splines=ortho, nodesep=0.5];\r\n");
        fprintf(f,"\tnode [shape=record; style=filled, fillcolor=beige,width=0.5,height=0.2];\r\n");
        fprintf(f,"\r\n");
        if(raiz != NULL)
        {
            nodos(raiz,&f);
            fprintf(f,"\r\n");
            link(raiz,&f);
        } else
        {
            fprintf(f,"\t\"Arbol vacio\"");
        }
        fprintf(f,"}");
        fclose(f);
        system("dot -Tpng ArbolABB.dot -o ArbolABB.png");
        system("eog ArbolABB.png");
    } else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

void abb::nodos(nodoabb *r, FILE **f)
{
    if(r != NULL)
    {
        fprintf(*f,"\tn%s[label=\"<C0>|%s|<C1>\"];\r\n",r->nombre.c_str(),r->nombre.c_str());
        nodos(r->hi,&(*f));
        nodos(r->hd,&(*f));
    }
}

void abb::link(nodoabb *r, FILE **f)
{
    if(r != NULL)
    {
        if(r->hi != NULL)
        {
            fprintf((*f),"\tn%s:C0->n%s;\r\n",r->nombre.c_str(),r->hi->nombre.c_str());
        }
        if(r->hd != NULL)
        {
            fprintf((*f),"\tn%s:C1->n%s;\r\n",r->nombre.c_str(),r->hd->nombre.c_str());
        }
        link(r->hi,&(*f));
        link(r->hd,&(*f));
    }
}