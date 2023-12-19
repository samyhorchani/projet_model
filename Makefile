# Samy HORCHANI (n° étudiant : 28706765)
all : main

complex.o : complex.c complex.h
	gcc -Wall -c complex.c

main.o : main.c
	gcc -Wall -c main.c

multiplyPolynomials.o : multiplyPolynomials.c multiplyPolynomials.h
	gcc -Wall -c multiplyPolynomials.c

FFT_and_invFFT.o : FFT_and_invFFT.c FFT_and_invFFT.h
	gcc -Wall -c FFT_and_invFFT.c

main : main.o complex.o multiplyPolynomials.o FFT_and_invFFT.o
	gcc -Wall -g -o main main.o complex.o multiplyPolynomials.o FFT_and_invFFT.o

zip :
	zip projet_Samy_HORCHANI Makefile *.c README.md
clean:
	rm -f *.o main