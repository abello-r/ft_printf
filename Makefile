SRCS	= flag1.c flag2.c flag3.c flag4.c flag5.c flag6.c flag7.c ft_setformat.c ft_printf.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -sC ./libft/
		cp libft/libft.a .
		mv libft.a $(NAME)
		ar rc  $(NAME) $(OBJS)
		ranlib $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		make -sC ./libft/ clean

fclean:	clean
		$(RM) $(NAME)
		make -sC ./libft/ fclean

re:		fclean all

.PHONY:	all fclean re
