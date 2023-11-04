#include <iostream>
using namespace std;
#include <string>
#include <map>
#include "DTUsuario.h"
#include "DTFecha.h"
#include "DTInscripcion.h"
#ifndef DTESTUDIANTE
#define DTESTUDIANTE

class Estudiante;
class DTEstudiante : public DTUsuario
{
private:
    string Pais;
    DTFecha *Fecha;
    map<string, DTInscripcion*>* Inscripciones;
public:
    DTEstudiante(string Nickname, string Contraseña, string Nombre, string Descripcion, string Pais, DTFecha * FechaNac);
    DTEstudiante(Estudiante* estudiante);
    string getNickname();
    string getContraseña();
    string getDescripcion();
    string getPais();
    DTFecha * getFechaNac();
    DTInscripcion* getInscripcionACurso(string nombreCurso);
    string getNombre();
    virtual ~DTEstudiante();
};

#endif
