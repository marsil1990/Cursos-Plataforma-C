#include <iostream>
using namespace std;
#include <string>
#include <set>
#include "Inscripcion.h"

#ifndef IUSUARIO
#define IUSUARIO

class DTNotificacion;
class DTUsuario;
class DTFecha;
class DTEstudiante;
class DTProfesor;
class DTCurso;
class IUsuario
{
public:
    //ALTA USUARIO
    virtual void IngresarDatosUsuario(string nickname, string contrasena, string descripcion,string nombre)=0;
    virtual void IngresarDatoEstudiante(string nombrePais, DTFecha* fechaNacimiento)=0;
    virtual bool NicknameDisponible(string nickname)=0;
    virtual void AltaEstudiante()=0;
    virtual bool ConfirmarAltaEstudiante()=0;
    virtual void IngresarInstituto(string nombrePais)=0;
    virtual set<string>* ObtenerIdiomasDisponibles()=0;
    virtual void AgregarEspecializacion(string nombreIdioma)=0;
    virtual bool ConfirmarAltaProfesor()=0;
    virtual void AltaProfesor()=0;
    //CONSULTAR USUARIO
    virtual set<string> *ObtenerNicknameUsuarios() = 0;
    virtual void seleccionarUsuario(string nickname)=0 ;
    virtual DTEstudiante *seleccionarEstudiante(string nickname)=0;
    virtual DTProfesor *seleccionarProfesor(string nickname)=0;
   
    //CONSULTAR NOTIFICACIONES
    virtual void IngresarNickname(string nickname)=0;
    virtual set<DTNotificacion*> *obtenerNotificaciones()=0;
    virtual void EliminarNotifiaciones()=0;
    //SUSCRIBIRSE A NOTIFIACIONES
    virtual set<string> *ObtenerIdiomaNoSuscripto(string nickname)=0;
    virtual void AgreagarSuscripcion(string nomIdioma)=0;
    virtual bool existeIdioma(string idiom)=0;
    //ElIMIAR SUSCRIPCIÓN
    virtual set<string> *obtenerSuscripciones(string nickname)=0;
    virtual void seleccionarSuscripciones(set<string>)=0;
    virtual void eliminarSuscripciones()=0;
    //INSCRIBIRSE A CURSO
    virtual set<DTCurso*> ObtenerCursosHabilitadosParaInscripcion(string nickName)=0;
    virtual void IngresarCursoSeleccionado(string nombreCurso)=0;
    virtual bool FinalizarInscripcionACurso(string nickname, DTFecha * f = NULL,bool aprobado = false)=0;
    //REALIZAR EJERCICIO
    virtual bool existeUsuario(string nickname)=0;
    virtual void recordarUsuario(string nickname)=0;
    virtual map<string, DTCurso*>* obtenerCursosInscriptoNoAprobado()=0;
    virtual map<int, DTEjercicio*>* obtenerEjerciciosNoAprobados()=0;
    virtual void recordarEjercicio(pair<int, DTEjercicio*>* ejercicio)=0;
    virtual bool mostrarEjercicio()=0;
    virtual bool mostrarEjercicioaux()=0;
    virtual void resolverCompletarPalabra(map<int, string>* solucion,bool imprimir=false)=0;
    virtual void resolverTraducir(string solucion,bool imprimir=false)=0;
    virtual int cantidadPalabrasACompletar()=0;
};

#include "DTNotificacion.h"
#include "DTUsuario.h"
#include "DTFecha.h"
#include "DTEstudiante.h"
#include "DTProfesor.h"
#include "DTCurso.h"
#endif

