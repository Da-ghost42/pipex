SRC = process.c utils.c main.c

OBJS = ${SRC:.c=.o}

SRS_BONUS = pipex_bonus.c get/get_next_line.c \
											get/get_next_line_utils.c \
																		utils.c

OBJ_BONUS = ${SRS_BONUS:.c=.o}

NAME_BONUS = bonus

NAME = pipex

HEADER = pipex.h

LIB = lib/libft.a

OPTION_FLAG = -fsanitize=address

RM = rm -rf

CC = cc


W = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	@echo "compiling..."
	@make -C lib
	@${CC} ${W} ${OPTION_FLAG} ${OBJS} ${LIB} -o ${NAME}
	
BONUS : ${NAME_BONUS}

${NAME_BONUS} : ${OBJ_BONUS}
	@echo "compiling..."
	@make -C lib
	@${CC} ${W} ${OPTION_FLAG} ${OBJ_BONUS} ${LIB} -o  ${NAME_BONUS}

%.o : %.c ${HEADER}
	@${CC} ${W} -c $< -o $@


clean : 
	@make clean -C lib
	@${RM} ${OBJS}
fclean : clean
	make fclean -C lib
	${RM} ${NAME} ${NAME_BONUS} ${OBJ_BONUS}
re : fclean all

./PHONY : BONUS all

./SILENT : re fclean clean all