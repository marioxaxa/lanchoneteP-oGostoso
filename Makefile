

all: compilar linkar rodar
	echo "Programa finalizado."

compilar: main.cpp cardapio.cpp cliente.cpp gerente.cpp logo.cpp 
	g++ -c main.cpp cardapio.cpp cliente.cpp gerente.cpp logo.cpp

linkar: main.o cardapio.o cliente.o gerente.o logo.o
	g++ -o meuPrograma main.o cardapio.o cliente.o gerente.o logo.o
	
rodar:
	./meuPrograma

limpar:
	rm -f meuPrograma *.o
