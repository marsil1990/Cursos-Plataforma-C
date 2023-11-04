#include "../include/Ejercicio.h"
#include "../include/Inscripcion.h"

Ejercicio::Ejercicio(int id, string descripcion){
    this->Id = id;
    this->Descripcion = descripcion;
    this->EstudiantesAprovaron = new map<string,Inscripcion*>;
};

int Ejercicio::getId(){
    return this->Id;
};

string Ejercicio::getDescripcion(){
    return this->Descripcion;
};
bool Ejercicio::esAprovado(string nickEstudiante){
    map<string, Inscripcion*>::iterator it = this->EstudiantesAprovaron->find(nickEstudiante);
    if (it == this->EstudiantesAprovaron->end())
        return false;
    else 
        return true;
};

void Ejercicio::addEstudianteAprobado(Inscripcion* inscripcion){
    Usuario* estudiante = inscripcion->getEstudianteInscripto();
    this->EstudiantesAprovaron->insert(pair<string, Inscripcion*>(estudiante->getNickname(), inscripcion));
};


Ejercicio::~Ejercicio(){

};