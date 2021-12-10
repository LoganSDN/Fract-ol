NAME	=	fractol
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -Ofast

SRCS	=	main.c \
			srcs/mandelbrot.c \
			srcs/init.c \
			srcs/draw.c \
			srcs/keys.c \
			srcs/julia.c \
			srcs/process.c \
			srcs/error.c \
			srcs/burning_ship.c \
			srcs/mouse.c \
			srcs/help.c \
			srcs/color.c

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

%.o:	%.c include/fractol.h
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) 
		@make -C ./libft/
		$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L libft -l ft -o $(NAME)

all: $(NAME)

clean :
		@make -C ./libft/ clean
		${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
		@make -C ./libft/ fclean
		${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
