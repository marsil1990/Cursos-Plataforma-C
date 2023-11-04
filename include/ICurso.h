#include <iostream>
using namespace std;
#include <string>
#include <set>
#ifndef ICURSO
#define ICURSO

class DTCurso;
class DTLeccion;

class ICurso{
public:
    //Alta Curso
    virtual set<string>* obtenerNickname()=0;
    virtual bool ExisteCurso(string nombreCurso)=0;
    virtual void seleccionarProfesor(string nickname)=0;
    virtual void ingresarDatosCurso(string nombre, string descripcion, Nivel dificultad)=0;
    virtual set<string>* obtenerIdiomasEspecializacion()=0;
    virtual void seleccionarIdioma(string nombreIdioma)=0;
    virtual void necesitaPrevia(bool confirmacion)=0;
    virtual set<DTCurso*>* obtenerCursosHabilitados()=0;
    virtual void seleccionarPrevias(set<string>*)=0;
    virtual void crearLeccion(string tema, string objetivo)=0;
    virtual void crearEjercicioCompletarPalabra(string descripcion,string frase, map<int, string>* respuesta)=0;
    virtual void crearEjercicioTraducir(string descripcion,string frase, string traduccion)=0;
    virtual void ConfirmarAltaCurso()=0;

    //Agregar leccion
    virtual set<DTCurso*>* ObtenerCursosNoHabilitados()=0;
    virtual void seleccionarCurso(string nombreCurso)=0;
    virtual void crearDatosLeccion(string tema, string objetivo)=0;
    virtual  void ingresarFraseCompletar(string frase, map<int, string>* solucion)=0;
    virtual void DarDeAltaEjercicio()=0;
    virtual void DarDeAltaLeccion()=0;

    //Agregar ejercicio
    virtual set<DTLeccion*>* obtenerLecciones()=0;
    virtual void agregarEjercicio(int lec, string descripcion ,string frase, map<int, string>* solucion)=0;
    virtual void agregarEjercicio(int lec, string descripcion, string frase, string solucion)=0;

    //AlTA IDIOMA
    virtual void IngresarIdioma(string nombreIdioma)=0;
    virtual bool ConfirmarIdioma()=0;
    virtual set<string>* ConsultarIdioma()=0;
    //Consultar Estadisticas
    virtual set<string>* ObtenerEstudiantes()=0;
    virtual map<int,DTCurso*>* obtenerCursosInscripto(string nickname)=0;
    virtual map<int,float>* obtenerAvanceCursos()=0;
    virtual set<string>* ObtenerProfesores()=0; 
    virtual map<int,float>* obtenerPromedioCursos()=0;
    virtual set<DTCurso*>* obtenerCursos()=0;
    virtual float obtenerPromedio()=0;
    virtual bool habilitarCurso()=0;
    //Consultar curso
    virtual DTCurso* obtenerCurso(string nombreCurso)=0;
    virtual map<int, DTLeccion*>* obtenerLeccionesDeCurso()=0;
    virtual map<int, DTEjercicio*>* obtenerEjercicios(int leccion)=0;
    //Eliminar curso
    virtual void eliminarCurso()=0;
};

#include "DTCurso.h"
#include "DTLeccion.h"

#endif