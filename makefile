trabalho : main.o dominios.o  controladorasapresentacao.o stubs.o
	g++ -std=c++11 -lncurses -Wall -o trabalho main.o dominios.o controladorasapresentacao.o stubs.o
main.o : main.cpp interfaces.h controladorasapresentacao.h stubs.h
	g++ -c main.cpp
dominios.o : dominios.cpp dominios.h
	g++ -c dominios.cpp
controladorasapresentacao.o: controladorasapresentacao.cpp controladorasapresentacao.h dominios.h entidades.h interfaces.h
	g++ -c controladorasapresentacao.cpp
stubs.o : stubs.cpp stubs.h interfaces.h dominios.h
	g++ -c stubs.cpp

