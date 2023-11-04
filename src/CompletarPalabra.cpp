#include "../include/CompletarPalabra.h"

CompletarPalabra::CompletarPalabra(int id, string descripcion, string frase, map<int, string>* palabrasfaltantes):Ejercicio(id, descripcion){
    this->Frase = frase;
    this->PalabrasFaltantes = palabrasfaltantes;
};

string CompletarPalabra::getFrase(){
    return this->Frase;
};

map<int, string>* CompletarPalabra::getPalabrasFaltantes(){
    return this->PalabrasFaltantes;
};

bool CompletarPalabra::ingresarSolucion(map<int, string>* solucion){
    bool correcto = true;
    for (map<int, string>::iterator it = this->PalabrasFaltantes->begin(); it != this->PalabrasFaltantes->end(); it++){
        map<int, string>::iterator palabraIN = solucion->find(it->first);
        if(palabraIN == solucion->end() || (palabraIN->second != it->second)){
            correcto = false;
        }
    };
    return correcto;
};

CompletarPalabra::~CompletarPalabra(){
};  
