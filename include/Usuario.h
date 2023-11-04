#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;



#ifndef USUARIO
#define USUARIO

class Idioma;
class DTNotificacion;
class Curso;

class Usuario
{
private:
    string Nickname;
    string Contraseña;
    string Nombre;
    string Descripcion;
    map<string, Idioma *> suscrito;
    set<DTNotificacion*> * notificaciones;
public:

    Usuario (string nickname, string contraseña, string nombre, string descripcion);
    string getNickname();
    string getContraseña();
    string getDescripcion();
    string getNombre();
    void removerIdioma(string nomIdioma);
    set<string> *ObtenerNomIdiomaSuscrito();
    void AgregarIdiomaSuscrito(Idioma *i);
    set<DTNotificacion*> * DevolverNotificaciones();
    void notificar(DTNotificacion * dtnuevocurso);
    virtual ~Usuario();
};
#include "Idioma.h"
#include "DTNotificacion.h"
#include "Curso.h"

#endif
