# include "../include/DTNotificacion.h"


DTNotificacion::DTNotificacion (Curso* curso){
    this->NombreCurso = curso->getNombre();
    this->NombreIdioma = curso->getIdioma();
};

string DTNotificacion::getNombreCurso(){
    return this->NombreCurso;
};

string DTNotificacion::getNombreIdioma(){
    return this->NombreIdioma;
};

DTNotificacion::~DTNotificacion(){

};


