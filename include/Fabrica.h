#include "IUsuario.h"
#include "ICurso.h"

#ifndef FABRICA
#define FABRICA
class IUsuario;
class CtrUsuario;

class Fabrica
{
private:
    static Fabrica *instancia;
    Fabrica();
public:
    static Fabrica *getInstancia();
    IUsuario *getIUsuario();
    ICurso* getICurso();
};


#include "../include/CtrUsuario.h"
#include "../include/CtrCurso.h"
#endif
