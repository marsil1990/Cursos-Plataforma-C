#include "DTEstudiante.h"
#include <iostream>
using namespace std;
#include <string>
#include <map>
#ifndef DTCURSO
#define DTCURSO

class Curso;

class DTCurso
{
private:
    string Nombre;
    string Descripcion;
    string Dificultad;
    string NombreProfesor;
    string NombreIdiomaCurso;
    map<string, DTEstudiante*>* inscriptos;
    bool Estado;
    int cantLecciones;
    int cantEjercicios;
    int cantInscriptos;
public:
    DTCurso();
    DTCurso(string nombre, string descripcion, string nombreProfesor, string nombreIdomaCurso, bool estado);
    DTCurso(Curso* curso);
    string getNombre();
    string getDesc();
    string getDificultad();
    string getNombreProfesor();
    string getNombreIdiomaCurso();    
    bool getHabilitado();
    int getcantLecciones();
    int getcantEjercicios();
    int getCantInscriptos();
    map<string, DTEstudiante*>* getEstudiantesInscriptos();
    ~DTCurso();
};

#endif
