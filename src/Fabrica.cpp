#include "../include/Fabrica.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){};

Fabrica *Fabrica::getInstancia(){
    if (instancia == NULL){
        instancia = new Fabrica();
    }
    return instancia;
};

IUsuario *Fabrica::getIUsuario(){
    return CtrUsuario::getInstancia();
};

ICurso* Fabrica::getICurso(){
    return CtrCurso::getInstancia();
}
