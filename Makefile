SRCS = server.c \
		client.c

OBJS := $(SRCS:.c=.o)

CC = cc

CFLAGS += -Wall -Werror -Wextra

all: library server client

library:
	make -C Libftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server:		server.o
		${CC} ${CFLAGS} $? Libftprintf/libftprintf.a -o server

client:		client.o
		${CC} ${CFLAGS} $? Libftprintf/libftprintf.a -o client

clean:
	rm -f $(OBJS)
	make clean -C Libftprintf

fclean: clean
	rm -f client
	rm -f server
	make fclean -C Libftprintf

re: fclean all
