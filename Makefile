SRCS = server.c \
		client.c

OBJS := $(SRCS:.c=.o)

NAME = minitalk.a

CC = gcc

#CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: server client

server:		server.o
		${CC} ${CFLAGS} $? -o server

client:		client.o
		${CC} ${CFLAGS} $? -o client

# $(NAME): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f client
	rm -f server

re: fclean all
