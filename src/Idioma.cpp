#include "../include/Idioma.h"
#include "../include/Curso.h"
#include "../include/Estudiante.h"
#include "../include/DTNotificacion.h"


Idioma:: Idioma(string nombre){
    this->Nombre = nombre;
    this->observers = new set<Usuario*>;
    this->Cursos = new map<string, Curso*>;
};

string Idioma:: getNombre(){
    return this->Nombre;
};

void Idioma:: AgregarSuscriptor(Usuario * u){
    this->observers->insert(u);
};

void Idioma:: removerUsuario(string nomUsuario){
    ManejadorUsuario * mu;
    mu = ManejadorUsuario::getInstancia();
    Usuario * u;
    u = mu->obtenerUsuario(nomUsuario);
    this->observers->erase(u);
};

set<DTCurso*>* Idioma::getDataCursosHab(){
    set<DTCurso*>* dataCursos = new set<DTCurso*>;
    for(map<string, Curso*>::iterator it = this->Cursos->begin(); it != this->Cursos->end(); it++){
        if (it->second->getHabilitado()){
            DTCurso* dataCurso = it->second->getDataCurso();
            dataCursos->insert(dataCurso);
        };
    };
    if (dataCursos->empty()){
        delete dataCursos;
        return NULL;
    }else
        return dataCursos;
};

//void Idioma::agregar(Usuario observer){};

//void Idioma::eliminar(Usuario observer){};

void Idioma::EnviarNotificacion(Curso* curso){
    for (set<Usuario*>::iterator it = this->observers->begin(); it != this->observers->end(); it++){
        DTNotificacion* DTnuevocurso = new DTNotificacion(curso);
        Usuario* user = *it;
        user->notificar(DTnuevocurso);
    };
};

void Idioma::asociarCursoIdioma(Curso* curso){
    this->Cursos->insert(pair<string, Curso*>(curso->getNombre(), curso));
};

void Idioma::removerCurso(string nombreCurso){
    this->Cursos->erase(nombreCurso);
}

Idioma::~Idioma(){};
