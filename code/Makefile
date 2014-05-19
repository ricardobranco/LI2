CFLAGS=-Wall -Wextra -pedantic -ansi -O2
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))
LIBS=-lreadline

all: encontrar_todas

encontrar_todas: $(OBJS)
	$(CC) $(CFLAGS) -o encontrar_todas $(OBJS) $(LIBS)

clean:
	rm encontrar_todas *.o
