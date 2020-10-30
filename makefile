trabalho : main.o dominios.o  testes_entidades.o
	g++ -std=c++11 -Wall -o trabalho main.o dominios.o testes_entidades.o
main.o : main.cpp dominios.h entidades.h testes_entidades.h
	g++ -c main.cpp
dominios.o : dominios.cpp dominios.h
	g++ -c dominios.cpp
testes_entidades.o: testes_entidades.cpp testes_entidades.h entidades.h dominios.h
	g++ -c testes_entidades.cpp
