# include "../include/ManejadorUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario(){
    this->Usuarios = new map<string, Usuario*>;
};

ManejadorUsuario *ManejadorUsuario::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorUsuario();
    return instancia;
};

bool ManejadorUsuario::ExisteUsuario(string nickname){
    map<string, Usuario*>::iterator it = this->Usuarios->find(nickname);
    if (it == this->Usuarios->end())
        return false;
    else 
        return true;
};

void ManejadorUsuario::agregarUsuario(Usuario* nuevoUsuario){
    this->Usuarios->insert(pair<string, Usuario*>(nuevoUsuario->getNickname(), nuevoUsuario));
};

Usuario *ManejadorUsuario::obtenerUsuario(string nickname){
    map<string, Usuario*>::iterator it = this->Usuarios->find(nickname);
    if (it == this->Usuarios->end())
        return NULL;
    else 
        return it->second;
};

ManejadorUsuario::~ManejadorUsuario(){};

set<Estudiante*> *ManejadorUsuario::obtenerEstudiantes(){
        set<Estudiante*>* res= new set<Estudiante*>;
    for (map<string,Usuario*>::iterator it = this->Usuarios->begin(); it != this->Usuarios->end();it++){
        Estudiante* es = dynamic_cast <Estudiante*> (it->second);
        if (es!=NULL){
            res->insert(es);
        }
    }
    return res;
};

set<Profesor*> *ManejadorUsuario::obtenerProfesores(){
      set<Profesor*>* res = new set<Profesor*>;
    for (map<string,Usuario*>::iterator it = this->Usuarios->begin(); it != this->Usuarios->end();it++){
        Profesor* p = dynamic_cast <Profesor*> (it->second);
        if (p!=NULL){
            res->insert(p);
        }
    }
    return res;
};

set<string>* ManejadorUsuario::obtenerNombres(){
    set<string>* Nombres = new set<string>;
    for (map<string, Usuario*>::iterator it = this->Usuarios->begin(); it != this->Usuarios->end(); it++)
        Nombres->insert(it->second->getNombre());
    return Nombres;
};

set<string> *ManejadorUsuario::obtenerNickname(){
    set<string>* NickN = new set<string>;
    for (map<string, Usuario*>::iterator it = this->Usuarios->begin(); it != this->Usuarios->end(); it++)
        NickN->insert(it->second->getNickname());
    return NickN;
}

set<string>* ManejadorUsuario::obtenerNombresProfesor(){
    set<string>* Nombres = new set<string>;
    for (map<string, Usuario*>::iterator it = this->Usuarios->begin(); it != this->Usuarios->end(); it++){
        Profesor* prof = dynamic_cast<Profesor*>(it->second);
        if (prof != NULL)
            Nombres->insert(it->second->getNickname());
    }
    return Nombres;
};

void ManejadorUsuario::agregarCursoColeccion(Curso curso){};

void ManejadorUsuario::aprobarEjercicio(Ejercicio* ejercicio, string nickname, string nombreCurso){
    Estudiante* estudiante = dynamic_cast<Estudiante*>(this->Usuarios->find(nickname)->second);

    Inscripcion* inscripcion = estudiante->getInscripciones()->find(nombreCurso)->second;
    Curso* curso = inscripcion->getCursoInscripto();    

    map<int, Leccion*>* colLecciones = curso->getColLecciones();  
    int tamanio = curso->getCantLecciones();   
    bool leccionAprobada = true;
    //si existe mas de una leccion  
    if (tamanio != 1){
        Leccion* ultimaLeccionAprobada = inscripcion->getUltimaLeccionAprobada();
        int ultimaLeccionOrden = 0;
        if (ultimaLeccionAprobada != NULL){
            ultimaLeccionOrden = ultimaLeccionAprobada->getOrden();
        }
        //si hay mas lecciones despues de la ultima aprobada
        if (tamanio > ultimaLeccionOrden + 1){
            Leccion* leccionActual = colLecciones->find(ultimaLeccionOrden + 1)->second;
            
            map<int, Ejercicio*>* colEjercicios = leccionActual->getColEjercicios();
            Ejercicio* ej = colEjercicios->find(ejercicio->getId())->second;
            
            ej->addEstudianteAprobado(inscripcion);

            for(map<int, Ejercicio*>::iterator itColEj = colEjercicios->begin(); (itColEj != colEjercicios->end()) && leccionAprobada == true; itColEj++){
                leccionAprobada = itColEj->second->esAprovado(nickname);
            }

            // si es el ultimo ejercicio de la leccion seteo la leccion como aprobada y actualizo la ultima leccion aprobada
            if (leccionAprobada){
                inscripcion->setNuevaLeccionAprobada(leccionActual);
                if (leccionActual->getOrden() == tamanio){
                    inscripcion->setAprobada(true);
                }
            }
        } 
        //si la ultima leccion aprobada es la ultima
        else {
            Leccion* leccionActual = colLecciones->find(ultimaLeccionOrden + 1)->second;
            
            map<int, Ejercicio*>* colEjercicios = leccionActual->getColEjercicios();
            Ejercicio* ej = colEjercicios->find(ejercicio->getId())->second;

            ej->addEstudianteAprobado(inscripcion);

            for(map<int, Ejercicio*>::iterator itColEj = colEjercicios->begin(); (itColEj != colEjercicios->end()) && leccionAprobada == true; itColEj++){
                leccionAprobada = itColEj->second->esAprovado(nickname);
            }

            // si es el ultimo ejercicio de la leccion seteo la leccion como aprobada y actualizo la ultima leccion aprobada
            if (leccionAprobada){
                inscripcion->setNuevaLeccionAprobada(leccionActual);
                if (leccionActual->getOrden() == tamanio){
                    inscripcion->setAprobada(true);
                }
            }
        }
    } 
    //si es una sola leccion
    else {
        Leccion* leccionActual = colLecciones->find(1)->second;
            
        map<int, Ejercicio*>* colEjercicios = leccionActual->getColEjercicios();
        Ejercicio* ej = colEjercicios->find(ejercicio->getId())->second;

        ej->addEstudianteAprobado(inscripcion);

        for(map<int, Ejercicio*>::iterator itColEj = colEjercicios->begin(); (itColEj != colEjercicios->end()) && leccionAprobada == true; itColEj++){
            leccionAprobada = itColEj->second->esAprovado(nickname);
        }

        // si es el ultimo ejercicio de la leccion seteo la leccion como aprobada y actualizo la ultima leccion aprobada
        if (leccionAprobada){
            inscripcion->setNuevaLeccionAprobada(leccionActual);
            if (leccionActual->getOrden() == tamanio){
                inscripcion->setAprobada(true);
            }
        }
    }        
}
