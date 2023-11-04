#include <iostream>
#include "Ejercicio.h"
#include <set>
using namespace std;
#ifndef TRADUCIR
#define TRADUCIR

class Traducir: public Ejercicio
{
private:
    string FraseATraducir;
    string FraseCorrecta;
public:
    Traducir(int id, string descricion, string fraseatraducir, string frasecorrecta);
    string getFraseATraducir();
    string getFraseCorrecta();
    bool ingresarSolucion(string solucion);
    ~Traducir();
};

#endif
