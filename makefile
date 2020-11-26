trabalho : main.o dominios.o  controladorasapresentacao.o stubs.o controladorasservico.o persistencia.o
	g++ -std=c++11 -lncurses -l sqlite3 -Wall -o trabalho main.o dominios.o controladorasapresentacao.o stubs.o controladorasservico.o persistencia.o
main.o : main.cpp interfaces.h controladorasapresentacao.h stubs.h controladorasservico.h
	g++ -c main.cpp
dominios.o : dominios.cpp dominios.h
	g++ -c dominios.cpp
controladorasapresentacao.o: controladorasapresentacao.cpp controladorasapresentacao.h dominios.h entidades.h interfaces.h
	g++ -c controladorasapresentacao.cpp
stubs.o : stubs.cpp stubs.h interfaces.h dominios.h
	g++ -c stubs.cpp
controladorasservico.o : controladorasservico.cpp controladorasservico.h interfaces.h dominios.h entidades.h persistencia.h
	g++ -c controladorasservico.cpp
persistencia.o: persistencia.cpp persistencia.h entidades.h dominios.h 
	g++ -c persistencia.cpp

