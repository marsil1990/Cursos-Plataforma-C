#include "../include/DTProfesor.h"

DTProfesor:: DTProfesor (string Nickname, string Contraseña, string Nombre, string Descripcion, string Instituto):DTUsuario(Nickname, Contraseña, Nombre, Descripcion){
    this->Instituto = Instituto;
};
string DTProfesor:: getNickname(){return  DTUsuario::getNickname();};
string DTProfesor:: getContraseña(){return  DTUsuario::getContraseña();};
string DTProfesor:: getDescripcion(){return  DTUsuario::getDescripcion();};
string DTProfesor:: getInstituto(){return this->Instituto;};
string DTProfesor:: getNombre(){return DTUsuario::getNombre();};
DTProfesor::~DTProfesor(){};


