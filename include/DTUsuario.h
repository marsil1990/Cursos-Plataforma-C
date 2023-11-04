# include <iostream>
using namespace std;
#ifndef DTUSUARIO
#define DTUSUARIO
class DTUsuario
{
private:
    string Nickname;
    string Contraseña;
    string Nombre;
    string Descripcion;
public:
    DTUsuario (string Nickname, string Contraseña, string Nombre, string Descripcion);
    string getNickname();
    string getContraseña();
    string getDescripcion();
    string getNombre();
    virtual ~DTUsuario();
};

#endif
