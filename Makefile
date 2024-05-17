all: echecs liste.o echiquier.O deplacement.o minmax.o graphique.o

liste.o: liste.c liste.h
	gcc -c liste.c

echiquier.o: echiquier.c echiquier.h
	gcc -c echiquier.c

deplacement.o: deplacement.c deplacement.h
	gcc -c deplacement.c

minmax.o: minmax.c minmax.h
	gcc -c minmax.c

graphique.o: graphique.c graphique.h
	gcc -c graphique.c

echecs: echecs.c liste.c echiquier.c deplacement.c minmax.c graphique.c liste.h echiquier.h deplacement.h minmax.h graphique.h item.h 
	gcc -o echecs echecs.c liste.c echiquier.c deplacement.c minmax.c graphique.c  -lSDL2 

clean:	
	rm -f echecs *.o

# -Wall -Wextra -Werror