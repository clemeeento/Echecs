all: echecs liste.o tableau.c

liste.o: liste.c liste.h
	gcc -c liste.c

tableau.o: tableau.c tableau.h
	gcc -c tableau.c

deplacement.o: deplacement.c deplacement.h
	gcc -c positions.c

echecs: echecs.c liste.c tableau.c deplacement.c liste.h tableau.h deplacement.h item.h
	gcc -o echecs echecs.c liste.c tableau.c deplacement.c

clean:	
	rm -f echecs *.o