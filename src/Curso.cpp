#include "../include/Curso.h"
#include "../include/Estudiante.h"
#include "../include/Leccion.h"
#include "../include/DTLeccion.h"

Curso::Curso(string nombre, string descripcion, Nivel nivel){
    this->Nombre = nombre;
    this->Descripcion = descripcion;
    this->Dificultad = nivel;
    this->Previas = new map<string,Curso*>;
    this->alumnosInscriptos = new map<string, Estudiante*>;
    this->Lecciones = new map<int, Leccion*>;

};

Curso::Curso(string nombre, string descripcion, Nivel nivel, Profesor* profesor, Idioma* idioma){
    this->Nombre = nombre;
    this->Descripcion = descripcion;
    this->Dificultad = nivel;
    this->ProfesorCurso = profesor;
    this->IdiomaCurso = idioma;
    this->Previas = new map<string,Curso*>;
    this->alumnosInscriptos = new map<string, Estudiante*>;
    this->Lecciones = new map<int, Leccion*>;
};

int Curso::getCantEjercicios(){
    int result = 0;
    for(map<int,Leccion*>::iterator LeccionesIt = this->Lecciones->begin(); LeccionesIt!=this->Lecciones->end();LeccionesIt++){
        result += LeccionesIt->second->getColEjercicios()->size();
    }
    return result;
}

map<string,Curso*>* Curso::getPrevias(){
    return this->Previas;
}

string Curso::getNombre(){
    return this->Nombre;
}

string Curso::getDescripcion(){
    return this->Descripcion;
};

Nivel Curso::getDificultad(){
    return this->Dificultad;
};

bool Curso::getHabilitado(){
    return this->Habilitado;
};

string Curso::getIdioma(){
    if (this->IdiomaCurso == NULL)
        return "No asociado a ningun idioma";
    else 
        return IdiomaCurso->getNombre();
};

int Curso::getCantLecciones(){
    if (this->Lecciones == NULL){
        return 0;
    } else {
        return this->Lecciones->size();
    }    
};

int Curso::getCantInscriptos(){
    return this->alumnosInscriptos->size();
}

void Curso::setProfesor(Profesor* profesor){
    this->ProfesorCurso = profesor;
};

void Curso::setHabilitado(bool habilitado){
    this->Habilitado = habilitado;
};

void Curso::removerPrevia(string nombreCurso){};

DTCurso* Curso::getDataCurso(){
    DTCurso* dataCurso = new DTCurso(this->getNombre(), this->getDescripcion(), this->getProfesor(), this->getIdioma(), this->getHabilitado()); 
    return dataCurso;   
};

void Curso::añadirLeccion(Leccion* lec){
    lec->setOrden(this->Lecciones->size() + 1);
    this->Lecciones->insert(pair<int, Leccion*>(this->Lecciones->size() + 1, lec));
};

void Curso::añadirPrevia(Curso* previa){
    this->Previas->insert(pair<string,Curso*>(previa->getNombre(),previa));
};

float Curso::obtenerAvanceCurso(string nickEstudiante){
    float tot=0;
    float ap=0;
    for(map<int,Leccion*>::iterator it = this->Lecciones->begin();it!=this->Lecciones->end();it++){
        it->second->contarEjercicios(tot,ap,nickEstudiante);
    }
    if(tot==0){
        return 0;}
    else{
    return ap/tot;
    }
};

float Curso::obtenerPromedioCurso(){
    float t=0;
    float p=0;
    if(alumnosInscriptos==NULL){
        return 0;
    }
    for(map<string,Estudiante*>::iterator it = this->alumnosInscriptos->begin();it!=this->alumnosInscriptos->end();it++){
        t++;
        p = p + this->obtenerAvanceCurso(it->second->getNickname());
    }
    if(t==0){
        return 0;}
    else{
    return p/t;
    }
};


Leccion* Curso::obtenerSiguienteLeccion(int orden){return NULL;};

void  Curso::inscribirEstudiante(Estudiante* estudiante){
    this->alumnosInscriptos->insert(pair<string, Estudiante*>(estudiante->getNickname(),estudiante));
};

set<DTLeccion*>* Curso::getLecciones(){
    set<DTLeccion*>* leccionesCurso = new set<DTLeccion*>;
    DTLeccion* dataLeccion;
    for (map<int, Leccion*>::iterator it = this->Lecciones->begin(); it != this->Lecciones->end(); it++){
        dataLeccion = new DTLeccion(it->second->getOrden(), it->second->getTema(), it->second->getObjetivo());
        leccionesCurso->insert(dataLeccion);
    };
    if (leccionesCurso->empty()){
        delete leccionesCurso;
        return NULL;
    }else{
        return leccionesCurso;
    };
};

void Curso::nuevoEjercicio(int lec, string descripcion, string frase, map<int, string>* solucion){
    map<int, Leccion*>::iterator it = this->Lecciones->find(lec);
    it->second->añadirEjercicio(descripcion, frase, solucion);
};

void Curso::nuevoEjercicio(int lec, string descripcion, string frase, string solucion){
    map<int, Leccion*>::iterator it = this->Lecciones->find(lec);
    it->second->añadirEjercicio(descripcion, frase, solucion);
};

bool Curso::habilitarCurso(){
    bool posible = false;
    if(this->Lecciones->size() >= 1){
        posible = true;
        for(map<int, Leccion*>::iterator it = Lecciones->begin(); it != Lecciones->end() && posible == true; it++){
            if (it->second->getCantEjercicios() <= 0){
                posible = false;
            };
        };
    };
    if (posible)
        this->setHabilitado(true);
    return posible;
};

map<int, Leccion*>* Curso::getColLecciones(){
    return this->Lecciones;
};

void Curso::eliminarLecciones(){
    this->Lecciones->clear();
}

void Curso::eliminarPrevias(string nomCurso){
    this->Previas->erase(nomCurso);
}

string Curso::getProfesor(){
    return this->ProfesorCurso->getNombre();
}

map<string,Estudiante*>* Curso::getEstudiantes(){
    return this->alumnosInscriptos;
}

string Curso::getNicknameProfesor(){
    return this->ProfesorCurso->getNickname();
}
void Curso::borrarPrevias(){
    this->Previas->clear();
}

Curso::~Curso(){};
