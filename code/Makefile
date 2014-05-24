CFLAGS=-g -Wall -Wextra -pedantic -ansi
OBJS=cadeias.o board.o interpretador.o dictionary.o tree.o
LIBS=-lreadline

all: coords tproc tdic encontrar_todas

encontrar_todas: encontrar_todas.o $(OBJS)
	$(CC) $(CFLAGS) -o encontrar_todas encontrar_todas.o $(OBJS) $(LIBS)

encontrar_todas.o: encontrar_todas.c
	$(CC) $(CFLAGS) -c encontrar_todas.c $(LIBS)

coords: coords.o $(OBJS)
	$(CC) $(CFLAGS) -o coords coords.o $(OBJS) $(LIBS)

coords.o: coords.c
	$(CC) $(CFLAGS) -c coords.c $(LIBS)

tproc: tproc.o $(OBJS)
	$(CC) $(CFLAGS) -o tproc tproc.o $(OBJS) $(LIBS)

tproc.o: tproc.c
	$(CC) $(CFLAGS) -c tproc.c $(LIBS)

tdic: tdic.o $(OBJS)
	$(CC) $(CFLAGS) -o tdic tdic.o $(OBJS) $(LIBS)

tdic.o: tdic.c
	$(CC) $(CFLAGS) -c tdic.c $(LIBS)

clean:
	rm coords tproc *.o
