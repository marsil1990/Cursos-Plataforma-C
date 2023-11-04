#include "../include/ManejadorCurso.h"

ManejadorCurso* ManejadorCurso::instancia = NULL;

ManejadorCurso::ManejadorCurso(){
    this->Cursos = new map<string, Curso*>;
};

ManejadorCurso* ManejadorCurso::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorCurso();
    return instancia;
};

Curso* ManejadorCurso::obtenerCurso(string nombreCurso){
    return this->Cursos->find(nombreCurso)->second;
};
bool ManejadorCurso::ExisteCurso(string nombreCurso){
    map<string, Curso*>::iterator it = this->Cursos->find(nombreCurso);
    if (it == this->Cursos->end())
        return false;
    else 
        return true;
};
set<string>* ManejadorCurso::obtenerCursosDisponibles(){
    set<string>* cursosDisponibles = new set<string>;
    for (map<string, Curso*>::iterator it = this->Cursos->begin(); it != this->Cursos->end(); it++)
        cursosDisponibles->insert(it->second->getNombre());
    if (cursosDisponibles->empty()){
        delete cursosDisponibles;
        return NULL;
    }
    else
        return cursosDisponibles;
};



set<Curso*>* ManejadorCurso::obtenerCursos(set<string>* nombreCursos){
    set<Curso*>* previas = new set<Curso*>;
    for(set<string>::iterator it = nombreCursos->begin(); it != nombreCursos->end(); it++)
        previas->insert(this->Cursos->find(*it)->second);
    return previas;
};

set<DTCurso*>* ManejadorCurso::obtenerCursosNoHab(){
    set<DTCurso*>* nombreCursos = new set<DTCurso*>;
    for(map<string, Curso*>::iterator it = Cursos->begin(); it != Cursos->end(); it++){
        if (!it->second->getHabilitado())
            nombreCursos->insert(it->second->getDataCurso());
    }
    if (nombreCursos->empty()){
        delete nombreCursos;
        return NULL;
    }
    else
        return nombreCursos;
};

set<Curso>* ManejadorCurso::CursosInscriptoNoAprobado(){return NULL;};

set<Ejercicio>* ManejadorCurso::ejerciciosNoAprobados(){return NULL;};

void ManejadorCurso::agregarCurso(Curso* curso){
    this->Cursos->insert(pair<string, Curso*>(curso->getNombre(), curso));
};

map<string,Curso*>* ManejadorCurso::obtenerTodosCursos() {
    map<string, Curso*>* cursosDisponibles=new map<string,Curso*>;
    for (map<string, Curso*>::iterator it = this->Cursos->begin(); it != this->Cursos->end(); it++){
        cursosDisponibles->insert(pair<string, Curso*>(it->second->getNombre(),it->second));
    }     
    return cursosDisponibles;
};

void ManejadorCurso::eliminarPrevia(string nomCurso){
    for (map<string, Curso*>::iterator it = this->Cursos->begin(); it != this->Cursos->end(); it++){
        it->second->eliminarPrevias(nomCurso);
    }   

}
void ManejadorCurso::eliminarCurso(string nombreCurso){
    this->Cursos->erase(nombreCurso);
}
