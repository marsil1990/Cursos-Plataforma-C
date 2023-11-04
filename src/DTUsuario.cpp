# include "../include/DTUsuario.h"

DTUsuario::DTUsuario (string Nickname, string Contraseña, string Nombre, string Descripcion){
    this->Nickname= Nickname;
    this->Contraseña = Contraseña;
    this->Descripcion = Descripcion;
    this->Nombre = Nombre;
};
string DTUsuario::getNickname(){return this->Nickname;};
string DTUsuario::getContraseña(){return this->Contraseña;};
string DTUsuario::getDescripcion(){
    return this->Descripcion;
};
string DTUsuario::getNombre(){
    return this->Nombre;
};
DTUsuario::~DTUsuario(){};


