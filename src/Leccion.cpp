#include "../include/Leccion.h"

Leccion::Leccion(int orden, string tema, string objetivo){
    this->Orden = orden;
    this->Tema = tema;
    this->Objetivo = objetivo;
    this->Ejercicios = new map<int, Ejercicio*>;
};

Leccion::Leccion(int orden, string tema, string objetivo, map<int, Ejercicio*>* ejercicios){
    this->Orden = orden;
    this->Tema = tema;
    this->Objetivo = objetivo;
    this->Ejercicios = ejercicios;
};

int Leccion::getOrden(){
    return this->Orden;
};

string Leccion::getTema(){
    return this->Tema;
};
string Leccion::getObjetivo(){
    return this->Objetivo;
};

void Leccion::añadirEjercicio(string descripcion, string frase, map<int, string>* respuesta){
    Ejercicio* ejercicioNuevo = new CompletarPalabra(this->Ejercicios->size() + 1, descripcion, frase, respuesta);
    this->Ejercicios->insert(pair<int, Ejercicio*>(ejercicioNuevo->getId(), ejercicioNuevo));
};

void Leccion::añadirEjercicio(string descripcion, string frase, string traduccion){
    Ejercicio* ejercicioNuevo = new Traducir(this->Ejercicios->size() + 1, descripcion, frase, traduccion);
    this->Ejercicios->insert(pair<int, Ejercicio*>(ejercicioNuevo->getId(), ejercicioNuevo));
};

void Leccion::contarEjercicios(float &tot, float &ap, string nickestudiante){
      for(map<int,Ejercicio*>::iterator it= this->Ejercicios->begin();it!= this->Ejercicios->end();it++){
        tot++;
        bool apro = it->second->esAprovado(nickestudiante);
        if(apro){ap++;}
    }
};

set<DTEjercicio>* obtenerNoAprobados(){return NULL;};

string obtenerEjercicio(string nombreEjercicio){return NULL;};

int Leccion::getCantEjercicios(){
    return this->Ejercicios->size();
};

void Leccion::setOrden(int orden){
    this->Orden = orden;
};

map<int, Ejercicio*>* Leccion::getColEjercicios(){
    return Ejercicios;
}

void Leccion::eliminarEjercicios(){
    this->Ejercicios->clear();
}

Leccion::~Leccion(){};  