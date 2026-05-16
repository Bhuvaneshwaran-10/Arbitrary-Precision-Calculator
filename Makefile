
Calculator: main.o Addition.o Subtraction.o Multiplication.o Division.o Functions.o
	gcc -o Calculator main.o Addition.o Subtraction.o Multiplication.o Division.o Functions.o
main.o: main.c
	gcc -c main.c
Addition.o: Addition.c
	gcc -c Addition.c
Subtraction.o: Subtraction.c
	gcc -c Subtraction.c
Multiplication.o: Multiplication.c
	gcc -c Multiplication.c
Division.o: Division.c
	gcc -c Division.c
Functions.o: Functions.c
	gcc -c Functions.c
clean:
	rm -f Calculator *.o