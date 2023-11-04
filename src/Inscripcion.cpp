#include "../include/Inscripcion.h"
#include "../include/Estudiante.h"
#include "../include/Curso.h"
#include "../include/DTFecha.h"



Inscripcion::Inscripcion(DTFecha* fechaInscripcion,Curso* curso,Estudiante* estudiante){
    this->Aprobada = false;
    this->EstudianteInscripto = estudiante;
    this->FechaDeInscripcion = fechaInscripcion;
    this->CursoInscripto = curso;
    this->UltimaLeccionAprobada = NULL;
}

Leccion* Inscripcion::getUltimaLeccionAprobada(){
    return this->UltimaLeccionAprobada;
};

DTFecha* Inscripcion::getFechaDeInscripcion(){
    return this->FechaDeInscripcion;
};

bool Inscripcion::getAprobada(){
    return this->Aprobada;
};

Curso* Inscripcion::getCursoInscripto(){
    return this->CursoInscripto;
};

Estudiante* Inscripcion::getEstudianteInscripto(){
    return this->EstudianteInscripto;
};

void Inscripcion::setAprobada(bool aprobada){
    this->Aprobada = aprobada;
};

void Inscripcion::setNuevaLeccionAprobada(Leccion* leccion){
    this->UltimaLeccionAprobada = leccion;
}

Inscripcion:: ~Inscripcion(){

};
