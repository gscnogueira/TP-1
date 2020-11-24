trabalho : main.o dominios.o  controladorasapresentacao.o
	g++ -std=c++11 -lncurses -Wall -o trabalho main.o dominios.o controladorasapresentacao.o
main.o : main.cpp interfaces.h controladorasapresentacao.h
	g++ -c main.cpp
dominios.o : dominios.cpp dominios.h
	g++ -c dominios.cpp
controladorasapresentacao.o: controladorasapresentacao.cpp controladorasapresentacao.h dominios.h entidades.h interfaces.h
	g++ -c controladorasapresentacao.cpp
