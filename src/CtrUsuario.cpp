#include "../include/CtrUsuario.h"
#include "../include/ManejadorCurso.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorIdioma.h"
#include "../include/Estudiante.h"
#include "../include/Inscripcion.h"
#include "../include/Curso.h"
#include "../include/Ejercicio.h"
#include "../include/Leccion.h"
#include "../include/DTCurso.h"
#include "../include/DTEjercicio.h"

CtrUsuario *CtrUsuario::instancia = NULL;
CtrUsuario::CtrUsuario(){instancia = NULL;};
CtrUsuario *CtrUsuario::getInstancia(){
    if (instancia == NULL){
        instancia = new CtrUsuario();
    }
    return instancia;
};

//ALTA USUARIO
void CtrUsuario::IngresarDatosUsuario(string nickname, string contrasena, string descripcion,string nombre){
    this->nuevoUsuarioNicknameRec = nickname;
    this->nuevoUsuarioContrasenia = contrasena;
    this->nuevoUsuarioDescripcion = descripcion;
    this->nuevoUsuarioNombreRec = nombre;

};
void CtrUsuario::IngresarDatoEstudiante(string nombrePais, DTFecha* fechaNacimiento){
    this->nuevoUsuarioNombrePaisRec = nombrePais;
    this->nuevoUsuarioFechaNacimientoRec = fechaNacimiento;
};

bool CtrUsuario::NicknameDisponible(string nickname){
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();
    return instanciaMU->ExisteUsuario(nickname);
};
void CtrUsuario::AltaEstudiante(){
    Estudiante* nuevoEstudiante = new Estudiante(this->nuevoUsuarioNicknameRec,this->nuevoUsuarioContrasenia,this->nuevoUsuarioNombreRec,this->nuevoUsuarioDescripcion,this->nuevoUsuarioNombrePaisRec,this->nuevoUsuarioFechaNacimientoRec);
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();
    instanciaMU->agregarUsuario(nuevoEstudiante);

};
bool CtrUsuario::ConfirmarAltaEstudiante(){
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();
    return instanciaMU->ExisteUsuario(this->nuevoUsuarioNicknameRec);
};

set<string>* CtrUsuario::ObtenerIdiomasDisponibles(){
    ManejadorIdioma* instanciaMI = ManejadorIdioma::getInstancia();
    return instanciaMI->IdiomasDisponibles();
};

void CtrUsuario::AgregarEspecializacion(string nombreIdioma){
    this->nuevoUsuarioEspecializacion.insert(nombreIdioma);
};
bool CtrUsuario::ConfirmarAltaProfesor(){
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();
    return instanciaMU->ExisteUsuario(this->nuevoUsuarioNicknameRec);

};

void CtrUsuario::IngresarInstituto(string instituto){
    this->nuevoUsuarioInstitutoRec = instituto;
}

void CtrUsuario::AltaProfesor(){
    Profesor* nuevoProfesor = new Profesor(this->nuevoUsuarioNicknameRec,this->nuevoUsuarioContrasenia,this->nuevoUsuarioNombreRec,this->nuevoUsuarioDescripcion,this->nuevoUsuarioInstitutoRec);
    set<string>::iterator it;   
    for (it = nuevoUsuarioEspecializacion.begin(); it != nuevoUsuarioEspecializacion.end(); it++){
        ManejadorIdioma* instanciaMI = ManejadorIdioma::getInstancia();
        Idioma* idiomaEspecializacion = instanciaMI->obtenerIdioma(*it);
        if(idiomaEspecializacion != NULL){
            nuevoProfesor->AgregarEspecializacion(idiomaEspecializacion);
        }
    };
    nuevoUsuarioEspecializacion.clear();
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();
    instanciaMU->agregarUsuario(nuevoProfesor);

};
    //CONSULTAR NOTIFICACIONES
set<DTNotificacion*> *CtrUsuario::obtenerNotificaciones(){
    ManejadorUsuario * mu;
    mu = ManejadorUsuario::getInstancia();
    usuarioRecordado = mu->obtenerUsuario(this->nickNameRec);
    return usuarioRecordado->DevolverNotificaciones();
    };

void CtrUsuario::EliminarNotifiaciones(){
    //cout<< this->usuarioRecordado->getNickname() <<endl;
    set<DTNotificacion *> * n = usuarioRecordado->DevolverNotificaciones();
    set<DTNotificacion*>::iterator it;
    if(n->size()!=0){
        for (it = n->begin(); it != n->end(); it++){
           delete *it;
           n->erase(*it);
           if(n->size()== 0) break;
        }
        n->clear();
    }
    
    
};
    //SUSCRIBIRSE A NOTIFIACIONES
set<string> *CtrUsuario::ObtenerIdiomaNoSuscripto(string nickname){
    ManejadorUsuario * mu;
    mu = ManejadorUsuario::getInstancia();
    Usuario * u = mu->obtenerUsuario(nickname);
    this->usuarioRecordado = u;
    set<string> * idiomas_usuario = u->ObtenerNomIdiomaSuscrito();
    ManejadorIdioma * mi;
    mi = ManejadorIdioma::getInstancia();
    set<string> * idiomas_disponibles = mi->IdiomasDisponibles();
    set<string> * resultado = new set<string>;
    set<string>::iterator it1; 
    set<string>::iterator it2; 
    for (it1=idiomas_disponibles->begin(); it1!=idiomas_disponibles->end(); it1++){
        it2 = idiomas_usuario->find(*it1);
        if(it2==idiomas_usuario->end()){
            resultado->insert(*it1);
        }
    }
    return resultado;
};

bool CtrUsuario::existeIdioma(string idiom){
    ManejadorIdioma * mi;
    mi = ManejadorIdioma::getInstancia();
    if (mi->existeIdioma(idiom)){
        return true;
    }
    else return false;
}
void CtrUsuario::AgreagarSuscripcion(string nomIdioma){
    ManejadorIdioma * mi;
    mi = ManejadorIdioma::getInstancia();
    Idioma * i = mi->obtenerIdioma(nomIdioma);
    //cout<<usuarioRecordado->getNickname()<<endl;
    i->AgregarSuscriptor(usuarioRecordado);
    this->usuarioRecordado->AgregarIdiomaSuscrito(i);
};
    //ElIMIAR SUSCRIPCIÓN
set<string>  *CtrUsuario::obtenerSuscripciones(string nickname){
    ManejadorUsuario * mu;
    mu = ManejadorUsuario::getInstancia();
    usuarioRecordado = mu->obtenerUsuario(nickname);
    set<string> * idiomaSus = usuarioRecordado->ObtenerNomIdiomaSuscrito();
    return idiomaSus;
};
void CtrUsuario::seleccionarSuscripciones(set<string> conj){
    ManejadorIdioma * mi;
    mi = ManejadorIdioma::getInstancia();
    set<string>::iterator it;
    for(it = conj.begin(); it != conj.end(); it++){
        this->idiomasRecordados.insert(mi->obtenerIdioma(*it));
    }
};
void CtrUsuario::eliminarSuscripciones(){
     set<Idioma *>::iterator it;
    for (it = idiomasRecordados.begin(); it != idiomasRecordados.end(); it++){
        (*it)->removerUsuario(usuarioRecordado->getNickname());
        usuarioRecordado->removerIdioma((*it)->getNombre());
    }
    
};
CtrUsuario::~CtrUsuario(){};

//INSCRIBIRSE A CURSO
void CtrUsuario::IngresarNickname(string nickName){
    this->nickNameRec = nickName;
    ManejadorUsuario * mu = ManejadorUsuario::getInstancia();
    this->usuarioRecordado = mu->obtenerUsuario(nickName);
};
set<DTCurso*> CtrUsuario::ObtenerCursosHabilitadosParaInscripcion(string nickName){
    
    ManejadorCurso* instanciaMC = ManejadorCurso::getInstancia();
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();
    Estudiante* estudiante = dynamic_cast<Estudiante*>(instanciaMU->obtenerUsuario(nickName));
    map<string, Curso*>* cursosInscriptos = estudiante->ObtenerCursosInscriptos();
    set<string>* nombreCursos = instanciaMC->obtenerCursosDisponibles();
    set<Curso*> * cursos = instanciaMC->obtenerCursos(nombreCursos);
    set<Curso*> cursosHabilitados;
    set<DTCurso*> cursosDisponibles;
    for(set<Curso*>::iterator it = cursos->begin(); it != cursos->end(); it++){     
        if ((*it)->getHabilitado()){
            cursosHabilitados.insert((*it));
        };
    };
    //Si no existe cursos Habilitado con el null indicamos que no existe cursos para inscribirse.
    if(cursosHabilitados.empty()){
        return cursosDisponibles;
    }
    //itero en todos los cursosHabilitados
    for(set<Curso*>::iterator cursosHabilitadosIt = cursosHabilitados.begin(); cursosHabilitadosIt != cursosHabilitados.end(); cursosHabilitadosIt++){    
        //si tengo cursosInscriptos 
        if(cursosInscriptos != NULL && cursosInscriptos->find((*cursosHabilitadosIt)->getNombre()) == cursosInscriptos->end()){
            //cout << "Tiene "<< cursosInscriptos->size() << " cursos inscripto" << endl;
            //por cada curso obtengo las previas
            map<string,Curso*>* previas = (*cursosHabilitadosIt)->getPrevias();
            bool tieneLasPrevias = true;
            //Si tiene previas
            if (previas != NULL){
                
                //itero en las previas
                for(map<string,Curso*>::iterator previasIt = previas->begin(); previasIt != previas->end() && tieneLasPrevias; previasIt++){
                    
                    if (cursosInscriptos->find((previasIt->second)->getNombre()) == cursosInscriptos->end()){
                        tieneLasPrevias = false;                         
                    }
                    else{
                        if(!estudiante->getInscripcion((previasIt->second)->getNombre())->getAprobada()){
                            tieneLasPrevias = false;
                        }
                    }                  
                }
            }
            if(tieneLasPrevias){
                DTCurso* cursoDisponible = new DTCurso(((*cursosHabilitadosIt)));
                cursosDisponibles.insert(cursoDisponible);
            }
        }
        //si no tengo cursosInscriptos solo puedo inscribirme a los curso sin previas.
        else if (cursosInscriptos == NULL) {
            map<string,Curso*>* previas = (*cursosHabilitadosIt)->getPrevias();
            if(previas == NULL || previas->empty()){
                DTCurso* cursoDisponible = new DTCurso(((*cursosHabilitadosIt)));
                cursosDisponibles.insert(cursoDisponible);
            }
        }
    };

    return cursosDisponibles;
};
void CtrUsuario::IngresarCursoSeleccionado(string nombreCurso){
    this->nombreCursoRec = nombreCurso;
};
bool CtrUsuario::FinalizarInscripcionACurso(string nickname, DTFecha * f,bool aprobarCurso){
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();
    ManejadorCurso* instanciaMC = ManejadorCurso::getInstancia();
    try{
        Estudiante* estudiante = dynamic_cast<Estudiante*>(instanciaMU->obtenerUsuario(nickname));
        Curso* curso = instanciaMC->obtenerCurso(this->nombreCursoRec);
        estudiante->inscribirseCurso(curso->getNombre(),curso,aprobarCurso, f);
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
};

set<string> * CtrUsuario::ObtenerNicknameUsuarios(){
    ManejadorUsuario * mu = ManejadorUsuario::getInstancia();
    return mu->obtenerNickname();
}

void CtrUsuario::seleccionarUsuario(string nickname){
    ManejadorUsuario * mu = ManejadorUsuario::getInstancia();
    Usuario * u = mu->obtenerUsuario(nickname);
    DTEstudiante* es;
    DTProfesor * profe;
    if(dynamic_cast <Estudiante*> (u)){
        es = seleccionarEstudiante(nickname);
        cout<< "Nombre: "+ es->getNombre()<<endl;
        cout<< "Descripcion: "+ es->getDescripcion()<<endl;
        cout<< "Pais: " +es->getPais()<<endl;
        delete es;
    }
    else {
        Profesor* p=dynamic_cast <Profesor*> (u);
        profe = seleccionarProfesor(nickname);
        cout<< "Nombre: "+ profe->getNombre()<<endl;
        cout<< "Descripcion: "+ profe->getDescripcion()<<endl;
        cout<< "Instituto: " + profe->getInstituto()<<endl;
        cout<<"Idiomas: \n";
        set<string>* id =p->obtenerEspecializaciones();
        for (set<string>::iterator it = id->begin();it != id->end();it++){
            cout << (*it) << "\n";
        }
        delete profe;
    }

}

DTEstudiante *CtrUsuario::seleccionarEstudiante(string nickname){
    ManejadorUsuario * mu = ManejadorUsuario::getInstancia();
    Usuario * u = mu->obtenerUsuario(nickname);
    Estudiante * estudiante = dynamic_cast <Estudiante*> (u);
     DTEstudiante * es;
    if (estudiante!=NULL){
        es = new DTEstudiante(estudiante);
        return es;
    }
    else return NULL;
}

DTProfesor *CtrUsuario::seleccionarProfesor(string nickname){
    ManejadorUsuario * mu = ManejadorUsuario::getInstancia();
    Usuario * u = mu->obtenerUsuario(nickname);
    Profesor* profe = dynamic_cast <Profesor*> (u);
    DTProfesor * pro ;
    if (profe!=NULL){
        pro = new DTProfesor(profe->getNickname(), profe->getContraseña(),profe->getNombre(), profe->getDescripcion(), profe->getInstituto());
        return pro;
    }
    else return NULL;
}
    
bool CtrUsuario::existeUsuario(string nickname){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    return mu->ExisteUsuario(nickname);
}

void CtrUsuario::recordarUsuario(string nickname){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    usuarioRecordado = mu->obtenerUsuario(nickname);
    this->usuarioRecordado=usuarioRecordado;
}

map<string, DTCurso*>* CtrUsuario::obtenerCursosInscriptoNoAprobado(){

    Estudiante* estudiante = dynamic_cast<Estudiante*>(usuarioRecordado);

    map<string, Inscripcion*>* inscripciones = estudiante->getInscripciones();
    map<string, DTCurso*>* cursosInscriptoNoAprobados = new map<string, DTCurso*>;

    for(map<string, Inscripcion*>::iterator it = inscripciones->begin(); it != inscripciones->end(); it++){
        if (!it->second->getAprobada()){
            DTCurso* curso = new DTCurso(it->second->getCursoInscripto());
            cursosInscriptoNoAprobados->insert(pair<string, DTCurso*>(curso->getNombre(), curso));
        }
    }

    return cursosInscriptoNoAprobados;
}

map<int, DTEjercicio*>* CtrUsuario::obtenerEjerciciosNoAprobados(){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    Estudiante* estudiante = dynamic_cast<Estudiante*>(usuarioRecordado);

    Inscripcion* inscripcion = estudiante->getInscripciones()->find(this->nombreCursoRec)->second;
    Leccion* ultimaLeccionAprobada = inscripcion->getUltimaLeccionAprobada();

    Curso* curso = mc->obtenerCurso(this->nombreCursoRec);    
    map<int, Ejercicio*>* ejerciciosDeLeccionActual = new map<int, Ejercicio*>;

    if(ultimaLeccionAprobada == NULL){
        ultimaLeccionAprobada = curso->getColLecciones()->find(1)->second;
        ejerciciosDeLeccionActual = ultimaLeccionAprobada->getColEjercicios();
        this->leccionRecordada = 1;
    } else {
        map<int, Leccion*>* leccionesCurso = curso->getColLecciones();
        this->leccionRecordada = ultimaLeccionAprobada->getOrden() + 1;
        ejerciciosDeLeccionActual = leccionesCurso->find(this->leccionRecordada)->second->getColEjercicios();
    }

    map<int, DTEjercicio*>* ejercicios = new map<int, DTEjercicio*>;
    for(map<int, Ejercicio*>::iterator it = ejerciciosDeLeccionActual->begin(); it != ejerciciosDeLeccionActual->end(); it++){
        if (!it->second->esAprovado(estudiante->getNickname())){
            DTEjercicio* ejercicio = new DTEjercicio(it->second);
            ejercicios->insert(pair<int, DTEjercicio*>(it->first, ejercicio));
        }
    }
    return ejercicios;
}
void CtrUsuario::recordarEjercicio(pair<int, DTEjercicio*>* ejercicio){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    Curso* curso = mc->obtenerCurso(this->nombreCursoRec); 
    Leccion* leccionesCurso = curso->getColLecciones()->find(this->leccionRecordada)->second;
    this->ejercicioRecordado = leccionesCurso->getColEjercicios()->find(ejercicio->first)->second;
}

bool CtrUsuario::mostrarEjercicio(){
    if(dynamic_cast<Traducir*>(this->ejercicioRecordado)){
        Traducir* traducir = dynamic_cast<Traducir*>(this->ejercicioRecordado);
        cout<<"\nLetra del ejercicio: " << traducir->getDescripcion() << endl;
        cout<<"\nFrase a traducir: " << traducir->getFraseATraducir() << endl;
        this->ejercicioDeTraducir = traducir;
        return true;
    }
    else if (dynamic_cast<CompletarPalabra*>(this->ejercicioRecordado)){
        CompletarPalabra* completarPalabra = dynamic_cast<CompletarPalabra*>(this->ejercicioRecordado);
        cout<<"\nLetra del ejercicio: " << completarPalabra->getDescripcion() << endl;
        cout<<"\nFrase a traducir: " << completarPalabra->getFrase() << endl;
        this->ejercicioDeCompletarPalabra = completarPalabra;
    }
    return false;
}

bool CtrUsuario::mostrarEjercicioaux(){
    if(dynamic_cast<Traducir*>(this->ejercicioRecordado)){
        Traducir* traducir = dynamic_cast<Traducir*>(this->ejercicioRecordado);
        this->ejercicioDeTraducir = traducir;
        return true;
    }
    else if (dynamic_cast<CompletarPalabra*>(this->ejercicioRecordado)){
        CompletarPalabra* completarPalabra = dynamic_cast<CompletarPalabra*>(this->ejercicioRecordado);
        this->ejercicioDeCompletarPalabra = completarPalabra;
    }
    return false;
}
void CtrUsuario::resolverCompletarPalabra(map<int, string>* solucion,bool imprimir){
    CompletarPalabra* completarPalabra = this->ejercicioDeCompletarPalabra;

    if (completarPalabra->ingresarSolucion(solucion)){
        ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
        mu->aprobarEjercicio(this->ejercicioRecordado, usuarioRecordado->getNickname(), this->nombreCursoRec);
        if(imprimir){
        cout<<"\nCorrecto!!!\n";
        }
    } else {
        if(imprimir){
        cout<<"\nPara volver a intentar ingrese 12 en el menu principal.\n";
        }
    }
}

void CtrUsuario::resolverTraducir(string solucion,bool imprimir){
    Traducir* traducir = this->ejercicioDeTraducir;

    if (traducir->ingresarSolucion(solucion)){
        ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
        mu->aprobarEjercicio(this->ejercicioRecordado, usuarioRecordado->getNickname(), this->nombreCursoRec);
    if(imprimir){
        cout<<"\nCorrecto!!!\n";
    }
    } else {
        if(imprimir){
        cout<<"\nPara volver a intentar ingrese 12 en el menu principal.\n";
        }
    }
}

int CtrUsuario::cantidadPalabrasACompletar(){
    return this->ejercicioDeCompletarPalabra->getPalabrasFaltantes()->size();
}