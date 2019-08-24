using namespace std;

#include "abb.cpp"

int main()
{
    abb *arbolABB = new abb();
    string salto = "";

    //1
    arbolABB->insertar("luigi");
    arbolABB->insertar("hammer");
    arbolABB->insertar("mario");
    arbolABB->insertar("peach");
    arbolABB->insertar("pow");
    arbolABB->insertar("fermin");
    arbolABB->graficar();
    cout << "Instruccion 1 graficada" << endl;
    cin >> salto;

    //2
    arbolABB->eliminar("peach");
    arbolABB->graficar();
    cout << "Instruccion 2 graficada" << endl;
    cin >> salto;
    
    //3
    arbolABB->insertar("shy_guy");
    arbolABB->insertar("edd");
    arbolABB->graficar();
    cout << "Instruccion 3 graficada" << endl;
    cin >> salto;
    
    //4
    arbolABB->eliminar("pow");
    arbolABB->graficar();
    cout << "Instruccion 4 graficada" << endl;
    cin >> salto;
    
    //5
    arbolABB->insertar("Boo");
    arbolABB->insertar("Kamek");
    arbolABB->insertar("star");
    arbolABB->insertar("whomp");
    arbolABB->graficar();
    cout << "Instruccion 5 graficada" << endl;
    cin >> salto;
    
    //6
    arbolABB->eliminar("shy_guy");
    arbolABB->graficar();
    cout << "Instruccion 6 graficada" << endl;
    cin >> salto;
    
    //7
    arbolABB->eliminar("mario");
    arbolABB->graficar();
    cout << "Instruccion 7 graficada" << endl;
    
    return 0;
}