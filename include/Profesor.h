#include "Usuario.h"
#include "Idioma.h"
# include <iostream>
#include <map>
using namespace std;
#ifndef PROFESOR
#define PROFESOR

class Idioma;
class Curso;

class Profesor: public Usuario
{
private:
    string Instituto;
    map<string, Idioma*>* Especializacion;
    map<string,Curso*>* Cursos;
public:
    Profesor(string nickname, string contraseña, string nombre, string descripcion, string instituto);
    string getInstituto();
    void AgregarEspecializacion(Idioma* idioma);
    set<string>* obtenerEspecializaciones();
    void asociarCursoProfesor(Curso* curso);
    map<string,Curso*>* obtenerCursos();
    void eliminarCurso(string nombreCurso);
    ~Profesor();
};

#endif
