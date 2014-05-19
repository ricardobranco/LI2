CFLAGS=-Wall -Wextra -pedantic -ansi -O2
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))
LIBS=-lreadline
NAME=main

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	rm main *.o
