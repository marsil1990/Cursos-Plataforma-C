#include "../include/DTEjercicio.h"
#include "../include/Ejercicio.h"

DTEjercicio::DTEjercicio(int id, string descripcion){
    this->Id = id;
    this->Descripcion = descripcion;
};

DTEjercicio::DTEjercicio(Ejercicio* ejercicio){
    this->Id = ejercicio->getId();
    this->Descripcion = ejercicio->getDescripcion();
}



string DTEjercicio::getDescripcion(){
    return this->Descripcion;
}



    
DTEjercicio::~DTEjercicio(){};
