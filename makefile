SRC = process.c utils.c main.c

OBJS = ${SRC:.c=.o}

NAME = pipex

HEADER = pipex.h

LIB = lib/libft.a

PRINTOOL = ft_fprintf/libftprintf.a

RM = rm -rf

CC = cc

W = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	make -C lib
	${CC} ${W} ${OBJS} ${LIB} -o ${NAME}
#cc ${W} $^ ft_fprintf/libftprintf.a -o $@

%.o : %.c ${HEADER}
	${CC} ${W} -c $< -o $@


clean : 
	make clean -C lib
	${RM} ${OBJS}
fclean : clean
	make fclean -C lib
	${RM} ${NAME}
re : fclean all