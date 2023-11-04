#include "Usuario.h"
#include "DTFecha.h"
#include "Inscripcion.h"
#include <map>
# include <iostream>
using namespace std;
#ifndef ESTUDIANTE
#define ESTUDIANTE
class Estudiante : public Usuario
{
private:
    string Pais;
    DTFecha *FechaNac;
    set<DTNotificacion*>* Notificaciones;
    map<string, Curso*>* CursosInscriptos;
    map<string, Inscripcion*>* Inscripciones;
public:
    Estudiante (string Nickname, string Contraseña, string Nombre, string Descripcion, string Pais, DTFecha * FechaNac);
    string getPais();
    DTFecha* getFechaNac();
    map<string, Curso*>* ObtenerCursosInscriptos();
    void notificar(DTNotificacion* DTnuevocurso);
    map<string, Inscripcion*>* getInscripciones();
    void inscribirseCurso(string nombreCurso,Curso* curso,bool aprobarCurso = false, DTFecha * f= NULL);
    set<string>* ObtenerNomIdiomaSuscrito(); 
    set<DTNotificacion>* DevolverNotificaciones();
    map<string,Curso*>* obtenerCursos();
    Inscripcion* getInscripcion(string cursoNombre);
    void removerCurso(string nombreCurso);
    virtual ~Estudiante();
};

#endif
