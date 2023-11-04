#include "../include/DTLeccion.h"

DTLeccion::DTLeccion (int orden, string tema, string objetivo){
    this->Orden = orden;
    this->Tema = tema;
    this->Objetivo = objetivo;
};

int DTLeccion::getOrden(){
    return this->Orden;
};

string DTLeccion::getTema(){
    return this->Tema;
};

string DTLeccion::getObjetivo(){
    return this->Objetivo;
};

DTLeccion::~DTLeccion(){

};