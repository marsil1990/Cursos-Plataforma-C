#include "../include/ManejadorIdioma.h"

ManejadorIdioma* ManejadorIdioma::instancia = NULL;

ManejadorIdioma::ManejadorIdioma(){
    this->Idiomas = new map<string, Idioma*>;
};

ManejadorIdioma* ManejadorIdioma::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorIdioma();
    return instancia;
};

void ManejadorIdioma::agregarIdioma(Idioma* nuevoIdioma){
    this->Idiomas->insert(pair<string, Idioma*>(nuevoIdioma->getNombre(), nuevoIdioma));
};

set<string>* ManejadorIdioma::IdiomasDisponibles(){
    set<string>* idDisponibles = new set<string>;
    for (map<string, Idioma*>::iterator it = this->Idiomas->begin(); it != this->Idiomas->end(); it++)
        idDisponibles->insert(it->second->getNombre());
    if (idDisponibles->empty()){
        delete idDisponibles;
        return NULL;
    }else{
        return idDisponibles;
    };
};

Idioma *ManejadorIdioma::obtenerIdioma(string nombreIdioma){
    return this->Idiomas->find(nombreIdioma)->second;
};
bool ManejadorIdioma::existeIdioma(string nombreIdioma) {
    return this->Idiomas->count(nombreIdioma)>0;
}
ManejadorIdioma::~ManejadorIdioma(){};

