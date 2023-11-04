#include "Usuario.h"
#include "Leccion.h"
#include "Curso.h"
#include "DTFecha.h"
#include <map>
# include <iostream>
using namespace std;
#ifndef INSCRIPCION
#define INSCRIPCION

class Estudiante; 

class Inscripcion 
{
private:
    Leccion* UltimaLeccionAprobada;
    DTFecha* FechaDeInscripcion; 
    Curso* CursoInscripto;
    bool Aprobada;
    Estudiante* EstudianteInscripto;
public:
    Inscripcion(DTFecha* fecha,Curso* curso,Estudiante* estudiante);
    Leccion* getUltimaLeccionAprobada();
    DTFecha* getFechaDeInscripcion();
    bool getAprobada();
    Curso* getCursoInscripto();
    Estudiante* getEstudianteInscripto();
    void setAprobada(bool aprobada);    
    void setNuevaLeccionAprobada(Leccion* leccion);
    virtual ~Inscripcion();
};

#endif




