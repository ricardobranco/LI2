CFLAGS=-Wall -Wextra -ansi -pedantic -O2
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))
LIBS=-lreadline

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS) $(LIBS)

limpar:
	rm main *.o
