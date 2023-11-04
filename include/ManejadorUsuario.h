# include "Usuario.h"
# include "Curso.h"
# include "Estudiante.h"
# include <iostream>
using namespace std;
#include <set>
#include <map>

#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO
class ManejadorUsuario
{
private:
    static ManejadorUsuario *instancia;
    map<string, Usuario*>* Usuarios;
    ManejadorUsuario();
public:
    static ManejadorUsuario *getInstancia();
    bool ExisteUsuario(string nickname);
    void agregarUsuario(Usuario* nuevoUsuario);
    Usuario* obtenerUsuario(string nickname);
    set<Estudiante*> *obtenerEstudiantes();
    set<Profesor*> *obtenerProfesores();
    set<string> *obtenerNombres();
    set<string> *obtenerNickname();
    set<string> *obtenerNombresProfesor();
    void agregarCursoColeccion(Curso curso);
    void aprobarEjercicio(Ejercicio* ejercicio, string nickname, string nombreCurso);
    ~ManejadorUsuario();
};
#endif
