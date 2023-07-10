##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

ARRAY	:=	arraycpy.c		\
		array_len.c		\
		create_and_set_array.c	\
		free_all.c		\

NUMBER	:=	my_getnbr.c		\
		my_int_to_array.c	\

PRINT	:=	my_putchar.c		\
		my_putstr.c		\

STRING	:=	my_memset.c		\
		my_str_to_array.c	\
		my_strcat.c		\
		my_strcpy.c		\
		my_strlen.c		\
		regex.c			\
		strcmp.c		\
		skip.c			\

_FILES	:=	$(addprefix array/, $(ARRAY)) 	\
		$(addprefix number/, $(NUMBER))	\
		$(addprefix print/, $(PRINT))	\
		$(addprefix string/, $(STRING))	\

OBJ     =       $(_FILES:.c=.o)

NAME    =       libmy.a

CFLAGS	:=	-Wall -I./include -O3

############colors##############
COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K
################################

all:    $(NAME)

$(NAME):        $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"
	@$(MAKE) --no-print-directory -C bitwise all
	@$(MAKE) --no-print-directory -C my_printf all
	@mv $(NAME) ../

%.o:    %.c
	@$(CC) -g -o $@ -c $< $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C bitwise clean
	@$(MAKE) --no-print-directory -C my_printf clean
	@echo -e "$(NAME) \033[01;38;5;220m'.o' Deletion : DONE$(WHITE)"

fclean:
	@rm -f $(OBJ)
	@$(MAKE) --no-print-directory -C bitwise fclean
	@$(MAKE) --no-print-directory -C my_printf fclean
	@echo -e "'$(NAME)' \033[01;38;5;222mhas been delete : DONE$(WHITE)"

re:     fclean all
