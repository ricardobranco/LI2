CFLAGS=-Wall -Wextra -pedantic -ansi -O2
OBJS=cadeias.o board.o interpretador.o
LIBS=-lreadline

all: encontrar_todas tproc

encontrar_todas: encontrar_todas.o $(OBJS)
	$(CC) $(CFLAGS) -o encontrar_todas encontrar_todas.o $(OBJS) $(LIBS)

encontrar_todas.o: encontrar_todas.c
	$(CC) $(CFLAGS) -c encontrar_todas.c $(LIBS)

tproc: tproc.o $(OBJS)
	$(CC) $(CFLAGS) -o tproc tproc.o $(OBJS) $(LIBS)

tproc.o: tproc.c
	$(CC) $(CFLAGS) -c tproc.c $(LIBS)

clean:
	rm encontrar_todas tproc *.o
