##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	pf_put_nbr.c	\
		pf_putstr.c	\
		pf_putchar.c	\
		my_printf.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libprintf.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) -t ../../

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf *.o
	@rm -f *~

re:	fclean all
