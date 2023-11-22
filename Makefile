# Samy HORCHANI (n° étudiant : 28706765)
all : main

complex.o : complex.c complex.h
	gcc -Wall -c complex.c

main.o : main.c
	gcc -Wall -c main.c

naive_mult_algo.o : naive_mult_algo.c naive_mult_algo.h
	gcc -Wall -c naive_mult_algo.c

main : main.o complex.o naive_mult_algo.o
	gcc -Wall -o main main.o complex.o naive_mult_algo.o

zip :
	zip projet_Samy_HORCHANI Makefile *.c README.md
clean:
	rm -f *.o main