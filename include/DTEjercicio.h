#include <iostream>
#include "Ejercicio.h"
using namespace std;
#ifndef DTEJERCICIO
#define DTEJERCICIO

class DTEjercicio
{
private:
    int Id;
    string Descripcion;

public:
    DTEjercicio(int id, string descripcion);
    DTEjercicio(Ejercicio* ejercicio);
    string getDescripcion();
    virtual ~DTEjercicio();
};

#endif