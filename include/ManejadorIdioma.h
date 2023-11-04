#include "Idioma.h"
#include "DTCurso.h"
# include <iostream>
#include <set>
#include <map>
using namespace std;
#ifndef MANEJADORIDIOMA
#define MANEJADORIDIOMA

class ManejadorIdioma
{
private:
    static ManejadorIdioma *instancia;
    map<string, Idioma*>* Idiomas;
    ManejadorIdioma();
public:
    static ManejadorIdioma* getInstancia();
    void agregarIdioma(Idioma* idioma);
    set<string>* IdiomasDisponibles();
    Idioma *obtenerIdioma(string nombreIdioma);
    bool existeIdioma(string nombreIdioma);
    ~ManejadorIdioma();
};

#endif
