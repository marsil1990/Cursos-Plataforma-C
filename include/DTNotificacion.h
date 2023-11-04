# include <iostream>
#include <string>
using namespace std;
#ifndef DTNOTIFICACION
#define DTNOTIFICACION

class Curso;

class DTNotificacion
{
private:
    string NombreCurso;
    string NombreIdioma;
public:
    DTNotificacion (Curso *curso);
    string getNombreCurso();
    string getNombreIdioma();
    ~DTNotificacion();
};

#include "Curso.h"

#endif
