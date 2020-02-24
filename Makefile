NAME	= libftprintf.a

CC		= cc
RM		= @rm -f
CFLAGS	= -Wall -Werror -Wextra

$(NAME):
		@clear
		@printf "\n\033[32mCompilando... ♻️ \v\n"
		@make -sC ./libft/
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		@gcc -c ft_printf.c
		@ar rc  $(NAME) ft_printf.o
		@ranlib $(NAME)

run:
	@clear #quitar luego campeon acuerdate del alex del pasado
	@gcc ft_printf.c flag1.c ft_setformat.c -g libftprintf.a && ./a.out #lo de arriba x2
	

all:	$(NAME)

clean:
		$(RM) $(NAME)

fclean:	
		$(RM) $(NAME)
		@clear
		@make -sC	./libft/ fclean
		@rm -f ft_printf.o
		@rm -f a.out

re:		fclean all run 

.PHONY:	all fclean re
