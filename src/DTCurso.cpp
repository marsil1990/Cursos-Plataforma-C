#include "../include/DTCurso.h"
#include "../include/Curso.h"
#include "../include/DTEstudiante.h"
#include "../include/Estudiante.h"
DTCurso::DTCurso(string nombre, string descripcion, string nombreProfesor, string nombreIdomaCurso, bool estado){
    this->Nombre = nombre;
    this->Descripcion = descripcion;
    this->NombreProfesor = nombreProfesor;
    this->NombreIdiomaCurso = nombreIdomaCurso;
    this->Estado = estado;
    this->inscriptos = NULL;
};

DTCurso::DTCurso(Curso* curso){
    this->Nombre = curso->getNombre();
    this->Descripcion = curso->getDescripcion();
    this->cantEjercicios = curso->getCantEjercicios();
    Nivel nivel = curso->getDificultad();
    this->NombreIdiomaCurso = curso->getIdioma();
    this->NombreProfesor = curso->getProfesor();
    this->Estado = curso->getHabilitado();
    this->cantLecciones = curso->getCantLecciones();
    this->cantInscriptos = curso->getCantInscriptos();
    this->inscriptos = new map<string, DTEstudiante*>;
    
    map<string, Estudiante*>* estudiantes = curso->getEstudiantes();
    for(map<string, Estudiante*>::iterator it = estudiantes->begin(); it != estudiantes->end(); it++){
        DTEstudiante* estudiante = new DTEstudiante(it->second);

        this->inscriptos->insert(pair<string, DTEstudiante*>(it->first, estudiante));
    }

    switch (nivel)
    {
    case Principiante:
        this->Dificultad = "Principiante";
        break;
    case Intermedio:
        this->Dificultad = "Intermedio";
        break;

    case Avanzado:
        this->Dificultad = "Avanzado";
        break;
       
    default:
        break;
    }
}

string DTCurso::getNombre(){
    return this->Nombre;
};

string DTCurso::getDesc(){
    return this->Descripcion;
};

string DTCurso::getDificultad(){
    return this->Dificultad;
};

string DTCurso::getNombreProfesor(){
    return this->NombreProfesor;
};

bool DTCurso::getHabilitado(){
    return this->Estado;
};

string DTCurso::getNombreIdiomaCurso(){
    return this->NombreIdiomaCurso;
};

int DTCurso::getcantLecciones(){
    return this->cantLecciones;
};
int DTCurso::getcantEjercicios(){
    return this->cantEjercicios;
};

int DTCurso::getCantInscriptos(){
    return this->cantInscriptos;
}

map<string, DTEstudiante*>* DTCurso::getEstudiantesInscriptos(){
    return this->inscriptos;
}

DTCurso::~DTCurso(){};
