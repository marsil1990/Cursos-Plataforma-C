#include <iostream>
using namespace std;
#include <set>
#include <map>
#ifndef EJERCICIO
#define EJERCICIO
class Inscripcion;
class Ejercicio

{
private:
    int Id;
    string Descripcion;
    map<string,Inscripcion*>* EstudiantesAprovaron;
public:
    Ejercicio(int id, string descricion);
    int getId();
    string getDescripcion();
    bool esAprovado(string nickEstudiante);
    void addEstudianteAprobado(Inscripcion* inscripcion);
    virtual ~Ejercicio();
};

#endif
