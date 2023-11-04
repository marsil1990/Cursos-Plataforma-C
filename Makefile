all: main

.PHONY: all clean_bin 


# directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj


MODULOS = CompletarPalabra CtrCurso CtrUsuario Curso DTInscripcion DTCurso DTEstudiante DTEjercicio DTFecha DTNotificacion DTProfesor DTUsuario Ejercicio Estudiante Fabrica Idioma Inscripcion IUsuario Leccion ManejadorCurso ManejadorIdioma ManejadorUsuario Profesor Traducir Usuario DTLeccion

# lista de archivos, con directorio y extensión
HS   = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)

MAIN=main
EJECUTABLE=main

# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall -I$(HDIR) -DNDEBUG -g #-Werror se comenta esto para que no tome las warning como error

$(ODIR)/$(MAIN).o:$(MAIN).cpp
	$(CC) $(CCFLAGS) -c $< -o $@


$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@


$(EJECUTABLE): $(ODIR)/$(MAIN).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@   



clean_bin:
	rm -f $(EJECUTABLE) $(ODIR)/$(MAIN).o $(OS)   

clean:clean_bin
	@rm -f *~ $(HDIR)/*~ $(CPPDIR)/*~ 



