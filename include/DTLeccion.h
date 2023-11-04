#include <iostream>
using namespace std;
#ifndef DTLECCION
#define DTLECCION
class DTLeccion
{
private:
    int Orden;
    string Tema;
    string Objetivo;
public:
    DTLeccion (int orden, string tema, string objetivo);
    int getOrden();
    string getTema();
    string getObjetivo();
    ~DTLeccion();
};

#endif
