##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

C	:=	.c

SOURCE	:=	src/
FSOURCE	:=	malloc		\
			free		\
			realloc		\
			calloc		\
			reallocarray\

FILES	:=	SOURCE		\

_FILES  :=      $(foreach FILE, $(FILES), $(addprefix $($(FILE)), $($(addprefix F, $(FILE)))))

_FILES_	:=	$(addsuffix $(C), $(_FILES)) \

OBJ     =       $(_FILES_:.c=.o)

NAME    =       libmy_malloc.so

CFLAGS	:=	-Wall -I./include -fPIC -g3 -O3

############colors##############
COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K
################################

all:    $(NAME)

$(NAME):        $(OBJ)
	@gcc -shared -o $(NAME) $(OBJ) -fPIC
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"

%.o:    %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:
	@rm -f $(NAME)
	@echo -e "$(NAME) \033[01;38;5;220m'.o' Deletion : DONE$(WHITE)"

fclean:
	@rm -f $(OBJ)
	@echo -e "'$(NAME)' \033[01;38;5;222mhas been delete : DONE$(WHITE)"

re:     fclean all

print-%  : ; @echo $* = $($*)
