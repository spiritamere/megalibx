SRCS	= ft_put_pixel.c \
ft_init_mlx.c
OBJS	= ${SRCS:.c=.o}
NAME	= megalibx.a
HEADER	= megalibx.h
CFLAGS	= -Wall -Wextra -Werror
FFLAGS	= -framework OpenGL -framework AppKit
LIB		= ./minilibx_macos/libmlx.a
CC		= gcc

%.o: %.c ${HEADER} Makefile ${LIB}
	${CC} ${CFLAGS} -c $< -o $@

all:	library ${NAME}

library:
	make -C ./minilibx_macos

${NAME}: ${OBJS} ${LIB}
	${CC} ${CFLAGS} ${FFLAGS} -o ${NAME} ${OBJS} ${LIB}

clean:
	rm -f ${OBJS}
	make clean -C ./minilibx_macos

fclean:
	rm -f ${NAME} ${OBJS}
	make clean -C ./minilibx_macos

re:	fclean all

.PHONY:	all clean fclean re library