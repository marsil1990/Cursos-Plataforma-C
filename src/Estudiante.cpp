#include "../include/Estudiante.h"
#include "../include/Inscripcion.h"
#include <chrono>
#include <ctime>



Estudiante::Estudiante (string nickname, string contraseña, string nombre, string descripcion, string pais, DTFecha * fecha):Usuario( nickname,  contraseña,  nombre, descripcion){
    this->Pais = pais;
    this->FechaNac = fecha;
    this->CursosInscriptos = new map<string,Curso*>;
    this->Inscripciones = new map<string, Inscripcion*>;
};

string Estudiante::getPais(){
    return this->Pais;
};

DTFecha * Estudiante::getFechaNac(){
    return this->FechaNac;
};

set<string>* Estudiante::ObtenerNomIdiomaSuscrito(){return NULL;};

set<DTNotificacion>* DevolverNotificaciones(){return NULL;};

map<string, Curso*>* Estudiante::ObtenerCursosInscriptos(){
   
    if(this->CursosInscriptos->empty()){
        return NULL;
    }
    return this->CursosInscriptos;
};

map<string, Inscripcion*>* Estudiante::getInscripciones(){
    return this->Inscripciones;
};

void Estudiante::inscribirseCurso(string nombreCurso,Curso* curso,bool aprobarCurso, DTFecha * f){

    DTFecha* h; 
    if(f==NULL ) h = new DTFecha(2023,6, 22);
    else h = f;
    Inscripcion* nuevaInscripcion = new Inscripcion(h,curso,this);
    if(aprobarCurso){
        nuevaInscripcion->setAprobada(true);
    }
    this->CursosInscriptos->insert(pair<string, Curso*>(nombreCurso, curso));
    this->Inscripciones->insert(pair<string, Inscripcion*>(nombreCurso, nuevaInscripcion));
    curso->inscribirEstudiante(this);
};

map<string,Curso*>* Estudiante::obtenerCursos(){
    return this->CursosInscriptos;
};

Inscripcion* Estudiante::getInscripcion(string cursoNombre){
    return this->Inscripciones->find(cursoNombre)->second;
}
 
Estudiante::~Estudiante(){

};

void Estudiante::removerCurso(string nombreCurso){
    Inscripcion* inscripcion = this->Inscripciones->find(nombreCurso)->second;

    this->CursosInscriptos->erase(nombreCurso);
    this->Inscripciones->erase(nombreCurso);

    inscripcion->~Inscripcion();
}