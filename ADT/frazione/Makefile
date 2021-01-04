frazione: main.o frazione.o
	gcc -g -o frazione  main.o frazione.o

main.o: main.c frazione.h
	gcc -c main.c

frazione.o: frazione.c frazione.h
	gcc -c frazione.c