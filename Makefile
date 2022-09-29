NAME = minitalk
CLIENT_EX = client
SERVER_EX = server
CLIENT_BNS = client_bonus
SERVER_BNS = server_bonus

LIB_DIR = Libft/
LIB = ${LIB_DIR}libft.a

CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = ${addprefix ${OBJ_DIR}, ${CLIENT_SRC:.c=.o}}
SERVER_OBJ = ${addprefix ${OBJ_DIR}, ${SERVER_SRC:.c=.o}}
CLIENT_DPS = ${addsuffix .d, ${basename ${CLIENT_OBJ}}}
SERVER_DPS = ${addsuffix .d, ${basename ${SERVER_OBJ}}}

CLIENT_SRC_BNS = client_bonus.c
SERVER_SRC_BNS = server_bonus.c
CLIENT_OBJ_BNS = ${addprefix ${OBJ_DIR}, ${CLIENT_SRC_BNS:.c=.o}}
SERVER_OBJ_BNS = ${addprefix ${OBJ_DIR}, ${SERVER_SRC_BNS:.c=.o}}
CLIENT_DPS_BNS = ${addsuffix .d, ${basename ${CLIENT_OBJ_BNS}}}
SERVER_DPS_BNS = ${addsuffix .d, ${basename ${SERVER_OBJ_BNS}}}

OBJ_DIR = obj/

CFLAGS = -Wall -Wextra -Werror
XFLAGS = -fsanitize=address -g3
RM = rm -rf

${OBJ_DIR}%.o: %.c Makefile
	mkdir -p ${dir $@}
	${CC} -MT $@ -MMD ${CFLAGS} -c $< -o $@

all: makelib ${NAME}

${NAME}: ${CLIENT_EX} ${SERVER_EX}

${CLIENT_EX}: ${CLIENT_OBJ}
	${CC} ${CFLAGS} ${XFLAGS} ${CLIENT_OBJ} ${LIB} -o ${CLIENT_EX}

${SERVER_EX}: ${SERVER_OBJ}
	${CC} ${CFLAGS} ${XFLAGS} ${SERVER_OBJ} ${LIB} -o ${SERVER_EX}

bonus: makelib ${CLIENT_BNS} ${SERVER_BNS}

${CLIENT_BNS}: ${CLIENT_OBJ_BNS}
	${CC} ${CFLAGS} ${CLIENT_OBJ_BNS} ${LIB} -o ${CLIENT_BNS}

${SERVER_BNS}: ${SERVER_OBJ_BNS}
	${CC} ${CFLAGS} ${SERVER_OBJ_BNS} ${LIB} -o ${SERVER_BNS}

makelib:
	make -C ${LIB_DIR}

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${CLIENT_EX} ${SERVER_EX}
	${RM} ${CLIENT_BNS} ${SERVER_BNS}
	make fclean -C ${LIB_DIR}

re: fclean all

-include ${CLIENT_DPS}
-include ${SERVER_DPS}
-include ${CLIENT_DPS_BNS}
-include ${SERVER_DPS_BNS}

.PHONY: all bonus makelib clean fclean re
