CLIENT_EX = client
SERVER_EX = server

CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = ${CLIENT_SRC:.c=.o}
SERVER_OBJ = ${SERVER_SRC:.c=.o}
CLIENT_DPS = ${CLIENT_SRC:.c=.d}
SERVER_DPS = ${SERVER_SRC:.c=.d}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
RM = rm -rf

all: ${CLIENT_OBJ} ${SERVER_OBJ}
	${CC} ${CFLAGS} ${CLIENT_SRC} -o ${CLIENT_EX}
	${CC} ${CFLAGS} ${SERVER_SRC} -o ${SERVER_EX}

client: ${CLIENT_OBJ}
	${CC} ${CFLAGS} ${CLIENT_SRC} -o ${CLIENT_EX}

server: ${SERVER_OBJ}
	${CC} ${CFLAGS} ${SERVER_SRC} -o ${SERVER_EX}

clean:
	${RM} ${CLIENT_OBJ} ${SERVER_OBJ}

fclean:
	${RM} ${CLIENT_EX} ${SERVER_EX}
	${RM} ${CLIENT_OBJ} ${SERVER_OBJ}
	${RM} ${CLIENT_DPS} ${SERVER_DPS}

re: fclean all

.PHONY: all cleint server clean fclean re