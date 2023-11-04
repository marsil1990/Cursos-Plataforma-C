#include "DTFecha.h"
#include <iostream>
using namespace std;
#include <string>
#ifndef DTINSCRIPCION
#define DTINSCRIPCION

class Inscripcion;
class DTEstudiante;
class DTCurso;

class DTInscripcion
{
private:
    DTFecha* FechaDeInscripcion; 
    DTCurso* CursoInscripto;
    DTEstudiante* EstudianteInscripto;
public:
    DTInscripcion();
    DTInscripcion(DTFecha* fecha, DTCurso* curso, DTEstudiante* estudiante);
    DTInscripcion(Inscripcion* inscripcion);
    DTFecha* getFechaDeInscripcion();
    DTCurso* getCursoInscripto();
    DTEstudiante* getEstudianteInscripto();
    ~DTInscripcion();
};

#endif