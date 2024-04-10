all: echecs liste.o echiquier.O deplacement.o

liste.o: liste.c liste.h
	gcc -c liste.c

echiquier.o: echiquier.c echiquier.h
	gcc -c echiquier.c

deplacement.o: deplacement.c deplacement.h
	gcc -c positions.c

echecs: echecs.c liste.c echiquier.c deplacement.c liste.h echiquier.h deplacement.h item.h
	gcc -o echecs echecs.c liste.c echiquier.c deplacement.c

clean:	
	rm -f echecs *.o