##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	pf_put_int_nbr.c	\
		pf_putstr.c		\
		pf_putchar.c		\
		pf_put_float_nbr.c	\
		my_printf.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libprintf.a

COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"
	@mv $(NAME) -t ../

%.o:    %.c
	@$(CC) -g -o $@ -c $< $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:
	@rm -f ../$(NAME)
	@echo -e "$(NAME) \033[01;38;5;220m'.o' Deletion : DONE$(WHITE)"

fclean:
	@rm -f $(OBJ)
	@echo -e "'$(NAME)' \033[01;38;5;222mhas been delete : DONE$(WHITE)"

re:	fclean all
