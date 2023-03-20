SRCS = process.c utils.c

OBJS = ${SRCS:.C=.O}

NAME = pipex

HEADER = pipex.h

RM = rm -rf

CC = cc

W = Wall Wextra Werror -c 

all: ${NAME}

${NAME}: ${OBJS}
	make -C lib
	cc ${W} $^ lib/libft.a -o $@
	cc ${W} $^ fprintf/libftprintf.a -o $@

%.o : %.c ${HEADER}
	${CC} ${W} $< -o $@

clean : 
	${RM} ${OBJS} libtool/*.o
fclean : clean
	${RM} ${NAME}
re : fclean all