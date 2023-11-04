#include <iostream>
#include "Ejercicio.h"
#include <set>
using namespace std;
#ifndef COMPLETARPALABRA
#define COMPLETARPALABRA

class CompletarPalabra: public Ejercicio
{
private:
    string Frase;
    map<int, string>* PalabrasFaltantes;
public:
    CompletarPalabra(int id, string descricion, string frase, map<int, string>* palabrasfaltantes);
    string getFrase();
    map<int, string>* getPalabrasFaltantes();
    bool ingresarSolucion(map<int, string>* solucion);
    ~CompletarPalabra();
};

#endif
