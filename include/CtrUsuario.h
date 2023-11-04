#include <iostream>
#include <set>
#include "IUsuario.h"
#include "DTCurso.h"
#include "DTEstudiante.h"
#include "DTProfesor.h" 
#ifndef CTRUSUARIO
#define CTRUSUARIO
class Idioma;
class Usuario;
class CtrUsuario: public IUsuario
{
private:
    static CtrUsuario * instancia;
    string nickNameRec;
    string nombreCursoRec;

    string nuevoUsuarioNicknameRec;
    string nuevoUsuarioContrasenia;
    string nuevoUsuarioDescripcion;
    string nuevoUsuarioNombreRec;
    string nuevoUsuarioNombrePaisRec;
    DTFecha* nuevoUsuarioFechaNacimientoRec;
    string nuevoUsuarioInstitutoRec;
    set<string> nuevoUsuarioEspecializacion; 
    set<Idioma*> idiomasRecordados;
    Usuario * usuarioRecordado; 
    Ejercicio* ejercicioRecordado;
    Traducir* ejercicioDeTraducir;
    CompletarPalabra* ejercicioDeCompletarPalabra;
    int leccionRecordada;

    CtrUsuario();
public:
    static CtrUsuario *getInstancia();
    //ALTA USUARIO
    void IngresarDatosUsuario(string nickname, string contrasena, string descripcion,string nombre);
    void IngresarDatoEstudiante(string nombrePais, DTFecha* fechaNacimiento);
    bool NicknameDisponible(string nickname);
    void AltaEstudiante();
    bool ConfirmarAltaEstudiante();
    void IngresarInstituto(string nombreInstituto);
    set<string>* ObtenerIdiomasDisponibles();
    void AgregarEspecializacion(string nombreIdioma);
    bool ConfirmarAltaProfesor();
    void AltaProfesor();
    //CONSULTAR NOTIFICACIONES
    set<DTNotificacion*> *obtenerNotificaciones();
    void EliminarNotifiaciones();
    //SUSCRIBIRSE A NOTIFIACIONES
    set<string> *ObtenerIdiomaNoSuscripto(string nickname);
    void AgreagarSuscripcion(string nomIdioma);
    bool existeIdioma(string idiom);
    //ElIMIAR SUSCRIPCIÓN
    set<string>  *obtenerSuscripciones(string nickname);
    void seleccionarSuscripciones(set<string> conj);
    void eliminarSuscripciones();
    //INSCRIBIRSE A CURSO
    void IngresarNickname(string nickName);
    set<DTCurso*> ObtenerCursosHabilitadosParaInscripcion(string nickName);
    void IngresarCursoSeleccionado(string nombreCurso);
    bool FinalizarInscripcionACurso(string nickname, DTFecha * f = NULL, bool aprobarCurso = false);
    //CONSULTAR USUARIO
    set<string> *ObtenerNicknameUsuarios();
    void seleccionarUsuario(string nickname);
    DTEstudiante *seleccionarEstudiante(string nickname);
    DTProfesor *seleccionarProfesor(string nickname);

    //realizar ejercicio
    bool existeUsuario(string nickname);
    void recordarUsuario(string nickname);
    map<string, DTCurso*>* obtenerCursosInscriptoNoAprobado();
    map<int, DTEjercicio*>* obtenerEjerciciosNoAprobados();
    void recordarEjercicio(pair<int, DTEjercicio*>* ejercicio);
    bool mostrarEjercicio();
    bool mostrarEjercicioaux();
    void resolverCompletarPalabra(map<int, string>* solucion,bool imprimir);
    void resolverTraducir(string solucion,bool imprimir);
    int cantidadPalabrasACompletar();

    virtual ~CtrUsuario();;
};

#include "Idioma.h"
#include "Usuario.h"

#endif