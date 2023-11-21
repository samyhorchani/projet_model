# Samy HORCHANI (n° étudiant : 28706765)
all : main

complex.o : complex.c complex.h
	gcc -c complex.c

main.o : main.c
	gcc -c main.c

main : main.o complex.o
	gcc -o main main.o complex.o

clean:
	rm -f *.o main