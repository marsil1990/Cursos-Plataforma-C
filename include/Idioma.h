#include "Usuario.h"
#include "DTCurso.h"
#include <map>
#include <iostream>
using namespace std;
#ifndef IDIOMA
#define IDIOMA
class Curso;
class ManjadorUsuario;
class ManjadorCurso;

class Idioma 
{
private:
    string Nombre;
    set<Usuario*>* observers;
    map<string, Curso*>* Cursos;
    
public:
    Idioma(string Nombre);
    string getNombre();
    void AgregarSuscriptor(Usuario *u);
    void removerUsuario(string nomUsuario);
    set<DTCurso*>* getDataCursosHab();
    //void agregar(Usuario observer);
    //void eliminar(Usuario observer);
    void EnviarNotificacion(Curso* curso);
    void asociarCursoIdioma(Curso* curso);
    void removerCurso(string nombreCurso);
    ~Idioma();
};

#include "ManejadorUsuario.h"
#include "ManejadorCurso.h"
#include "Curso.h"

#endif
