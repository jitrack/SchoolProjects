##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME    :=      my_nm

CC	:=	gcc
C	:=	.c

SRC	:=	src/
FSRC	:=	main		\

PROCESS		:=	$(SRC)process/
FPROCESS	:=	process				\
				parser				\
				display_syms_32bits	\
				display_syms_64bits	\

UTILS	:=	$(SRC)utils/
FUTILS	:=	fd			\
			my_string		\
			list		\
			utils		\

FILES	:=	SRC			\
			PROCESS		\
			UTILS		\

_FILES  :=      $(foreach FILE, $(FILES), $(addprefix $($(FILE)), $($(addprefix F, $(FILE)))))

_FILES_	:=	$(addsuffix $(C), $(_FILES))

OBJ     :=      $(_FILES_:$(C)=.o)

LIBNAME	:=	printf\

LIBS    :=      $(addprefix -l, $(LIBNAME))

LDFLAGS +=      -L../lib $(LIBS)

CFLAGS	+=	-I./include -Wall -Wextra -g -Wno-unused-label -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable

VERBOSE=

COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K

all:    $(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[01;38;5;154m========================== start Compiling :\033[0;0m"
	@$(CC)  $(OBJ) -o $(NAME) $(LDFLAGS) $(VERBOSE)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"
	@echo -e "\033[01;38;5;154m========================== Compiling : Done\033[0;0m"
	@mv $(NAME) ..

%.o:    %.c
	@$(CC) -g -o $@ -c $< $(CFLAGS) $(VERBOSE)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:
	@rm -f ../$(NAME)
	@rm -f vgcore*
	@echo -e "$(NAME) \033[01;38;5;220m'.o' Deletion : DONE$(WHITE)"

fclean: clean
	@rm -f $(OBJ)
	@echo -e "'$(NAME)' \033[01;38;5;222mdeletion : DONE$(WHITE)"

re:     fclean  all

clean_all: fclean

print-%  : ; @echo $* = $($*)

rebuild: fclean all

.PHONY: $(NAME) clean fclean re test
