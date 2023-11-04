#include "../include/CtrCurso.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorIdioma.h"
#include "../include/ManejadorCurso.h"
#include "../include/Profesor.h"
#include "../include/Curso.h"
#include "../include/CompletarPalabra.h"
#include "../include/Traducir.h"
#include "../include/DTEjercicio.h"


CtrCurso* CtrCurso::instancia = NULL;

CtrCurso::CtrCurso(){
    this->leccionesRec = new map<int,Leccion*>;
    this->previasRec = new set<Curso*>;
};

CtrCurso* CtrCurso::getInstancia(){
    if (instancia == NULL)
        instancia = new CtrCurso();
    return instancia;
};

//Alta curso
set<string>* CtrCurso::obtenerNickname(){
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();
    set<string>* nombres = instanciaMU->obtenerNombresProfesor();
    if (nombres->empty())
        return NULL;
    else
        return nombres;
};

bool CtrCurso::ExisteCurso(string nombreCurso){
    ManejadorCurso* instanciaMC = ManejadorCurso::getInstancia();
    return instanciaMC->ExisteCurso(nombreCurso);
}

void CtrCurso::seleccionarProfesor(string nickname){
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();
    Usuario* prof = instanciaMU->obtenerUsuario(nickname);
    if (prof != NULL)
        profRec = dynamic_cast<Profesor*>(prof);
};

void CtrCurso::ingresarDatosCurso(string nombre, string descripcion, Nivel dificultad){
    this->nombreCursoRec = nombre;
    this->descripcionRec = descripcion;
    this->dificultadRec = dificultad;
};

set<string>* CtrCurso::obtenerIdiomasEspecializacion(){
    return profRec->obtenerEspecializaciones();
};

void CtrCurso::seleccionarIdioma(string nombreIdioma){
    ManejadorIdioma* instanciaMI = ManejadorIdioma::getInstancia();
    this->idiomaRec = instanciaMI->obtenerIdioma(nombreIdioma);
};

void CtrCurso::necesitaPrevia(bool confirmacion){
    this->necesitaPreviaRec = confirmacion;
};

set<DTCurso*>* CtrCurso::obtenerCursosHabilitados(){
    return idiomaRec->getDataCursosHab();
};

void CtrCurso::seleccionarPrevias(set<string>* nombrePrevias){
    ManejadorCurso* instanciaMC = ManejadorCurso::getInstancia();
    this->previasRec = instanciaMC->obtenerCursos(nombrePrevias);
};

void CtrCurso::crearLeccion(string tema, string objetivo){
    int n =this->leccionesRec->size() + 1;
    this->ultimaLeccion = new Leccion(n, tema, objetivo);
    this->leccionesRec->insert(pair<int,Leccion*>(n,ultimaLeccion));
};

void CtrCurso::crearEjercicioTraducir(string descripcion, string frase, string traduccion){
    ultimaLeccion->añadirEjercicio(descripcion, frase, traduccion);
};

void CtrCurso::crearEjercicioCompletarPalabra(string descripcion, string frase, map<int, string>* respuesta){
    ultimaLeccion->añadirEjercicio(descripcion, frase, respuesta);
};

void CtrCurso::ConfirmarAltaCurso(){
    //Se instancia un nuevo curso
    Curso* nuevoCurso = new Curso(nombreCursoRec, descripcionRec, dificultadRec, profRec, idiomaRec);
    
    //Se agregan las lecciones recordadas
    int i =1;
    for(map<int,Leccion*>::iterator it = this->leccionesRec->begin(); it != this->leccionesRec->end(); it++){
        nuevoCurso->añadirLeccion(leccionesRec->find(i)->second);
        i++;
}
    //Se asocia el nuevo curso con el profesor recordado
    this->profRec->asociarCursoProfesor(nuevoCurso);

    //Se agrega cada previa recordada al curso
    for(set<Curso*>::iterator it = this->previasRec->begin(); it != this->previasRec->end(); it++)
        nuevoCurso->añadirPrevia(*it);
    previasRec->clear();
    //Se asocia el curso al idioma
    idiomaRec->asociarCursoIdioma(nuevoCurso);

    //Se asocia el profesor al curso
    nuevoCurso->setProfesor(this->profRec);

    ManejadorCurso* manejadorCurso = ManejadorCurso::getInstancia();

    //Se agrega el curso a la coleccion de cursos
    manejadorCurso->agregarCurso(nuevoCurso);

    //Se crea la notificacion
    idiomaRec->EnviarNotificacion(nuevoCurso);

    //Se eliminan los punteros a las lecciones para dejar el conjunto vacio para la siguiente creacion de un nuevo curso
    this->leccionesRec->clear();
};

//Agregar leccion
set<DTCurso*>* CtrCurso::ObtenerCursosNoHabilitados(){
    ManejadorCurso* instanciaMC = ManejadorCurso::getInstancia();
    return instanciaMC->obtenerCursosNoHab();
};

void CtrCurso::seleccionarCurso(string nombreCurso){
    ManejadorCurso* instanciaMC = ManejadorCurso::getInstancia();
    this->cursoRecAgregar = instanciaMC->obtenerCurso(nombreCurso);
};

void CtrCurso::crearDatosLeccion(string tema, string objetivo){
    this->temaRec = tema;
    this->objetivoRec = objetivo;
};

void CtrCurso::ingresarTipoEjercicio(TipoEjercicio tipoejercicio, string descripcion){
    this->tipoejercicioRec = tipoejercicio;
    this->descripcionEjRec = descripcion;
}

void CtrCurso::ingresarFraseCompletar(string frase, map<int, string>* solucion){
    this->fraseEjRec = frase;
    this->solucionFCRec = solucion; 
};

void CtrCurso::ingresarFraseTraduccion(string frase, string traduccion){
    this->fraseEjRec = frase;
    this->solucionTRec = traduccion;
};

void CtrCurso::DarDeAltaEjercicio(){
    Ejercicio* nuevoEjercicio;
    if (this->ejerciciosNuevos == NULL)
        this->ejerciciosNuevos = new map<int, Ejercicio*>;
    if (this->tipoejercicioRec == completarPalabra){
        nuevoEjercicio = new CompletarPalabra(this->ejerciciosNuevos->size() , this->descripcionEjRec, this->fraseEjRec, this->solucionFCRec);
        this->ejerciciosNuevos->insert(pair<int, Ejercicio*>(nuevoEjercicio->getId(), nuevoEjercicio));
    }else{
        nuevoEjercicio = new Traducir(this->ejerciciosNuevos->size() , descripcionEjRec, fraseEjRec, solucionTRec);
        this->ejerciciosNuevos->insert(pair<int, Ejercicio*>(nuevoEjercicio->getId(), nuevoEjercicio));
    };
};

void CtrCurso::DarDeAltaLeccion(){
    cursoRecAgregar->añadirLeccion(this->ultimaLeccion);
    this->leccionesRec->clear();
    this->ultimaLeccion = NULL;
};

//Agregar ejercicio
set<DTLeccion*>* CtrCurso::obtenerLecciones(){
    return this->cursoRecAgregar->getLecciones();
};

void CtrCurso::agregarEjercicio(int lec, string descripcion, string frase, map<int, string>* solucion){
    this->cursoRecAgregar->nuevoEjercicio(lec, descripcion, frase, solucion);
};

void CtrCurso::agregarEjercicio(int lec, string descripcion, string frase, string solucion){
    this->cursoRecAgregar->nuevoEjercicio(lec, descripcion, frase, solucion);
};

//Alta Idioma
void CtrCurso::IngresarIdioma(string nombreIdioma){
	this->nombreRecordado = nombreIdioma;
}
bool CtrCurso::ConfirmarIdioma(){ 
	ManejadorIdioma* mi = ManejadorIdioma::getInstancia();
	bool existe = mi->existeIdioma(this->nombreRecordado);
	if (!existe) {
		Idioma* I= new Idioma(this->nombreRecordado);
		mi->agregarIdioma(I);
	}
	return !existe;
}
//ConsultarIdioma
set<string>* CtrCurso::ConsultarIdioma() {
	ManejadorIdioma* mi = ManejadorIdioma::getInstancia();
	return mi->IdiomasDisponibles();
 }

//ConsultarEstadisticas

 set<string>* CtrCurso::ObtenerEstudiantes() {
	ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
	set<Estudiante*>* aux = mu->obtenerEstudiantes();
	set<string>* nickAlumnos= new set<string>;
	for (set<Estudiante*>::iterator it = aux->begin(); it != aux->end(); it++)
		nickAlumnos->insert((*it)->getNickname());
	return nickAlumnos;
};
map<int,DTCurso*>* CtrCurso::obtenerCursosInscripto(string nickname) {
    
	ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    if(!mu->ExisteUsuario(nickname)){return NULL;}
    this->nombreRecordado=nickname;
    Usuario* u = mu->obtenerUsuario(nickname);
	Profesor* prof = dynamic_cast <Profesor*> (u);
    map<int,DTCurso*>* infoCursos= new map<int,DTCurso*>;
    if (prof==NULL){
        Estudiante* es = dynamic_cast <Estudiante*>(u);
        map <string,Curso*>* aux = es->obtenerCursos();
        this->cursosRecordados=aux;
        int i=1;
        for (map<string,Curso*>::iterator it = aux->begin();it!=aux->end();it++){
            DTCurso* dtc = new DTCurso(it->second);
            infoCursos->insert(pair<int,DTCurso*>(i,dtc));
            i++;
        }
        return infoCursos;
    }
    else{
        map <string,Curso*>* aux = prof->obtenerCursos();
        this->cursosRecordados=aux;
        int i = 1;
        for (map<string,Curso*>::iterator it = aux->begin();it!=aux->end();it++){
            DTCurso* dtc = new DTCurso(it->second);
            infoCursos->insert(pair<int,DTCurso*>(i,dtc));
            i++;
        }
        return infoCursos;
    }

};
map<int,float>* CtrCurso::obtenerAvanceCursos() {
	map<int,float>* res=new map<int,float>;
	map<string, Curso*>* aux = this->cursosRecordados;
    int i=1;
	for (map<string, Curso*>::iterator it = aux->begin(); it != aux->end(); it++){
		res->insert(pair<int,float>(i,it->second->obtenerAvanceCurso(this->nombreRecordado)));
        i++;
    }
	return res;
};
set<string>* CtrCurso::ObtenerProfesores() {
	ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
	set<Profesor*>* aux = mu->obtenerProfesores();
	set<string>* nickProf=new set<string>;
	for (set<Profesor*>::iterator it = aux->begin(); it != aux->end(); it++)
		nickProf->insert((*it)->getNickname());
	return nickProf;
};
map<int,float>* CtrCurso::obtenerPromedioCursos() {
	map<int,float>* res=new map<int,float>;
	map<string,Curso*>* aux = this->cursosRecordados;
    int i=1;
    if (aux->begin()==aux->end()){
        cout<<"Profesor no tiene cursos\n";
    }
	for (map<string,Curso*>::iterator it = aux->begin(); it != aux->end(); it++){
		res->insert(pair<int,float>(i,it->second->obtenerPromedioCurso()));
        i++;
    }
	return res;
};
set<DTCurso*>* CtrCurso::obtenerCursos() {
	ManejadorCurso* mc = ManejadorCurso::getInstancia();
	map<string,Curso*>* aux = mc->obtenerTodosCursos();
	set<DTCurso*>* res=new set<DTCurso*>;
	for (map<string,Curso*>::iterator it = aux->begin(); it != aux->end(); it++){
        DTCurso* dtc = new DTCurso(it->second); 
		res->insert(dtc);
    }
	return res;
};
float CtrCurso::obtenerPromedio() {
	return this->cursoRecAgregar->obtenerPromedioCurso();
};

bool CtrCurso::habilitarCurso(){
    return this->cursoRecAgregar->habilitarCurso();
};

bool CtrCurso::existeCurso(string nombreCurso){
    ManejadorCurso* instanciaMC = ManejadorCurso::getInstancia();
    return instanciaMC->ExisteCurso(nombreCurso);
}

void CtrCurso::eliminarCurso(){
    ManejadorIdioma* instanciaMI = ManejadorIdioma::getInstancia();
    ManejadorCurso* instanciaMC = ManejadorCurso::getInstancia();
    ManejadorUsuario* instanciaMU = ManejadorUsuario::getInstancia();

    //eliminar lecciones y ejercicios
    map<int, Leccion*>* lecciones = this->cursoRecAgregar->getColLecciones();

    for(map<int, Leccion*>::iterator it = lecciones->begin(); it != lecciones->end(); it++){
        //eliminar ejercicios
        it->second->eliminarEjercicios();
    }
    cursoRecAgregar->eliminarLecciones();
    
    //eliminar previas
    instanciaMC->eliminarPrevia(cursoRecAgregar->getNombre());
    cursoRecAgregar->borrarPrevias();

    //eliminar curso de idioma correspondiente
    Idioma* idiomaDeCurso = instanciaMI->obtenerIdioma(cursoRecAgregar->getIdioma());
    idiomaDeCurso->removerCurso(cursoRecAgregar->getNombre());

    //eliminar inscripciones
    map<string,Estudiante*>* estudiantes = this->cursoRecAgregar->getEstudiantes();
    if (estudiantes != NULL)
    {
        for(map<string, Estudiante*>::iterator it = estudiantes->begin(); it != estudiantes->end(); it++){
            it->second->removerCurso(cursoRecAgregar->getNombre());
        }
    }

    //eliminar de la lista de cursos del profesor 
    Profesor* profesor = dynamic_cast<Profesor*>(instanciaMU->obtenerUsuario(cursoRecAgregar->getNicknameProfesor()));
    if (profesor != NULL)
    {
        profesor->eliminarCurso(cursoRecAgregar->getNombre());
    }

    instanciaMC->eliminarCurso(cursoRecAgregar->getNombre());

    cursoRecAgregar->~Curso();
}

DTCurso* CtrCurso::obtenerCurso(string nombreCurso){
    ManejadorCurso* instanciaMC = ManejadorCurso::getInstancia();

    return new DTCurso(instanciaMC->obtenerCurso(nombreCurso));
}

map<int, DTLeccion*>* CtrCurso::obtenerLeccionesDeCurso(){
    map<int, Leccion*>* lecciones = cursoRecAgregar->getColLecciones();
    map<int, DTLeccion*>* leccionesDeCurso = new map<int, DTLeccion*>;

    for(map<int, Leccion*>::iterator it = lecciones->begin(); it != lecciones->end(); it++){
        DTLeccion* leccion = new DTLeccion(it->second->getOrden(), it->second->getTema(), it->second->getObjetivo());

        leccionesDeCurso->insert(pair<int, DTLeccion*>(it->first, leccion));
    }

    return leccionesDeCurso;
}

map<int, DTEjercicio*>* CtrCurso::obtenerEjercicios(int leccion){
    Leccion* lec = cursoRecAgregar->getColLecciones()->at(leccion);
    map<int, DTEjercicio*>* ejercicios = new map<int, DTEjercicio*>;

    for(map<int, Ejercicio*>::iterator it = lec->getColEjercicios()->begin(); it != lec->getColEjercicios()->end(); it++){
        DTEjercicio* ejercicio = new DTEjercicio(it->first, it->second->getDescripcion());

        pair<int, DTEjercicio*> par;
        par.first = it->second->getId();
        par.second = ejercicio;
        ejercicios->insert(par);
    }
    
    return ejercicios;
}