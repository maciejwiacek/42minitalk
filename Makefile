SRCS = server.c \
		client.c
SRCS_BON = server_bonus.c \
			client_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BON = $(SRCS_BON:.c=.o)

NAME = minitalk
CC = cc
CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME): library $(OBJS)
	${CC} ${CFLAGS} server.o Libftprintf/libftprintf.a -o server
	${CC} ${CFLAGS} client.o Libftprintf/libftprintf.a -o client

library:
	make -C Libftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BON)
	make clean -C Libftprintf

fclean: clean
	rm -f client
	rm -f server
	rm -f client_bonus
	rm -f server_bonus
	make fclean -C Libftprintf

bonus: fclean library $(OBJS_BON)
	${CC} ${CFLAGS} server_bonus.o Libftprintf/libftprintf.a -o server_bonus
	${CC} ${CFLAGS} client_bonus.o Libftprintf/libftprintf.a -o client_bonus

re: fclean all
