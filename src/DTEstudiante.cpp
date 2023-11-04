#include "../include/DTEstudiante.h"
#include "../include/DTInscripcion.h"
#include "../include/Inscripcion.h"

DTEstudiante::DTEstudiante(string Nickname, string Contraseña, string Nombre, string Descripcion, string Pais, DTFecha * FechaNac):DTUsuario(Nickname, Contraseña,  Nombre, Descripcion){
    this->Pais = Pais;
    this->Fecha = FechaNac;
};

DTEstudiante::DTEstudiante(Estudiante* estudiante):DTUsuario(estudiante->getNickname(), estudiante->getContraseña(),  estudiante->getNombre(), estudiante->getDescripcion()){
    this->Pais = estudiante->getPais();
    this->Fecha = estudiante->getFechaNac();
    this->Inscripciones = new map<string, DTInscripcion*>;

     for(map<string, Inscripcion*>::iterator it = estudiante->getInscripciones()->begin(); it != estudiante->getInscripciones()->end(); it++){
        DTInscripcion* inscripcion = new DTInscripcion(it->second);

        this->Inscripciones->insert(pair<string, DTInscripcion*>(it->first, inscripcion));
     }
};

string DTEstudiante:: getNickname(){return  DTUsuario::getNickname();};

string DTEstudiante:: getContraseña(){return  DTUsuario::getContraseña();};

string DTEstudiante:: getDescripcion(){return  DTUsuario::getDescripcion();};

string DTEstudiante:: getPais(){return this->Pais;};

DTFecha * DTEstudiante:: getFechaNac(){return this->Fecha;};

string DTEstudiante:: getNombre(){return  DTUsuario::getNombre();};

DTInscripcion* DTEstudiante::getInscripcionACurso(string nombreCurso){
    return this->Inscripciones->find(nombreCurso)->second;
}
DTEstudiante:: ~DTEstudiante(){};

