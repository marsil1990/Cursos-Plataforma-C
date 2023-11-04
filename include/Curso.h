#include <iostream>
#include "DTCurso.h"
#include "Profesor.h"
#include "DTLeccion.h"
using namespace std;
#include <set>
#ifndef CURSO
#define CURSO

class Profesor; 
class Idioma;
class Leccion;
class DTCurso;
class Estudiante;

enum Nivel {
    Principiante = 0,
    Intermedio = 1,
    Avanzado = 2
};

class Curso
{
private:
    string Nombre;
    string Descripcion;
    Nivel Dificultad;
    Profesor* ProfesorCurso = NULL;
    Idioma* IdiomaCurso = NULL;
    map<string,Curso*>* Previas;
    bool Habilitado = false;
    map<string,Estudiante*> * alumnosInscriptos;
    map<int, Leccion*>* Lecciones;
public:
    Curso(string nombre, string descripcion, Nivel nivel);
    Curso(string nombre, string descripcion, Nivel nivel, Profesor* profesor, Idioma* idioma);
    string getNombre(); 
    map<string,Curso*>* getPrevias();
    string getDescripcion();
    Nivel getDificultad();
    string getIdioma();
    bool getHabilitado();
    void inscribirEstudiante(Estudiante* estudiante);
    int getCantLecciones();
    void setProfesor(Profesor* profesor);
    void setHabilitado(bool habilitado);
    void removerPrevia(string nombreCurso);
    DTCurso* getDataCurso();
    void añadirLeccion(Leccion* lec);
    void añadirPrevia(Curso* previa);
    float obtenerAvanceCurso(string nickEstudiante);
    float obtenerPromedioCurso();
    Leccion* obtenerSiguienteLeccion(int orden);
    set<DTLeccion*>* getLecciones();
    void nuevoEjercicio(int lec, string descripcion, string frase, map<int, string>* solucion);
    void nuevoEjercicio(int lec, string descripcion, string frase, string solucion);
    bool habilitarCurso();
    int getCantEjercicios();
    map<int, Leccion*>* getColLecciones();
    void eliminarLecciones();
    void eliminarPrevias(string nomCurso);
    string getProfesor();
    map<string,Estudiante*>* getEstudiantes();
    string getNicknameProfesor();
    int getCantInscriptos();
    void borrarPrevias();
    ~Curso();
};

#endif
