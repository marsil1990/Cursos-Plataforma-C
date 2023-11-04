#include "include/CtrUsuario.h"
#include "include/CtrCurso.h"
#include "include/DTEstudiante.h"
#include "include/DTFecha.h"
#include "include/DTEjercicio.h"
#include "include/DTNotificacion.h"
#include "include/DTProfesor.h"
#include "include/DTInscripcion.h"
#include "include/DTUsuario.h"
#include "include/Estudiante.h"
#include "include/Idioma.h"
#include "include/ManejadorIdioma.h"
#include "include/ManejadorUsuario.h"
#include "include/Profesor.h"   
#include "include/Usuario.h"
#include "include/Fabrica.h"
#include "include/IUsuario.h"
#include "include/ICurso.h"
#include "include/ManejadorCurso.h"
#include "include/Inscripcion.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include "include/DTLeccion.h"
# include <iostream>
# include <iomanip>
using namespace std;

DTFecha* transformarStringTofecha(string nuevoUsuarioFechaDeNacimientoDia,string nuevoUsuarioFechaDeNacimientoMes,string nuevoUsuarioFechaDeNacimientoAnio){
    int dia = stoi(nuevoUsuarioFechaDeNacimientoDia);
    int mes = stoi(nuevoUsuarioFechaDeNacimientoMes);
    int anio = stoi(nuevoUsuarioFechaDeNacimientoAnio);
    return new DTFecha(anio,mes,dia);
};

set<string>* stringToSet(string cadena){
    string word = "";
    set<string>* res = new set<string>;
    for (auto x : cadena){
        if (x == ','){
            res->insert(word);
            word = "";
        }else if (x != ' ' && x != '.'){
            word = word + x;
        }
    };
    res->insert(word);
    return res;
};

map<int, string>* stringToMap(string cadena){
    string word = "";
    map<int, string>* res = new map<int, string>;
    int i = 1;
    for (auto x : cadena){
        if (x == ','){
            res->insert(pair<int, string>(i, word));
            word = "";
            i++;
        }else if (x != ' ' && x != '.'){
            word = word + x;
        }
    };
    res->insert(pair<int, string>(i, word));
    return res;
};

void ejecutarCargarDatosPrueba(){
    Fabrica* f = Fabrica::getInstancia();
    ICurso* cc = f->getICurso();
    IUsuario* cu = f->getIUsuario();
    
    
    try //Crear Idiomas
    {        
        cc->IngresarIdioma("Ingles");
        cc->ConfirmarIdioma();
        cc->IngresarIdioma("Aleman");
        cc->ConfirmarIdioma();
        cc->IngresarIdioma("Portugues");
        cc->ConfirmarIdioma();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    try //Crear Usuarios
    {       
        cu->IngresarDatosUsuario("jpidiom","asdfg123","Soy un apasionado del aprendizaje de idiomas.","Juan Perez");
        DTFecha* fechaU1 = transformarStringTofecha("15","07","1995");
        cu->IngresarDatoEstudiante("Argentina",fechaU1);
        cu->AltaEstudiante();

        cu->IngresarDatosUsuario("marsilva","qwer456","Como amante de los idiomas disfruto explorando nuevas formas de interactuar.","Maria Silva");
        DTFecha* fechaU2 = transformarStringTofecha("28","02","1998");
        cu->IngresarDatoEstudiante("Ecuador",fechaU2);
        cu->AltaEstudiante();

        cu->IngresarDatosUsuario("pero12","789werty","Soy un apasionado del aprendizaje de idiomas.","Pedro Rodriguez");
        DTFecha* fechaU3 = transformarStringTofecha("10","11","1994");
        cu->IngresarDatoEstudiante("Peru",fechaU3);
        cu->AltaEstudiante();

        cu->IngresarDatosUsuario("laugu","c1v2b3m4","Estoy fascinada por la forma en que las palabras pueden unir a las personas","Laura Gutierrez");
        DTFecha* fechaU4 = transformarStringTofecha("22","04","1997");
        cu->IngresarDatoEstudiante("Chile",fechaU4);
        cu->AltaEstudiante();
        
        cu->IngresarDatosUsuario("carlo22","tyuipz147","Emocionado por adquirir fluidez en diferentes lenguas.","Carlos Lopez");
        DTFecha* fechaU5 = transformarStringTofecha("03","09","1996");
        cu->IngresarDatoEstudiante("Uruguay",fechaU5);
        cu->AltaEstudiante();

        cu->IngresarDatosUsuario("anator","1qsxc36","Disfruto de la belleza de las diferentes estructuras y sonidos.","Ana Torres");
        DTFecha* fechaU6 = transformarStringTofecha("12","01","1999");
        cu->IngresarDatoEstudiante("Argentina",fechaU6);
        cu->AltaEstudiante();
        
        cu->IngresarDatosUsuario("luher24","t7h8y5u6","Emocionada en la riqueza cultural que cada idioma ofrece.","Lucia Hernandez");
        DTFecha* fechaU7 = transformarStringTofecha("25","06","1993");
        cu->IngresarDatoEstudiante("Colombia",fechaU7);
        cu->AltaEstudiante();

        cu->IngresarDatosUsuario("dagon","1w2e3r4t5","Aprender nuevas lenguas y sumergirme en diferentes culturas.","David Gonzalez");
        DTFecha* fechaU8 = transformarStringTofecha("08","12","1997");
        cu->IngresarDatoEstudiante("Uruguay",fechaU8);
        cu->AltaEstudiante();

        cu->IngresarDatosUsuario("carmor","6yu7i8m9","El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.","Carmen Morales");
        DTFecha* fechaU9 = transformarStringTofecha("17","03","1995");
        cu->IngresarDatoEstudiante("Chile",fechaU9);
        cu->AltaEstudiante();

        cu->IngresarDatosUsuario("jose24","qwj789p","Disfruto del proceso de descubrir nuevas formas de comunicarme","Jose Fernandez");
        DTFecha* fechaU10 = transformarStringTofecha("02","08","1998");
        cu->IngresarDatoEstudiante("Bolivia",fechaU10);
        cu->AltaEstudiante();

        cu->IngresarDatosUsuario("langMaster","P4s512","Soy una profesora apasionada por los idiomas.","Marta Grecia");
        cu->AgregarEspecializacion("Ingles");
        cu->AgregarEspecializacion("Portugues");
        cu->IngresarInstituto("Instituto de Idiomas Moderno");
        cu->AltaProfesor();

        cu->IngresarDatosUsuario("linguaPro","Pess23","Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas","Carlos Petro");
        cu->AgregarEspecializacion("Ingles");
        cu->AgregarEspecializacion("Aleman");
        cu->AgregarEspecializacion("Portugues");
        cu->IngresarInstituto("Centro Global");
        cu->AltaProfesor();

        cu->IngresarDatosUsuario("talkExpert","Secret1","Soy una profesora entusiasta del aprendizaje de idiomas","Laura Perez");
        cu->AgregarEspecializacion("Aleman");
        cu->IngresarInstituto("Instituto de Idiomas Vanguardia");
        cu->AltaProfesor();

        cu->IngresarDatosUsuario("lingoSensei","Secure2","Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos","Franco Lopez");
        cu->AgregarEspecializacion("Portugues");
        cu->IngresarInstituto("Centro de Idiomas");
        cu->AltaProfesor();
        
        cu->IngresarDatosUsuario("wordMaestro","Passw0","Soy una profesora comprometida en desarrollo de habilidades idiomaticas","Ana Morales");
        cu->AgregarEspecializacion("Ingles");
        cu->IngresarInstituto("Instituto de Idiomas Progreso");
        cu->AltaProfesor();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try //Crear Cursos  
    {              
        cc->seleccionarProfesor("langMaster");
        cc->ingresarDatosCurso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.",Principiante);
        cc->seleccionarIdioma("Ingles");
        cc->necesitaPrevia(false);
        cc->crearLeccion("Saludos y Presentaciones", "Aprender a saludar y despedirse");
        cc->crearEjercicioTraducir("Presentaciones", "Mucho gusto en conocerte", "Nice to meet you");
        map<int, string>* res1 = new map<int, string>;
        res1->insert(pair<int, string>(1, "allow"));
        res1->insert(pair<int, string>(2,"myself"));    
        cc->crearEjercicioCompletarPalabra("Presentaciones formales","Please — me to introduce —",res1);
        cc->crearLeccion("Articulos y Plurales", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
        cc->crearEjercicioTraducir("Plurales regulares", "I have two brothers and three sisters", "Tengo dos hermanos y tres hermanas");
        map<int, string>* res2 = new map<int, string>;
        res2->insert(pair<int, string>(1, "some"));
        cc->crearEjercicioCompletarPalabra("Sustantivos contables en plural","Can I have — water, please?",res2);
        cc->ConfirmarAltaCurso();

        cc->seleccionarProfesor("langMaster");
        cc->ingresarDatosCurso("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.",Principiante);
        cc->seleccionarIdioma("Ingles");
        cc->necesitaPrevia(false);
        cc->crearLeccion("Actividades Cotidianas", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
        map<int, string>* res3 = new map<int, string>;
        res3->insert(pair<int, string>(1, "up"));
        cc->crearEjercicioCompletarPalabra("Actividades diarias","Wake —",res3);
        cc->crearLeccion("Presente Simple", "Aprender el uso del presente simple");
        cc->ConfirmarAltaCurso();

        cc->seleccionarProfesor("linguaPro");
        cc->ingresarDatosCurso("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura",Intermedio);
        cc->seleccionarIdioma("Ingles");
        cc->necesitaPrevia(true);
        set<string>* sel1=new set<string>;
        sel1->insert("Ingles para principiantes");
        cc->seleccionarPrevias(sel1);
        cc->crearLeccion("Conversaciones cotidianas", "Aprender a hacer preguntas y respuestas en situaciones comunes");
        map<int, string>* res4 = new map<int, string>;
        res4->insert(pair<int, string>(1, "have"));
        res4->insert(pair<int, string>(2, "past")); 
        cc->crearEjercicioCompletarPalabra("Consultas de la hora","Q: Do you — the time?, A: Yes, it is half — 4",res4);
        cc->ConfirmarAltaCurso();

        cc->seleccionarProfesor("linguaPro");
        cc->ingresarDatosCurso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.",Avanzado);
        cc->seleccionarIdioma("Ingles");
        cc->necesitaPrevia(true);
        set<string>* sel2=new set<string>;
        sel2->insert("Ingles para principiantes");
        sel2->insert("Ingles intermedio: mejora tu nivel");
        cc->seleccionarPrevias(sel2);
        cc->crearLeccion("Uso de modales avanzados", "Explorar el uso de los modales complejos");
        cc->crearEjercicioTraducir("Dar consejos o expresar obligacion","You should visit that museum", "Deberias visitar ese museo");
        cc->ConfirmarAltaCurso();

        cc->seleccionarProfesor("linguaPro");
        cc->ingresarDatosCurso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.",Intermedio);
        cc->seleccionarIdioma("Portugues");
        cc->necesitaPrevia(false);
        cc->crearLeccion("Lectura y comprension de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas");
        cc->crearEjercicioTraducir("Imperativo","Fale comigo", "Habla conmigo");
        cc->ConfirmarAltaCurso();

        cc->seleccionarProfesor("lingoSensei");
        cc->ingresarDatosCurso("Portugues avanzado", "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.",Avanzado);
        cc->seleccionarIdioma("Portugues");
        cc->necesitaPrevia(true);
        set<string>* sel3= new set<string>;
        sel3->insert("Portugues intermedio");
        cc->seleccionarPrevias(sel3);
        cc->ConfirmarAltaCurso();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try//Habilitar cursos
    {
        cc->seleccionarCurso("Ingles para principiantes");
        cc->habilitarCurso();
        cc->seleccionarCurso("Ingles intermedio: mejora tu nivel");
        cc->habilitarCurso();
        cc->seleccionarCurso("Curso avanzado de ingles");
        cc->habilitarCurso();
        cc->seleccionarCurso("Portugues intermedio");
        cc->habilitarCurso();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try//Inscribirse a curso
    {
        string curso1 = "Ingles para principiantes";
        string curso3 = "Ingles intermedio: mejora tu nivel";
        string curso4 = "Curso avanzado de ingles";
        string curso5 = "Portugues intermedio";
        DTFecha * f1 = new DTFecha(2022,1,1);
        DTFecha * f4 = new DTFecha(2022,1,2);
        DTFecha * f5 = new DTFecha(2022,1,2);
        DTFecha * f6 = new DTFecha(2022,1,3);
        DTFecha * f7 = new DTFecha(2023,1,3);
        DTFecha * f8 = new DTFecha(2023,1,5);

        DTEstudiante* estudianteU1 = cu->seleccionarEstudiante("jpidiom");
        cu->IngresarCursoSeleccionado(curso1);
        cu->FinalizarInscripcionACurso(estudianteU1->getNickname(),f1);

        DTEstudiante* estudianteU2 = cu->seleccionarEstudiante("marsilva");
        cu->IngresarCursoSeleccionado(curso1);
        cu->FinalizarInscripcionACurso(estudianteU2->getNickname(), f4);

        DTEstudiante* estudianteU3 = cu->seleccionarEstudiante("pero12");
        cu->IngresarCursoSeleccionado(curso1);
        cu->FinalizarInscripcionACurso(estudianteU3->getNickname(), f5);


        DTEstudiante* estudianteU4 = cu->seleccionarEstudiante("laugu");
        cu->IngresarCursoSeleccionado(curso1);
        cu->FinalizarInscripcionACurso(estudianteU4->getNickname(), f6);
        cu->IngresarCursoSeleccionado(curso5);
        cu->FinalizarInscripcionACurso(estudianteU4->getNickname(), f7);


        DTEstudiante* estudianteU5 = cu->seleccionarEstudiante("carlo22");
        cu->IngresarCursoSeleccionado(curso5);
        cu->FinalizarInscripcionACurso(estudianteU5->getNickname(), f8);


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //Realizar ejercicios
        cu->recordarUsuario("jpidiom");
        cu->IngresarCursoSeleccionado("Ingles para principiantes");
        map<int, DTEjercicio*>* ejercicios = cu->obtenerEjerciciosNoAprobados();
        pair<int, DTEjercicio*>* ejercicio1 = new pair<int, DTEjercicio*>(ejercicios->find(1)->first, ejercicios->find(1)->second);
        cu->recordarEjercicio(ejercicio1);
        cu->mostrarEjercicioaux();
        cu->resolverTraducir("Nice to meet you");

        cu->recordarUsuario("jpidiom");
        cu->IngresarCursoSeleccionado("Ingles para principiantes");
        ejercicios = cu->obtenerEjerciciosNoAprobados();
        pair<int, DTEjercicio*>* ejercicio2 = new pair<int, DTEjercicio*>(ejercicios->find(2)->first, ejercicios->find(2)->second);
        cu->recordarEjercicio(ejercicio2);
        cu->mostrarEjercicioaux();
        map<int, string>* resu1 = new map<int, string>;
        resu1->insert(pair<int, string>(1, "allow"));
        resu1->insert(pair<int, string>(2,"myself"));
        cu->resolverCompletarPalabra(resu1);

        //Fin Primer leccion
        cu->recordarUsuario("jpidiom");
        cu->IngresarCursoSeleccionado("Ingles para principiantes");
        ejercicios = cu->obtenerEjerciciosNoAprobados();
        pair<int, DTEjercicio*>* ejercicio3 = new pair<int, DTEjercicio*>(ejercicios->find(1)->first, ejercicios->find(1)->second);
        cu->recordarEjercicio(ejercicio3);
        cu->mostrarEjercicioaux();
        cu->resolverTraducir("Tengo dos hermanos y tres hermanas");
       
        cu->recordarUsuario("jpidiom");
        cu->IngresarCursoSeleccionado("Ingles para principiantes");
        ejercicios = cu->obtenerEjerciciosNoAprobados();
        pair<int, DTEjercicio*>* ejercicio4 = new pair<int, DTEjercicio*>(ejercicios->find(2)->first, ejercicios->find(2)->second);
        cu->recordarEjercicio(ejercicio4);
        cu->mostrarEjercicioaux();
        map<int, string>* resu2 = new map<int, string>;
        resu2->insert(pair<int, string>(1, "some"));
        cu->resolverCompletarPalabra(resu2);
        //Fin Segunda leccion
        DTFecha * f2 = new DTFecha(2022,6,12);
        DTFecha * f3 = new DTFecha(2023,3,3);
        cu->IngresarCursoSeleccionado("Ingles intermedio: mejora tu nivel"); 
        cu->FinalizarInscripcionACurso("jpidiom",f2);

        cu->recordarUsuario("jpidiom");
        cu->IngresarCursoSeleccionado("Ingles intermedio: mejora tu nivel");
        ejercicios = cu->obtenerEjerciciosNoAprobados();
        pair<int, DTEjercicio*>* ejercicio6 = new pair<int, DTEjercicio*>(ejercicios->find(2)->first, ejercicios->find(2)->second);
        cu->recordarEjercicio(ejercicio6);
        cu->mostrarEjercicioaux();
        map<int, string>* resu4 = new map<int, string>;
        resu4->insert(pair<int, string>(1, "have"));
        resu4->insert(pair<int, string>(2, "past"));
        cu->resolverCompletarPalabra(resu4);
       
        cu->IngresarCursoSeleccionado("Curso avanzado de ingles");
        cu->FinalizarInscripcionACurso("jpidiom",f3);
        
        cu->recordarUsuario("marsilva");
        cu->IngresarCursoSeleccionado("Ingles para principiantes");
        ejercicios = cu->obtenerEjerciciosNoAprobados();
        ejercicio1 = new pair<int, DTEjercicio*>(ejercicios->find(1)->first, ejercicios->find(1)->second);
        cu->recordarEjercicio(ejercicio1);
        cu->mostrarEjercicioaux();
        cu->resolverTraducir("Nice to meet you");

        cu->recordarUsuario("marsilva");
        cu->IngresarCursoSeleccionado("Ingles para principiantes");
        ejercicios = cu->obtenerEjerciciosNoAprobados();
        ejercicio2 = new pair<int, DTEjercicio*>(ejercicios->find(2)->first, ejercicios->find(2)->second);
        cu->recordarEjercicio(ejercicio2);
        cu->mostrarEjercicioaux();
        resu1 = new map<int, string>;
        resu1->insert(pair<int, string>(1, "allow"));
        resu1->insert(pair<int, string>(2,"myself"));
        cu->resolverCompletarPalabra(resu1);

        cu->recordarUsuario("pero12");
        cu->IngresarCursoSeleccionado("Ingles para principiantes");
        ejercicios = cu->obtenerEjerciciosNoAprobados();
        ejercicio1 = new pair<int, DTEjercicio*>(ejercicios->find(1)->first, ejercicios->find(1)->second);
        cu->recordarEjercicio(ejercicio1);
        cu->mostrarEjercicioaux();
        cu->resolverTraducir("Nice to meet you");

        cu->recordarUsuario("pero12");
        cu->IngresarCursoSeleccionado("Ingles para principiantes");
        ejercicios = cu->obtenerEjerciciosNoAprobados();
        ejercicio2 = new pair<int, DTEjercicio*>(ejercicios->find(2)->first, ejercicios->find(2)->second);
        cu->recordarEjercicio(ejercicio2);
        cu->mostrarEjercicioaux();
        resu1 = new map<int, string>;
        resu1->insert(pair<int, string>(1, "allow"));
        resu1->insert(pair<int, string>(2,"myself"));
        cu->resolverCompletarPalabra(resu1);

        cu->recordarUsuario("pero12");
        cu->IngresarCursoSeleccionado("Ingles para principiantes");
        ejercicios = cu->obtenerEjerciciosNoAprobados();
        ejercicio4 = new pair<int, DTEjercicio*>(ejercicios->find(2)->first, ejercicios->find(2)->second);
        cu->recordarEjercicio(ejercicio4);
        cu->mostrarEjercicioaux();
        resu2 = new map<int, string>;
        resu2->insert(pair<int, string>(1, "some"));
        cu->resolverCompletarPalabra(resu2);

        
};  

void ejecutarAltaUsuario(){
    Fabrica* f = Fabrica::getInstancia();

    IUsuario* ctrUsuario = f->getIUsuario();
    string nuevoUsarioNickname;
    string nuevoUsuariocontrasenia;
    string nuevoUsuarioDescripcion;
    string nuevoUsuarioNombre;
    string tipoDeUsuario;
    string nuevoUsuarioPaisDeResidencia;
    string nuevoUsuarioFechaDeNacimientoDia;
    string nuevoUsuarioFechaDeNacimientoMes;
    string nuevoUsuarioFechaDeNacimientoAnio;
    string nuevoUsuarioIdiomaEspecializacion;
    string nuevoUsuarioInstituto;
    set<string> * idiomasDisponibles;
    string seguirAgregandoIdiomasOpcion;
    bool usuarioCreadoExitosamente;

    cout << "Ingrese el nickname del nuevo usuario(Esto se usara para identificar a el usuario en el sistema): ";
    getline(cin, nuevoUsarioNickname);
    while(ctrUsuario->NicknameDisponible(nuevoUsarioNickname)){
        cout << "Ese nombre no esta disponible, ingrese otro: ";
        getline(cin, nuevoUsarioNickname);
    }
    
    cout << "Ingrese la contasenia del nuevo usuario: ";
    getline(cin, nuevoUsuariocontrasenia);
    while(nuevoUsuariocontrasenia.length() < 6){
        cout << "La contrasenia debe de ser de largo 6 o mas, ingrese una nueva: ";
        getline(cin, nuevoUsuariocontrasenia);
    }
    
    cout << "Ingrese la descripcion del nuevo usuario: ";
    getline(cin, nuevoUsuarioDescripcion);
    while(nuevoUsuarioDescripcion.empty()){
        cout << "La descripcion no puede ser vacia, ingrese una nuevamente: ";
        getline(cin, nuevoUsuarioDescripcion);

    }
    
    cout << "Ingrese el nombre del nuevo usuario: ";
    getline(cin, nuevoUsuarioNombre);
    while(nuevoUsuarioNombre.empty()){
        cout << "El nombre no puede ser vacio, ingrese uno nuevamente: ";
        getline(cin, nuevoUsuarioNombre);
    }

    ctrUsuario->IngresarDatosUsuario(nuevoUsarioNickname,nuevoUsuariocontrasenia,nuevoUsuarioDescripcion,nuevoUsuarioNombre);
    cout << "Eres profesor o estudiante?(P/E) ";
    getline(cin, tipoDeUsuario);
    while ( tipoDeUsuario != "p" && tipoDeUsuario != "e" && tipoDeUsuario != "P" && tipoDeUsuario != "E"){
        cout << "Opcion Invalida,ingrese nuevamente: ";
        getline(cin, tipoDeUsuario);
    }
    if (tipoDeUsuario == "p" || tipoDeUsuario == "P"){
        idiomasDisponibles = ctrUsuario->ObtenerIdiomasDisponibles();
        bool seguirAgregandoIdiomas = false;
        while(!seguirAgregandoIdiomas){
            int i = 1;
            cout << "---IDIOMAS DISPONIBLES---\n";
            for (set<string>::iterator it = idiomasDisponibles->begin(); it != idiomasDisponibles->end(); ++it){
                cout << to_string(i) << " " << *it << "\n";
                i++;
            }
            cout << "Ingrese el NOMBRE del idioma en el que se especiliza: ";
            getline(cin, nuevoUsuarioIdiomaEspecializacion);
            if(idiomasDisponibles->find(nuevoUsuarioIdiomaEspecializacion) == idiomasDisponibles->end()){
                cout << "El idioma ingresado no es valido.\n";
            }
            else{
                ctrUsuario->AgregarEspecializacion(nuevoUsuarioIdiomaEspecializacion);
            }
            cout << "Quiere agregar otro idioma?(Y/N)";
            getline(cin, seguirAgregandoIdiomasOpcion);
            if (seguirAgregandoIdiomasOpcion != "y" && seguirAgregandoIdiomasOpcion != "Y"){
                seguirAgregandoIdiomas = true;
            }
        }
        cout << "Ingrese el instituto donde trabaja: ";
        getline(cin, nuevoUsuarioInstituto);
        while(nuevoUsuarioInstituto.empty()){
            cout << "El instituto no puede ser vacio, ingrese uno nuevamente: ";
            getline(cin, nuevoUsuarioInstituto);
        }
        ctrUsuario->IngresarInstituto(nuevoUsuarioInstituto);
        ctrUsuario->AltaProfesor();
        usuarioCreadoExitosamente = ctrUsuario->ConfirmarAltaProfesor();

    }
    else{
        cout << "Ingrese el pais de residencia del estudiante: ";
        getline(cin, nuevoUsuarioPaisDeResidencia);
        while(nuevoUsuarioPaisDeResidencia.empty()){
            cout << "El pais de residencia no puede ser vacio, ingrese uno nuevamente: ";
            getline(cin, nuevoUsuarioPaisDeResidencia);
        }
        cout << "Ingrese fecha de nacimiento del estudiante(Dia-Mes-Anio).\n";
        cout << "Dia: ";
        getline(cin, nuevoUsuarioFechaDeNacimientoDia);
        cout << "Mes: ";
        getline(cin, nuevoUsuarioFechaDeNacimientoMes);
        cout << "Anio: ";
        getline(cin, nuevoUsuarioFechaDeNacimientoAnio);
        DTFecha* fechaNacimiento = transformarStringTofecha(nuevoUsuarioFechaDeNacimientoDia,nuevoUsuarioFechaDeNacimientoMes,nuevoUsuarioFechaDeNacimientoAnio);
        ctrUsuario->IngresarDatoEstudiante(nuevoUsuarioPaisDeResidencia,fechaNacimiento);
        ctrUsuario->AltaEstudiante();
        usuarioCreadoExitosamente = ctrUsuario->ConfirmarAltaEstudiante();
    }

    if(usuarioCreadoExitosamente){
        cout << "Usuario creado con exito.\n ";
    }
    else{
        cout << "Hubo un error al crear el usuario.\n ";
    }
}

void  ejecutarAltaDeIdioma(){
    //llamar al caso de uso Alta de idioma
    cout << "Ingrese el nombre del nuevo Idioma:\n";
    string nombreIdioma;
    getline(cin,nombreIdioma);
    while(nombreIdioma.empty()){
        cout << "El nombre del idioma no puede ser vacio, ingrese uno nuevamente: ";
        getline(cin, nombreIdioma);
    }
    Fabrica* f = Fabrica::getInstancia();
    ICurso* cc = f->getICurso();
    cc->IngresarIdioma(nombreIdioma);
    bool ex = cc->ConfirmarIdioma();
    if (ex){
        cout << "El idioma "<<nombreIdioma<<" se ha dado de alta correctamente\n";
    }
    else{
        cout << "El idioma "<<nombreIdioma<<" ya existe \n";
    }
}

void ejecutarConsultarIdioma(){
    //llamar al caso de uso Consultar idioma
     //llamar al caso de uso Consultar idioma
    Fabrica* f = Fabrica::getInstancia();
    ICurso* cc = f->getICurso();
    set<string>* id = cc->ConsultarIdioma();
    if(id == NULL || id->size() == 0){
        cout << "No hay idiomas cargados en el sistema. \n";
    }
    else{
        cout << "Los idiomas actualmente disponibles son: \n";
        for (set<string>::iterator it = id->begin();it != id->end();it++){
        cout << *it << "\n";
    }
    }   
    
    
}

void ejecutarAltaDeCurso(){ 
    /*Se cargan todos los datos de pruebas que brinda.*/
    string nickname, nombreCurso, descCurso, dificultad, nomIdioma, previas;
    Fabrica* f = Fabrica::getInstancia();
    ICurso* ctrCurso = f->getICurso();
    set<string>* nombres = ctrCurso->obtenerNickname();
    if (nombres == NULL){
        cout << "No hay profesores registrados en el sistema\n";    
    }else{
        cout << "--- Profesores registrados ---\n";
        for (set<string>::iterator it = nombres->begin(); it != nombres->end(); it++)
            cout << *it << "\n";
        cout << "Ingrese el nickname del profesor a seleccionar\n";
        bool profValido = false;
        while (!profValido){
            getline(cin, nickname);
            if (nombres->find(nickname) == nombres->end()){
                cout << "Debe ingresar un nickname valido: ";
            }else{
                profValido = true;
            };
        };
        ctrCurso->seleccionarProfesor(nickname);
        cout << "Ingrese los datos del curso\n";
        cout << "Nombre:\n";
        getline(cin, nombreCurso);
        while(nombreCurso.empty()){
            cout << "El nombre del curso no puede ser vacio, ingrese uno nuevamente: ";
            getline(cin, nombreCurso);
        }
        //TODO:
        while(ctrCurso->ExisteCurso(nombreCurso)){
            cout << "El nombre del curso ya esta en uso, ingrese otro: ";
            getline(cin, nombreCurso);
        }
        cout << "Descripcion:\n";
        getline(cin, descCurso);
        while(descCurso.empty()){
            cout << "La descripcion del curso no puede ser vacia, ingrese una nuevamente: ";
            getline(cin, descCurso);
        }
        cout << "Dificultad:\n";
        getline(cin, dificultad);
        while (dificultad != "Principiante" && dificultad != "Intermedio" && dificultad != "Avanzado"){
            cout << "Debe ingresar una dificultad valida\n";
            getline(cin, dificultad);
        };
        Nivel lvl;
        if (dificultad == "Principiante")
            lvl = Principiante;
        else if (dificultad == "Intermedio")
            lvl = Intermedio;
        else
            lvl = Avanzado;
        ctrCurso->ingresarDatosCurso(nombreCurso, descCurso, lvl);
        set<string>* idiomas = ctrCurso->obtenerIdiomasEspecializacion();
        if (idiomas == NULL)
            cout << "Este profesor no tiene idiomas registrados\n";
        else {
            cout << "---IDIOMAS--- \n";
            for (set<string>::iterator it = idiomas->begin(); it != idiomas->end(); it++)
                cout << *it << "\n";
            cout << "Ingrese un idioma de la lista: ";
            bool idiomaVal = false;
            while(!idiomaVal){
                getline(cin, nomIdioma);
                if (idiomas->find(nomIdioma) == idiomas->end())
                    cout << "Debe ingresar un idioma valido \n";
                else
                    idiomaVal = true;
            };
            ctrCurso->seleccionarIdioma(nomIdioma);
            cout << "El curso requiere previas? Responda con si o no\n";  
            getline(cin, previas);
            if (previas == "si"){
                ctrCurso->necesitaPrevia(true);
                set<DTCurso*>* cursosHab = ctrCurso->obtenerCursosHabilitados();
                if (cursosHab == NULL)
                    cout << "No hay cursos habilitados para este idioma\n";
                else{
                    cout << "Los cursos habilitados para dicho idioma son: \n";
                    for (set<DTCurso*>::iterator it = cursosHab->begin(); it != cursosHab->end(); it++)
                        cout << (*it)->getNombre() << ". Descripcion: " << (*it)->getDesc() << "\n";
                    cout << "Seleccione los cursos que desea de la lista, e ingrese listo al finalizar\n";
                    string cursoSel = "";
                    set<string>* nomCursosSel = new set<string>;
                    while (cursoSel != "listo"){
                        getline(cin, cursoSel);
                        if (cursoSel != "listo")
                            nomCursosSel->insert(cursoSel);
                    };
                    ctrCurso->seleccionarPrevias(nomCursosSel);
                };
            }else{
                ctrCurso->necesitaPrevia(false);
            };
            cout << "Desea agregar lecciones? \n";
            string reqLecciones, descLeccion, nombreLec, lecListo;
            getline(cin, reqLecciones);
            if (reqLecciones == "si"){
                string nombreLec, descLeccion;
                while (lecListo != "no"){
                    cout << "Ingresar tema de la leccion: ";
                    getline(cin, nombreLec);
                    while(nombreLec.empty()){
                        cout << "El tema de la leccion no puede ser vacio, ingrese uno nuevamente: ";
                        getline(cin, nombreLec);
                    }
                    cout << "Ingresar descripcion de la leccion: ";
                    getline(cin, descLeccion);
                    while(descLeccion.empty()){
                        cout << "La descripcion de la leccion no puede ser vacia, ingrese una nuevamente: ";
                        getline(cin, descLeccion);
                    }
                    cout << "Desea agregar ejercicios? Indique con si o no\n";
                    ctrCurso->crearLeccion(nombreLec, descLeccion);
                    string ejNuevo;
                    getline(cin, ejNuevo);
                    string tipoEjercicio, descEjercicio, tiraCompletar, solucionCP, fraseATraducir, fraseTraducida;
                    if(ejNuevo == "si"){
                        while (ejNuevo != "no"){
                            cout << "Ingresar tipo de ejercicio(Completar Palabra/Traducir)\n";
                            getline(cin, tipoEjercicio);
                            while(tipoEjercicio != "Completar Palabra" && tipoEjercicio != "Traducir"){
                                cout << "El tipo de ejercicio ingresado no es valido, ingrese uno nuevamente: ";
                                getline(cin, tipoEjercicio);
                            }
                            cout << "Ingresar descripcion del ejercicio\n";
                            getline(cin, descEjercicio);
                                string solucionCPAux = "";
                            if (tipoEjercicio == "Completar Palabra"){
                                cout << "Ingrese la frase a completar\n";
                                getline(cin, tiraCompletar);
                                while(tiraCompletar.empty()){
                                    cout << "La frase a completar no puede ser vacia, ingrese una nuevamente: ";
                                    getline(cin, tiraCompletar);
                                }
                                
                                cout << "Ingrese la solucion del ejercicio\n";
                                getline(cin, solucionCP);
                                while(solucionCP.empty()){
                                    cout << "La solucion del ejercicio no puede ser vacia, ingrese una nuevamente: ";
                                    getline(cin, solucionCP);
                                }
                                map<int, string>* solucionSetCP = stringToMap(solucionCP);
                                ctrCurso->crearEjercicioCompletarPalabra(descEjercicio, tiraCompletar, solucionSetCP);
                            }else{
                                cout << "Ingrese la frase a traducir\n";
                                getline(cin, fraseATraducir);
                                while(fraseATraducir.empty()){
                                    cout << "La frase a traducir no puede ser vacia, ingrese una nuevamente: ";
                                    getline(cin, fraseATraducir);
                                }

                                cout << "Ingrese la frase traducida\n";
                                getline(cin, fraseTraducida);
                                while(fraseTraducida.empty()){
                                    cout << "La frase traducida no puede ser vacia, ingrese una nuevamente: ";
                                    getline(cin, fraseTraducida);
                                }
                                ctrCurso->crearEjercicioTraducir(descEjercicio, fraseATraducir, fraseTraducida); 
                            };
                            cout << "Desea continuar agregando ejercicios? Ingrese si o no\n";
                            getline(cin, ejNuevo);
                        };
                    };
                    cout << "Desea continuar agregando lecciones? Ingrese si o no\n";
                    getline(cin, lecListo);
                };  
            };
        ctrCurso->ConfirmarAltaCurso(); 
        cout << "--- El curso fue creado con exito ---\n";
        };
    };
};

void ejecutarAgregarLeccion(){
    string cursoSel, nombreLec, descLeccion;
    Fabrica* f = Fabrica::getInstancia();
    ICurso* instanciaCtrCurso = f->getICurso();
    set<DTCurso*>* cursosNoHab = instanciaCtrCurso->ObtenerCursosNoHabilitados();
    if (cursosNoHab == NULL)
        cout << "No existen cursos no habilitados\n";
    else{
        cout << "--- Cursos no habilitados ---\n";
        for (set<DTCurso*>::iterator it = cursosNoHab->begin(); it != cursosNoHab->end(); it++)
            cout << (*it)->getNombre() << "\n";
        
        cout << "Seleccione un curso \n";
        getline(cin, cursoSel);
        /*while(cursosNoHab->find(cursoSel) == cursosNoHab->end()){
            cout << "El curso ingresado no es valido, ingrese uno nuevamente: ";
            getline(cin, cursoSel);
        }*/
        instanciaCtrCurso->seleccionarCurso(cursoSel);
        
        cout << "Ingresar el tema de la leccion\n";
        getline(cin, nombreLec);
        while(nombreLec.empty()){
            cout << "El tema de la leccion no puede ser vacio, ingrese uno nuevamente: ";
            getline(cin, nombreLec);
        }

        cout << "Ingresar descripcion de la leccion\n";
        getline(cin, descLeccion);
        while(descLeccion.empty()){
            cout << "La descripcion de la leccion no puede ser vacia, ingrese una nuevamente: ";
            getline(cin, descLeccion);
        }
        cout << "Desea agregar ejercicios? Indique con si o no\n";
        instanciaCtrCurso->crearLeccion(nombreLec, descLeccion);
        string ejNuevo;
        getline(cin, ejNuevo);
        string tipoEjercicio, descEjercicio, tiraCompletar, solucionCP, fraseATraducir, fraseTraducida;
        if(ejNuevo == "si"){
            while (ejNuevo != "no"){
                cout << "Ingresar tipo de ejercicio(Completar Palabra/Traducir)\n";
                getline(cin, tipoEjercicio);
                cout << "Ingresar descripcion del ejercicio\n";
                getline(cin, descEjercicio);
                    string solucionCPAux = "";
                if (tipoEjercicio == "Completar Palabra"){
                    
                    cout << "Ingrese la frase a completar\n";
                    getline(cin, tiraCompletar);
                    while(tiraCompletar.empty()){
                        cout << "La frase a completar no puede ser vacia, ingrese una nuevamente: ";
                        getline(cin, tiraCompletar);
                    }

                    cout << "Ingrese la solucion del ejercicio\n";
                    getline(cin, solucionCP);
                    while(solucionCP.empty()){
                        cout << "La solucion del ejercicio no puede ser vacia, ingrese una nuevamente: ";
                        getline(cin, solucionCP);
                    }

                    map<int, string>* solucionSetCP = stringToMap(solucionCP);
                    instanciaCtrCurso->crearEjercicioCompletarPalabra(descEjercicio, tiraCompletar, solucionSetCP);
                }else{
                    cout << "Ingrese la frase a traducir\n";
                    getline(cin, fraseATraducir);
                    while(fraseATraducir.empty()){
                        cout << "La frase a traducir no puede ser vacia, ingrese una nuevamente: ";
                        getline(cin, fraseATraducir);
                    }
                    
                    cout << "Ingrese la frase traducida\n";
                    getline(cin, fraseTraducida);
                    while(fraseTraducida.empty()){
                        cout << "La frase traducida no puede ser vacia, ingrese una nuevamente: ";
                        getline(cin, fraseTraducida);
                    }
                    instanciaCtrCurso->crearEjercicioTraducir(descEjercicio, fraseATraducir, fraseTraducida); 
                };
                cout << "Desea continuar agregando ejercicios? Ingrese si o no\n";
                getline(cin, ejNuevo);
            };
        };
        instanciaCtrCurso->DarDeAltaLeccion();
    };
};

void ejecutarAgregarEjercicio(){
    string cursoSel, descLeccion;
    Fabrica* f = Fabrica::getInstancia();
    ICurso* instanciaCtrCurso = f->getICurso();
    set<DTCurso*>* cursosNoHab = instanciaCtrCurso->ObtenerCursosNoHabilitados();
    if (cursosNoHab == NULL)
        cout << "No existen cursos no habilitados\n";
    else{
        cout << "--- Cursos no habilitados ---\n";
        for (set<DTCurso*>::iterator it = cursosNoHab->begin(); it != cursosNoHab->end(); it++)
            cout << (*it)->getNombre() << "\n";
        cout << "Seleccione un curso: ";
        getline(cin, cursoSel);
        while(cursoSel.empty()){
            cout << "El nombre del curso no puede ser vacio, ingrese uno nuevamente: ";
            getline(cin, cursoSel);
        };
        /*while(cursosNoHab->find(cursoSel) == cursosNoHab->end()){
            cout << "El curso ingresado no es valido, ingrese uno nuevamente: ";
            getline(cin, cursoSel);
        }*/

        instanciaCtrCurso->seleccionarCurso(cursoSel);
        set<DTLeccion*>* lecciones = instanciaCtrCurso->obtenerLecciones();
        if(lecciones == NULL || lecciones->size() == 0){
            cout << "El curso no tiene lecciones creadas.\n";
        }
        else{
            for (set<DTLeccion*>::iterator it = lecciones->begin(); it != lecciones->end(); it++)
                cout << (*it)->getOrden() <<") "<< (*it)->getTema() <<"\n";
        cout << "Seleccione una leccion ingresando su numero identificador\n";
        string numIngresado;
        getline(cin, numIngresado);
        int indiceLec = stoi(numIngresado);
        string tipoEjercicio, descEjercicio, tiraCompletar, solucionCP, fraseATraducir, fraseTraducida;
        
        cout << "Ingresar tipo de ejercicio(Completar Palabra/Traducir)\n";
        getline(cin, tipoEjercicio);
        while(tipoEjercicio != "Completar Palabra" && tipoEjercicio != "Traducir"){
            cout << "El tipo de ejercicio ingresado no es valido, ingrese uno nuevamente: ";
            getline(cin, tipoEjercicio);
        }
        cout << "Ingresar descripcion del ejercicio\n";
        getline(cin, descEjercicio);
        string solucionCPAux = "";
        if (tipoEjercicio == "Completar Palabra"){
            cout << "Ingrese la frase a completar\n";
            getline(cin, tiraCompletar);
            while(tiraCompletar.empty()){
                cout << "La frase a completar no puede ser vacia, ingrese una nuevamente: ";
                getline(cin, tiraCompletar);
            }
            cout << "Ingrese la solucion del ejercicio\n";
            getline(cin, solucionCP);
            while(solucionCP.empty()){
                cout << "La solucion del ejercicio no puede ser vacia, ingrese una nuevamente: ";
                getline(cin, solucionCP);
            }
            map<int, string>* solucionSetCP = stringToMap(solucionCP);
            instanciaCtrCurso->agregarEjercicio(indiceLec, descEjercicio, tiraCompletar, solucionSetCP);
        }else{
            cout << "Ingrese la frase a traducir\n";
            getline(cin, fraseATraducir);
            while(fraseATraducir.empty()){
                cout << "La frase a traducir no puede ser vacia, ingrese una nuevamente: ";
                getline(cin, fraseATraducir);
            }

            cout << "Ingrese la frase traducida\n";
            getline(cin, fraseTraducida);
            while(fraseTraducida.empty()){
                cout << "La frase traducida no puede ser vacia, ingrese una nuevamente: ";
                getline(cin, fraseTraducida);
            }
            instanciaCtrCurso->agregarEjercicio(indiceLec, descEjercicio, fraseATraducir, fraseTraducida);
            cout << "--- El ejercicio fue agregado exitosamente ---\n";
        };
        }
    };
};  

void ejecutarHabilitarCurso(){
    string cursoSel;
    Fabrica* f = Fabrica::getInstancia();
    ICurso* instanciaCtrCurso = f->getICurso();
    set<DTCurso*>* cursosNoHab = instanciaCtrCurso->ObtenerCursosNoHabilitados();
    if (cursosNoHab == NULL)
        cout << "No existen cursos no habilitados\n";
    else{
        cout << "--- Cursos no habilitados ---\n";
        for (set<DTCurso*>::iterator it = cursosNoHab->begin(); it != cursosNoHab->end(); it++)
            cout << (*it)->getNombre() << "\n";
        cout << "Seleccione un curso \n";
        getline(cin, cursoSel);
        /*while(cursosNoHab->find(cursoSel) == cursosNoHab->end()){
            cout << "El curso ingresado no es valido, ingrese uno nuevamente: ";
            getline(cin, cursoSel);
        }*/
        instanciaCtrCurso->seleccionarCurso(cursoSel);
        bool exito = instanciaCtrCurso->habilitarCurso();
        if (exito){
            cout << "---El curso seleccionado fue habiltiado con exito ---\n";
        } else {
            cout << "--- El curso no cumple las condiciones para ser habilitado --- \n";
        };
    };
};


void ejecutarEliminarCurso(){
    Fabrica* f = Fabrica::getInstancia();
    ICurso* ctrCurso = f->getICurso();
    set<DTCurso*>* cursos = ctrCurso->obtenerCursos();

    if (cursos->size() != 0){
        string cursoAEliminar;

        cout << "Cursos disponibles para eliminar: \n";
        for (set<DTCurso*>::iterator it = cursos->begin(); it != cursos->end(); it++){
            cout << (*it)->getNombre() << endl;
        }

        cout << "\nEscriba el nombre del curso que quiere eliminar: ";
        getline(cin, cursoAEliminar);

        while (!ctrCurso->ExisteCurso(cursoAEliminar)){
            cout<<"Ingrese un nombre de curso correcto\n" <<endl;
            cout << "Escriba el nombre del curso que quiere eliminar: ";
            getline(cin, cursoAEliminar);
        }
        
        ctrCurso->seleccionarCurso(cursoAEliminar);
        ctrCurso->eliminarCurso();
        cout << "Curso eliminado con exito. \n";
    }
    else {
        cout << "No hay cursos para eliminar. \n";
    }   
}

void ejecutarConsultarCurso(){
    Fabrica* f = Fabrica::getInstancia();
    ICurso* ctrCurso = f->getICurso();
    set<DTCurso*>* cursos = ctrCurso->obtenerCursos();

    if (cursos->size() != 0){
        string cursoAConsultar;

        cout << "\nCursos disponibles para consultar: \n";
        for (set<DTCurso*>::iterator it = cursos->begin(); it != cursos->end(); it++){
            cout << (*it)->getNombre() << endl;
        }

        cout << "\nEscriba el nombre del curso que quiere consultar: ";
        getline(cin, cursoAConsultar);

        while (!ctrCurso->ExisteCurso(cursoAConsultar)){
            cout<<"No se encuentra ese curso en el sistema. Por favor, vuelva a ingresar un curso a consultar: ";
            getline(cin, cursoAConsultar);
        }
        
        DTCurso* curso = ctrCurso->obtenerCurso(cursoAConsultar);
        ctrCurso->seleccionarCurso(cursoAConsultar);

        cout<<"Informacion general del curso \n"<<endl;

        cout << "Nombre: " + curso->getNombre() << endl;

        cout << "Descripcion: " + curso->getDesc() << endl;

        cout << "Dificultad: " + curso->getDificultad() << endl;

        cout << "Idioma: " + curso->getNombreIdiomaCurso() << endl;

        cout << "Profesor: " + curso->getNombreProfesor() << endl;

        if (curso->getHabilitado()){
            cout << "Estado del curso: Habilitado \n" << endl;
        } else {
            cout << "Estado del curso: Deshabilitado \n" << endl;
        }

        if (curso->getcantLecciones() > 0) {
            map<int, DTLeccion*>* leccionesDeCurso = ctrCurso->obtenerLeccionesDeCurso();
            
            int i = 1;
            for(map<int, DTLeccion*>::iterator it = leccionesDeCurso->begin(); it != leccionesDeCurso->end(); it++){
                cout << "Leccion " << to_string(i) << ")" << endl;
                cout << "Tema: " + it->second->getTema() << endl;
                cout << "Objetivo: " + it->second->getObjetivo() + "\n" << endl;

                map<int, DTEjercicio*>* ejercicios = ctrCurso->obtenerEjercicios(it->second->getOrden());

                if (ejercicios->size() != 0){
                    cout<<"Ejercicios de la leccion"<<endl;

                    for(map<int, DTEjercicio*>::iterator ej = ejercicios->begin(); ej != ejercicios->end(); ej++){
                        cout << "- Tema: " + ej->second->getDescripcion()<< endl;
                    }
                }
                i++;
            }
        }        

        if (curso->getCantInscriptos() > 0) {
            cout<<"\nInscriptos al curso:"<<endl;
            map<string, DTEstudiante*>* estudiantes = curso->getEstudiantesInscriptos();
            for(map<string, DTEstudiante*>::iterator it = estudiantes->begin(); it != estudiantes->end(); it++){
                cout << "- " + it->second->getNombre() << ". ";

                DTFecha* fechaDeInscripcion = it->second->getInscripcionACurso(curso->getNombre())->getFechaDeInscripcion();
                cout << "Fecha de inscripcion: "  << fechaDeInscripcion->getDia() << "/" << fechaDeInscripcion->getMes() << "/" << fechaDeInscripcion->getAno() << endl;
            }
        }        
    }
    else {
        cout << "No hay cursos en el sistema. \n";
    }  
}

void ejecutarInscribirseCurso(){
    string nickname;
    string nombreDelCurso;
    Fabrica* f = Fabrica::getInstancia();
    IUsuario* ctrUsuario = f->getIUsuario();
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nickname);
    if(ctrUsuario->NicknameDisponible(nickname)){
        set<DTCurso*> cursosHabilitados = ctrUsuario->ObtenerCursosHabilitadosParaInscripcion(nickname);
        if (cursosHabilitados.empty()){
            cout << "El estudiante no tiene cursos habilitados disponibles\n";
        }
        else{
            int i = 1;
            cout << "---CURSO DISPONIBLES---\n";
            for (set<DTCurso*>::iterator it = cursosHabilitados.begin(); it != cursosHabilitados.end(); ++it){
                cout << to_string(i) << ") Curso: " << (*it)->getNombre() << endl;
                cout << "- Descripcion: " << (*it)->getDesc() << endl;
                cout << "- Cantidad de Lecciones: " << (*it)->getcantLecciones() << endl;
                cout << "- Cantidad de ejercicios: " << (*it)->getcantEjercicios() << endl;
                cout << "\n";
                i++;
            }
            
            cout << "Escriba el nombre del curso: \n";
            getline(cin, nombreDelCurso);
            /*while(cursosHabilitados->find(nombreDelCurso) == cursosHabilitados->end()){
                cout << "El curso ingresado no es valido, ingrese uno nuevamente: ";
                getline(cin, nombreDelCurso);
            }*/
            ctrUsuario->IngresarCursoSeleccionado(nombreDelCurso);
            DTFecha * f = NULL;
            bool inscripcionCorrecta = ctrUsuario->FinalizarInscripcionACurso(nickname, f);
            if(inscripcionCorrecta){
                cout << "Se realizo correctamente la inscripcion.\n";
            }
            else{
                cout << "Surgio un problema durante la inscripcion pruebe nuevamente.\n";
            } 
        }
    }
    else{
        cout << "No existe un estudiante con ese nombre.\n";
    }
    

}

void ejecutarRealizarEjercicio(){
    Fabrica* f = Fabrica::getInstancia();
    IUsuario* ctrUsuario = f->getIUsuario();
    set<string>* usuarios = ctrUsuario->ObtenerNicknameUsuarios();
    ICurso* ctrCurso = f->getICurso();

    if (usuarios->size() != 0){
        string nickname;
        cout << "Ingrese su nickname: ";
        getline(cin, nickname);

        while (!ctrUsuario->existeUsuario(nickname)){
            cout<<"Ese nickname no existe en el sistema, intente de nuevo: ";
            getline(cin, nickname);
        }
        ctrUsuario->recordarUsuario(nickname);

        map<string, DTCurso*>* cursos = ctrUsuario->obtenerCursosInscriptoNoAprobado();
        if (cursos->size() > 0){            
            cout<< "\nCursos disponibles para realizar ejercicios: "<<endl;
            for(map<string, DTCurso*>::iterator it = cursos->begin(); it != cursos->end(); it++){
                cout<< "- " + it->second->getNombre() << endl;
            }

            string cursoSeleccionado;
            cout << "\nIngrese el nombre del curso que quiere realizar un ejercicio: ";
            getline(cin, cursoSeleccionado);

            while (!ctrCurso->ExisteCurso(cursoSeleccionado)){
                cout<<"Ese curso no existe en el sistema, intente de nuevo: ";
                getline(cin, cursoSeleccionado);
            }
            ctrUsuario->IngresarCursoSeleccionado(cursoSeleccionado);

            cout<<"\nEjercicios disponibles:" << endl;
            map<int, DTEjercicio*>* ejercicios = ctrUsuario->obtenerEjerciciosNoAprobados();
            for(map<int, DTEjercicio*>::iterator it = ejercicios->begin(); it != ejercicios->end(); it++){
                cout<< it->first << ") " << it->second->getDescripcion() << endl;
            }

            cout<<"\nIngrese el numero del ejercicio que desea realizar: ";
            string ejercicioSeleccionadoRaw;
            getline(cin, ejercicioSeleccionadoRaw);
            int ejercicioSeleccionado = stoi(ejercicioSeleccionadoRaw);

            while (ejercicios->find(ejercicioSeleccionado) == ejercicios->end()){
                cout<<"No hay un ejercicio con ese numero asignado, vuelva a intentar: ";
                getline(cin, ejercicioSeleccionadoRaw);
                ejercicioSeleccionado = stoi(ejercicioSeleccionadoRaw);
            }

            pair<int, DTEjercicio*>* ejercicio = new pair<int, DTEjercicio*>(ejercicios->find(ejercicioSeleccionado)->first, ejercicios->find(ejercicioSeleccionado)->second);
            ctrUsuario->recordarEjercicio(ejercicio);
            bool esEjercicioDeTraducir = ctrUsuario->mostrarEjercicio();
            
            if(esEjercicioDeTraducir){
                cout<<"\nIngrese la traduccion: ";
                string traduccion;
                getline(cin, traduccion);
                ctrUsuario->resolverTraducir(traduccion,true);
            } else {
                cout<<"\nIngrese palabras faltantes" << endl;
                map<int, string>* completarPalabra = new map<int, string>;
                cout << ctrUsuario->cantidadPalabrasACompletar();
                for(int i = 1; i <= ctrUsuario->cantidadPalabrasACompletar(); i++){
                    cout<< "Palabra " << i << ": " ;
                    string palabra;
                    getline(cin, palabra);
                    completarPalabra->insert(pair<int, string>(i, palabra));
                    cout << endl;
                }
                
                ctrUsuario->resolverCompletarPalabra(completarPalabra,true);
            }
        } else {
            cout<< "No hay cursos sin aprobar dentro de sus inscripciones.\n"<<endl;
        }     
    }
    else {
        cout << "No hay usuarios registrados en el sistema. \n";
    }
}

void ejecutarConsultarEstadisticas(){

    //llamar al caso de uso Consultar estadisticas
    cout << "Seleccione que estadistica desea consultar: \n\n";
    cout << "1. Estadisticas de un estudiante\n";
    cout << "2. Estadisticas de un profesor\n";
    cout << "3. Estadisticas de un curso\n";
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    string eleccion;
    getline(cin,eleccion);
    CtrUsuario* ctrUsuario = CtrUsuario::getInstancia();
    bool valido = false;
    while (!valido){
      int el = stoi(eleccion);  
    switch (el){
        case 1:{
            Fabrica* f = Fabrica::getInstancia();
            ICurso* cc = f->getICurso();
            set<string>* estudiantes = cc->ObtenerEstudiantes();
             for (set<string>::iterator it = estudiantes->begin();it != estudiantes->end();it++){
                cout << *it << "\n";
                } 
            string elegido;
            if (estudiantes->begin()==estudiantes->end()){
                cout<<"No hay estudiantes en el sistema\n";
                valido = true;
            }
            else{
            cout << "Seleccione un estudiante:\n";
            bool correcto=false;
            while(!correcto){
                getline(cin,elegido);
                while(!ctrUsuario->NicknameDisponible(elegido)){
                    cout<<"Estudiante no válido, intente nuevamente\n";
                    getline(cin,elegido);
                }
                map<int,DTCurso*>* cursos = cc->obtenerCursosInscripto(elegido);
                if (cursos==NULL){
                    cout<<"Estudiante no válido, intente nuevamente\n";
                }
                else {
                    map<int,float>* avances= cc->obtenerAvanceCursos();
                    int i=1;
                    int f=1;
                    for (map<int,DTCurso*>::iterator it = cursos->begin(); it != cursos->end();it++){
                        cout<<"Curso: "<<(cursos->find(i)->second)->getNombre()<<" Avance: "<<(avances->find(f)->second)*100<<"\n";
                        i++;
                        f++;
                    }
                    correcto=true;
                    valido=true;
                }
            }
            }
            break;
        }
        case 2:{
            Fabrica* f = Fabrica::getInstancia();
            ICurso* cc = f->getICurso();
            set<string>* profesores = cc->ObtenerProfesores();
             for (set<string>::iterator it = profesores->begin();it != profesores->end();it++){
                cout << *it << "\n";
                }
            if (profesores->begin()==profesores->end()){
                cout<<"No hay profesores en el sistema\n";
                valido = true;
            } 
            else{
            string elegido;
            cout << "Seleccione un profesor:\n";
            bool correcto=false;
            while(!correcto){
                getline(cin,elegido);
                while(!ctrUsuario->NicknameDisponible(elegido)){
                    cout<<"Profesor no válido, intente nuevamente\n";
                    getline(cin,elegido);
                }
                map<int,DTCurso*>* cursos = cc->obtenerCursosInscripto(elegido);
                if (cursos==NULL){
                    cout<<"Profesor no válido, intente nuevamente\n";
                }
                else {
                    map<int,float>* avances= cc->obtenerPromedioCursos();
                    int f=1;
                    int i=1;
                    for (map<int,DTCurso*>::iterator it = cursos->begin(); it != cursos->end();it++){
                        cout<<"Curso: "<<(cursos->find(i)->second)->getNombre()<<" Promedio: "<<(avances->find(f)->second)*100<<"\n";
                        f++;
                        i++;
                    }
                    correcto=true;
                    valido=true;
                }
            }
            }
            break;
        }

        case 3:{
            Fabrica* f = Fabrica::getInstancia();
            ICurso* cc = f->getICurso();
            set<DTCurso*>* cursos = cc->obtenerCursos();
             for (set<DTCurso*>::iterator it = cursos->begin();it != cursos->end();it++){
                cout << (*it)->getNombre() << "\n";
                } 
            string elegido;
            if (cursos->begin()==cursos->end()){
                cout<<"No hay cursos en el sistema\n";
                valido = true;
            }
            else{
            cout << "Seleccione un curso:\n";
            bool correcto=false;
            while(!correcto){
                getline(cin,elegido);
                /*while(cursos->find(elegido) == cursos->end()){
                    cout<<"Curso no válido, intente nuevamente\n";
                    getline(cin,elegido);
                }*/
                if (!cc->ExisteCurso(elegido)){
                    cout<<"Curso no valido, intente nuevamente\n";
                }
                else {
                    cc->seleccionarCurso(elegido);
                    float avance= cc->obtenerPromedio();
                    cout <<"Curso: "<< elegido <<"  "<< "Promedio:   "<< avance*100<<"\n";
                    correcto=true;
                    valido=true;
                }
            }
            }
            break;
        }

        default:{
           cout<<"La opción no es válida, intente nuevamente\n";
           getline(cin,eleccion);
           break;
        }
    }
    }
}

void ejecutarSuscribirseNotificaciones(){
    //llamar al caso de uso Suscribirse a notificaciones
    string nickname;
    string idioma;
    cout<< "Ingrese nickname\n";
    getline(cin, nickname);
    Fabrica * f = Fabrica::getInstancia();
    IUsuario * u = f->getIUsuario();
    set<string>::iterator it;
    if (u->NicknameDisponible(nickname)){
        set<string> * idiomasNosuscrito = u->ObtenerIdiomaNoSuscripto(nickname);
        cout<<"Idiomas disponibles a los que no se ha suscrito\n";
        if (idiomasNosuscrito->size()!= 0){
            for(it = idiomasNosuscrito->begin(); it!=idiomasNosuscrito->end(); it++){
               cout<< *it <<endl;
            }
        }
        else {cout<< "Ya esta suscrito a todos los idiomas\n";}

        if(idiomasNosuscrito->size()!= 0){
            cout<< "ingrese idioma al que desea suscribirse o 1 si desea salir\n";
            getline(cin, idioma);
            while(idioma != "1" && idiomasNosuscrito->size()!= 0 ){
                while(!u->existeIdioma(idioma)){
                    cout<< "Idioma incorrecto, vuelva a ingresarlo\n";
                    getline(cin, idioma);
                }
                u->AgreagarSuscripcion(idioma);
                idiomasNosuscrito = u->ObtenerIdiomaNoSuscripto(nickname);
                cout<<"Idiomas disponibles a los que no se ha suscrito\n";
                if (idiomasNosuscrito->size()!= 0){
                    for(it = idiomasNosuscrito->begin(); it!=idiomasNosuscrito->end(); it++){
                        cout<< *it <<endl;
                    }
                }
                else {cout<< "Ya esta suscrito a todos los idiomas\n";}
                if (idiomasNosuscrito->size()!= 0){
                    cout<< "ingrese otro idioma si desea seguir suscribiendote o 1 si desa salir\n";
                    getline(cin, idioma);
                }
            }
        }   
    }
    else {
        cout<< "nickname incorrecto"<<endl;
    } 
}

void ejecutarConsultaNotificaciones(){
    //llamar al caso de uso Consulta de notificaciones
    string nickname;
    Fabrica * f = Fabrica::getInstancia();
    IUsuario * u = f->getIUsuario();
    cout<< "Ingrese nickname\n";
    getline(cin, nickname);
    if (u->NicknameDisponible(nickname)){
        u->IngresarNickname(nickname);
        set<DTNotificacion*> * n = u->obtenerNotificaciones();
        set<DTNotificacion*>::iterator it;
        if(n->size()==0){ cout <<"no hay notificaciones"<<endl;}
        else {
            for (it=n->begin(); it!=n->end(); it++){
                 cout<< "Nombre del curso: " + (*it)->getNombreCurso() + "--- Idioma: " + (*it)->getNombreIdioma() <<endl;
            }
        }
        if(n != NULL)
            u->EliminarNotifiaciones();
    }
    else cout<< "Nickname incorrecto"<<endl;

}

void ejecutarEliminarSuscripciones(){
    //llamar al caso de uso Eliminar suscripciones
    string nickname, idioma;
    Fabrica * f = Fabrica::getInstancia();
    IUsuario * u = f->getIUsuario();
    cout<<"Ingresar nickname\n";
    getline(cin, nickname);
    set<string> * sus;
    if(u->NicknameDisponible(nickname)) sus = u->obtenerSuscripciones(nickname);
    set<string>::iterator it_sus;
    if(u->NicknameDisponible(nickname)){
        if(sus->empty()){ cout <<"No está suscripto a ningun idioma"<<endl;}
        else {
            for (it_sus = sus->begin(); it_sus!=sus->end(); it_sus++){
                cout<< (*it_sus)<<endl;
            }
            set<string>*seleccionados =  new set<string>;
            cout<<"ingrese en diferentes lineas las suscripciones que deseas eliminar o digite 1 para salir y eliminar si selecciono algún idioma\n";
            getline(cin, idioma);
            while(idioma!="1" && u->existeIdioma(idioma)){
                seleccionados->insert(idioma);
                getline(cin, idioma);
            }    
            u->seleccionarSuscripciones(*seleccionados);
            if(seleccionados->size()!=0){
                u->eliminarSuscripciones();}
           
        }
    }   
    else cout<< "El nickname ingresado es incorrecto\n";
    

    
}

void ejecutarConsultaUsuario(){
    //llamar al caso de uso Consulta de usuario
    string nickN;
    Fabrica * f = Fabrica::getInstancia();
    IUsuario * u = f->getIUsuario();
    set<string> * nickname = u->ObtenerNicknameUsuarios();
    if (nickname->size()!=0){
        cout<<"Lista de Nickname\n";
        for (set<string>::iterator it = nickname->begin(); it != nickname->end(); it++)
            cout<< *it << endl;
        cout<<"Ingrese un nickname\n";
        getline(cin, nickN);
        while (!u->NicknameDisponible(nickN)){
            cout<<"Ingrese un nickname correcto"<<endl;
            getline(cin, nickN);
        }
        u->seleccionarUsuario(nickN);

    }
    else cout<< "No hay usuarios"<<endl;
}

void executeOption(int opcion){
    switch (opcion)
    {
    case 1:
        ejecutarCargarDatosPrueba();
        cout << "Datos cargados exitosamente\n";
        break;
    case 2:
        cout << "Alta de usuario\n";
        ejecutarAltaUsuario();
        break;
    case 3:
        cout << "Alta de idioma\n";
        ejecutarAltaDeIdioma();
        break;
    case 4:
        cout << "Consultar idiomas\n";
        ejecutarConsultarIdioma();
        break;
    case 5:
        cout << "Alta de curso\n";
        ejecutarAltaDeCurso();
        break;
    case 6:
        cout << "Agregar leccion\n";
        ejecutarAgregarLeccion();
        break;
    case 7:
        cout << "Agregar ejercicio\n";
        ejecutarAgregarEjercicio();
        break;
    case 8:
        cout << "Habilitar curso\n";
        ejecutarHabilitarCurso();
        break;
    case 9:
        cout << "Eliminar curso\n";
        ejecutarEliminarCurso();
        break;
    case 10:
        cout << "Consultar curso\n";
        ejecutarConsultarCurso();
        break;
    case 11:
        cout << "Inscribirse a curso\n";
        ejecutarInscribirseCurso();
        break;
    case 12:
        cout << "Realizar ejercicio\n";
        ejecutarRealizarEjercicio();
        break;
    case 13:
        cout << "Consultar estadísticas\n";
        ejecutarConsultarEstadisticas();
        break;
    case 14:
        cout << "Suscribirse a notificaciones\n";
        ejecutarSuscribirseNotificaciones();
        break;
    case 15:
        cout << "Consulta de notificaciones\n";
        ejecutarConsultaNotificaciones();
        break;
    case 16:
        cout << "Eliminar suscripciones\n";
        ejecutarEliminarSuscripciones();
        break;
    case 17:
        cout << "Consulta de usuario\n";
        ejecutarConsultaUsuario();
        break;
    case 18:
        cout << "Cerrando programa...\n";
        break;
    
    default:
        break;
    }

}
bool printMenu();

void checkOption(string opcion){
    try
    {
        int num = stoi(opcion);
        if(num <1 || num>18){
            cout << "La opcion seleccionada no es valida.Ingrese nuevamente\n";
            printMenu();
        }
        else{
            executeOption(num);
        }      
    }
    catch(...)
    {
        cout << "La opcion seleccionada no es valida.Ingrese nuevamente\n";
        printMenu();
    }
}

bool printMenu() {
    string opcion;

    cout << "-------------------------------------\n";
    cout << "Tarea 5 menu: \n";
    cout << "-------------------------------------\n";
    cout << "Elija uno de los siguiente caso de uso\n";
    cout << "1) Cargar datos de prueba \n";
    cout << "2) Alta de usuario \n";
    cout << "3) Alta de idioma \n";
    cout << "4) Consultar idiomas \n";
    cout << "5) Alta de curso \n";
    cout << "6) Agregar leccion \n";
    cout << "7) Agregar ejercicio \n";
    cout << "8) Habilitar curso \n";
    cout << "9) Eliminar curso \n";
    cout << "10) Consultar curso \n";
    cout << "11) Inscribirse a curso \n";
    cout << "12) Realizar ejercicio \n";
    cout << "13) Consultar estadisticas \n";
    cout << "14) Suscribirse a notificaciones \n";
    cout << "15) Consulta de notificaciones \n";
    cout << "16) Eliminar suscripciones \n";
    cout << "17) Consulta de usuario \n";
    cout << "18) Salir \n";

    
    getline(cin, opcion);
    checkOption(opcion);
    string seguirOperando;
    if (opcion != "18") {      
        cout << "Quiere seguir Operando? ";
        getline(cin, seguirOperando);
    }    
    return (seguirOperando != "no" && opcion != "18");
};
    
int main(){
  
    #pragma region Interfaz del usuario

    string salir;
    bool seguirOperando;
    seguirOperando = printMenu();
    while (seguirOperando){

        seguirOperando = printMenu();
    }
    cout << "Aprete cualquier letra para salir ";
    getline(cin, salir);//Esto es para que quede la consola abierta al final de todo.
  
    #pragma endregion

    return 0;
}; 

