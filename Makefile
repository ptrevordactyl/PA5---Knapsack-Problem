pa5: main.o maxval.o sackinfo.o custom.h
	gcc -o pa5 main.o maxval.o sackinfo.o
main.o: main.c custom.h
	gcc -c main.c
maxval.o: maxval.c custom.h
	gcc -c maxval.c
sackinfo.o: sackinfo.c custom.h
	gcc -c sackinfo.c
clean: 
	rm pa3 main.o 
