immobili: main.o listaImmobili.o
	gcc -g -o immobili main.o listaImmobili.o

main.o: main.c listaImmobili.h
	gcc -c -g main.c

listaImmobili.o: listaImmobili.c listaImmobili.h
	gcc -c -g listaImmobili.c