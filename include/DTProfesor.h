#include "DTUsuario.h"
# include <iostream>
using namespace std;
#ifndef DTPROFESOR
#define DTPROFESOR
class DTProfesor : public DTUsuario
{
private:
    string Instituto;
public:
    DTProfesor (string Nickname, string Contraseña, string Nombre, string Descripcion, string Instituto);
    string getNickname();
    string getContraseña();
    string getDescripcion();
    string getInstituto();
    string getNombre();
    virtual ~DTProfesor();
};

#endif
