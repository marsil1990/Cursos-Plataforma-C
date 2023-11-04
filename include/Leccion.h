#include "DTEjercicio.h"
#include "Ejercicio.h"
#include "Traducir.h"
#include "CompletarPalabra.h"
#include <iostream>
using namespace std;
#include <set>
#include <map>
#ifndef LECCION
#define LECCION

class DTEjercicio;

class Leccion
{
private:
    int Orden;
    string Tema;
    string Objetivo;
    map<int, Ejercicio*>* Ejercicios;
public:
    Leccion(int orden, string tema, string objetivo);
    Leccion(int orden, string tema, string objetivo, map<int, Ejercicio*>* ejercicios);
    int getOrden();
    string getTema();
    string getObjetivo();
    void añadirEjercicio(string descripcion, string frase, map<int, string>* respuesta);
    void añadirEjercicio(string descripcion, string frase, string traduccion);
    void contarEjercicios(float &tot, float &ap, string nickestudiante);
    set<DTEjercicio>* obtenerNoAprobados();
    string obtenerEjercicio(string nombreEjercicio);
    int getCantEjercicios();
    void setOrden(int orden);
    map<int, Ejercicio*>* getColEjercicios();
    void eliminarEjercicios();
    ~Leccion();
};

#endif