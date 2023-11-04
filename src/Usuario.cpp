#include "../include/Usuario.h"

Usuario::Usuario (string nickname, string contraseña, string nombre, string descripcion){
    this->Nickname = nickname;
    this->Contraseña = contraseña;
    this->Nombre = nombre;
    this->Descripcion = descripcion;
    this->notificaciones = new set<DTNotificacion*>;
};

string Usuario::getNickname(){
    return this->Nickname;  
};


string Usuario::getContraseña(){
    return this->Contraseña;
};

string Usuario::getDescripcion(){
    return this->Descripcion;
};

string Usuario::getNombre(){
    return this->Nombre;
};

set<string> *Usuario::ObtenerNomIdiomaSuscrito(){
    set<string> * conj  = new set<string>;
    map<string, Idioma *>::iterator it;
    for (it= suscrito.begin(); it!=suscrito.end(); ++it){
        string clave = it->first;
        Idioma * idiom = it->second;
        conj->insert(idiom->getNombre());
         }
    return conj;
};

void Usuario::AgregarIdiomaSuscrito(Idioma * i){
    this->suscrito[i->getNombre()]= i;
};

set<DTNotificacion*> * Usuario::DevolverNotificaciones(){
    return  this->notificaciones;
};



void Usuario::removerIdioma(string nomIdioma){
    this->suscrito.erase(nomIdioma);
    set<DTNotificacion *>::iterator it;
    if(notificaciones != NULL){
        for(it = notificaciones->begin(); it!=notificaciones->end(); it++){
            if ((*it)->getNombreIdioma()==nomIdioma){
                delete *it;
                notificaciones->erase(*it);
            }
            if(notificaciones->size()== 0) break;
        }
    }
};


void Usuario::notificar(DTNotificacion* DTnuevocurso){
    notificaciones->insert(DTnuevocurso);
};


Usuario::~Usuario(){
};
