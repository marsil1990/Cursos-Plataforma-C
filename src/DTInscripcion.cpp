#include "../include/DTInscripcion.h"
#include "../include/Inscripcion.h"
#include "../include/DTEstudiante.h"
#include "../include/DTCurso.h"

DTInscripcion::DTInscripcion(DTFecha* fechaInscripcion, DTCurso* curso, DTEstudiante* estudiante){
    this->EstudianteInscripto = estudiante;
    this->FechaDeInscripcion = fechaInscripcion;
    this->CursoInscripto = curso;
}

DTInscripcion::DTInscripcion(Inscripcion* inscripcion){
    //sthis->CursoInscripto = new DTCurso(inscripcion->getCursoInscripto());
    //this->EstudianteInscripto = new DTEstudiante(inscripcion->getEstudianteInscripto());
    this->FechaDeInscripcion = inscripcion->getFechaDeInscripcion();
}

DTFecha* DTInscripcion::getFechaDeInscripcion(){
    return this->FechaDeInscripcion;
};

DTCurso* DTInscripcion::getCursoInscripto(){
    return this->CursoInscripto;
};

DTEstudiante* DTInscripcion::getEstudianteInscripto(){
    return this->EstudianteInscripto;
};

DTInscripcion::~DTInscripcion(){};
