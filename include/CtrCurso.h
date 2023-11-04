#include <iostream>
#include "Curso.h"
#include "Leccion.h"
#include "Ejercicio.h"
#include "Estudiante.h"
#include "ICurso.h"
using namespace std;
#include <string>
#include <set>
#ifndef CTRCURSO
#define CTRCURSO

enum TipoEjercicio {
    completarPalabra = 0,
    traducir = 1,
};

class Curso;
class DTCurso;
class DTLeccion;

class CtrCurso: public ICurso
{
private:
    static CtrCurso* instancia;
    CtrCurso();
    Profesor* profRec;
    string nombreCursoRec;
    string descripcionRec;
    Nivel dificultadRec;
    Idioma* idiomaRec;
    bool necesitaPreviaRec;
    set<Curso*>* previasRec;
    map<int,Leccion*>* leccionesRec;
    Leccion* ultimaLeccion = NULL;
    Curso* cursoRecAgregar = NULL;
    string temaRec;
    string objetivoRec;
    TipoEjercicio tipoejercicioRec;
    string descripcionEjRec;
    string fraseEjRec;
    map<int, string>* solucionFCRec;
    string solucionTRec; 
    map<int, Ejercicio*>* ejerciciosNuevos = NULL;
    Leccion* leccionSeleccionada;
    string nombreRecordado;
    map<string,Curso*>* cursosRecordados;
public:
    static CtrCurso* getInstancia();
    //Alta Curso
    set<string>* obtenerNickname();
    bool ExisteCurso(string nombreCurso);
    void seleccionarProfesor(string nickname);
    void ingresarDatosCurso(string nombre, string descripcion, Nivel dificultad);
    set<string>* obtenerIdiomasEspecializacion();
    void seleccionarIdioma(string nombreIdioma);
    void necesitaPrevia(bool confirmacion);
    set<DTCurso*>* obtenerCursosHabilitados();
    void seleccionarPrevias(set<string>* nombrePrevias);
    void crearLeccion(string tema, string objetivo);
    void crearEjercicioCompletarPalabra(string descripcion, string frase, map<int, string>* respuesta);
    void crearEjercicioTraducir(string descripcion, string frase, string traduccion);
    void ConfirmarAltaCurso();

    //Agregar leccion
    set<DTCurso*>* ObtenerCursosNoHabilitados();
    void seleccionarCurso(string nombreCurso);
    void crearDatosLeccion(string tema, string objetivo);
    void ingresarTipoEjercicio(TipoEjercicio tipoejercicio, string descripcion);
    void ingresarFraseCompletar(string frase, map<int, string>* solucion);
    void ingresarFraseTraduccion(string frase, string traduccion);
    void DarDeAltaEjercicio();
    void DarDeAltaLeccion();
    //Agregar ejercicio
    set<DTLeccion*>* obtenerLecciones();
    void agregarEjercicio(int lec, string descripcion ,string frase, map<int, string>* solucion);
    void agregarEjercicio(int lec, string descripcion, string frase, string solucion);  
    //Alta Idioma
    void IngresarIdioma(string nombreIdioma);
    bool ConfirmarIdioma();
    //Consultar Idioma
    set<string>* ConsultarIdioma();
    //Consultar Estadisticas
    set<string>* ObtenerEstudiantes();
    map<int,DTCurso*>* obtenerCursosInscripto(string nickname);
    map<int,float>* obtenerAvanceCursos();
    set<string>* ObtenerProfesores(); 
    map<int,float>* obtenerPromedioCursos();
    set<DTCurso*>* obtenerCursos();
    float obtenerPromedio();
    bool habilitarCurso();

    //eliminar curso
    bool existeCurso(string nombreCurso);
    void eliminarCurso();

    //consultar curso
    DTCurso* obtenerCurso(string nombreCurso);
    map<int, DTLeccion*>* obtenerLeccionesDeCurso();
    map<int, DTEjercicio*>* obtenerEjercicios(int leccion);
};

#include "DTCurso.h"
#endif
