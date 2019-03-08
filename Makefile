pa5: main.o
	gcc -o pa5 main.o
main.o: main.c
	gcc -c main.c
clean: 
	rm pa3 main.o 
