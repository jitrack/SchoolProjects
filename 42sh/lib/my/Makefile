##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

SRC	=	my_getnbr.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_strlen_2.c		\
		is_thing.c		\
		strcmp.c		\
		strcmp_2.c		\
		my_int_to_array.c	\
		my_strcpy.c		\
		my_strcat.c		\
		freeif.c		\
		fd.c			\
		my_str_to_array.c	\
		arraycpy.c		\
		my_memset.c		\
		array_create.c		\
		write_file.c		\
		create_and_set_array.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K

all:    $(NAME)

$(NAME):        $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"
	@rm *.o
	@$(MAKE) --no-print-directory -C my_printf all
	@mv $(NAME) ../

%.o:    %.c
	@$(CC) -g -o $@ -c $< $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C my_printf clean
	@echo -e "$(NAME) \033[01;38;5;220m'.o' Deletion : DONE$(WHITE)"

fclean: clean
	@rm -f $(OBJ)
	@$(MAKE) --no-print-directory -C my_printf fclean
	@echo -e "'$(NAME)' \033[01;38;5;222mhas been delete : DONE$(WHITE)"

re:     fclean all
	@$(MAKE) --no-print-directory -C my_printf re
