#include "Curso.h"
#include "Leccion.h"
#include "Ejercicio.h"
#include <iostream>
using namespace std;
#include <string>
#include <set>
#include <map>
#ifndef MANEJADORCURSO
#define MANEJADORCURSO

class Curso;
class Ejercicio;

class ManejadorCurso
{
private: 
    static ManejadorCurso *instancia;
    map<string, Curso*>* Cursos;
    ManejadorCurso();
public:
    static ManejadorCurso* getInstancia();
    Curso* obtenerCurso(string nombreCurso);
    set<string>* obtenerCursosDisponibles();
    bool ExisteCurso(string nombreCurso);
    set<DTCurso*>* obtenerCursosNoHab();
    set<Curso>* CursosInscriptoNoAprobado();
    set<Ejercicio>* ejerciciosNoAprobados();
    set<Curso*>* obtenerCursos(set<string>* nombreCursos);
    void eliminarPrevia(string NomCurso);
    void agregarCurso(Curso* curso);
    map<string,Curso*>* obtenerTodosCursos();
    void eliminarCurso(string nombreCurso);
};

#endif
