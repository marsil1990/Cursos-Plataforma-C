#include "../include/Traducir.h"

Traducir::Traducir(int id, string descripcion, string fraseatraducir, string frasecorrecta):Ejercicio(id, descripcion){
    this->FraseATraducir = fraseatraducir;
    this->FraseCorrecta = frasecorrecta;
};

string Traducir::getFraseATraducir(){
    return this->FraseATraducir;
};

string Traducir::getFraseCorrecta(){
    return this->FraseCorrecta;
};

bool Traducir::ingresarSolucion(string solucion){
    string traduccion = this->FraseCorrecta;

    if (traduccion.compare(solucion) == 0){
        return true;
    } else {
        return false;
    }
};

Traducir::~Traducir(){

};
