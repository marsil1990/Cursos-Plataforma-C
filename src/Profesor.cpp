#include "../include/Profesor.h"
#include "../include/Curso.h"

Profesor::Profesor(string nickname, string contraseña, string nombre, string descripcion, string instituto):Usuario (nickname, contraseña, nombre, descripcion){
    this->Instituto = instituto;
    this->Especializacion = new map<string, Idioma*>;
    this->Cursos = new map<string,Curso*>;
};

string Profesor::getInstituto(){
    return this->Instituto;
};

void Profesor::AgregarEspecializacion(Idioma* idioma){
    this->Especializacion->insert(pair<string, Idioma*>(idioma->getNombre(), idioma));
};

set<string>* Profesor::obtenerEspecializaciones(){
    set<string>* especializaciones = new set<string>;       
    for (map<string, Idioma*>::iterator it = this->Especializacion->begin(); it != this->Especializacion->end(); it++)
        especializaciones->insert(it->first);
    if (especializaciones->empty())
        return NULL;
    else
        return especializaciones;
};

void Profesor::asociarCursoProfesor(Curso* curso){
    this->Cursos->insert(pair<string,Curso*>(curso->getNombre(),curso));
};
map<string,Curso*>* Profesor::obtenerCursos(){
    return this->Cursos;
};

void Profesor::eliminarCurso(string nombreCurso){
    this->Cursos->erase(nombreCurso);
}

Profesor::~Profesor(){
    
};

