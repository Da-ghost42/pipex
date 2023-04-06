SRC = process.c utils.c main.c

OBJS = ${SRC:.c=.o}

SRS_BONUS = pipex_bonus.c get/get_next_line.c \
											get/get_next_line_bonus.c \
																		utils.c

OBJ_BONUS = ${SRS_BONUS:.c=.o}
NAME_BONUS = bop

NAME = pipex

HEADER = pipex.h

LIB = lib/libft.a

RM = rm -rf

CC = cc


W = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	make -C lib
	${CC} ${W} ${OBJS} ${LIB} -o ${NAME}
	
BONUS : ${NAME_BONUS}

${NAME_BONUS} : ${OBJ_BONUS}
	make -C lib
	${CC} ${W} ${OBJ_BONUS} ${LIB} -O  ${NAME_BONUS}

%.o : %.c ${HEADER}
	${CC} ${W} -c $< -o $@



clean : 
	make clean -C lib
	${RM} ${OBJS}
fclean : clean
	make fclean -C lib
	${RM} ${NAME}
re : fclean all

./PHONY : BONUS all

./SILENT : 