##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME    :=      Test

SOURCE	:=	source/

FSOURCE	:=	main.c	\

FINITIALISATION	:=

FERROR	:=

FPROCESS	:=

FUTILITIES	:=

_FILES  :=      $(addprefix $(SOURCE), $(FSOURCE))   				\
                $(addprefix $(SOURCE)initialisation/, $(FINITIALISATION)) 	\
                $(addprefix $(SOURCE)error/, $(FERROR))   			\
                $(addprefix $(SOURCE)process/, $(FPROCESS)) 			\
                $(addprefix $(SOURCE)utilities/, $(FUTILITIES)) 		\

OBJ     :=      $(_FILES:.c=.o)

_MAKEFILES      :=      my		\

LIBNAME	:=	my	\
		printf	\
		bitwise	\

LIBS    :=      $(addprefix -l, $(LIBNAME))

LDFLAGS +=      -Llib $(LIBS)

CFLAGS	+=	-I./include -Wall -Wextra -g

COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K

all:    $(NAME)

$(NAME):         make_all $(OBJ)
	@$(CC)  $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"
	@echo -e "\033[01;38;5;154m========================== Compiling : Done\033[0;0m"

%.o:    %.c
	@$(CC) -g -o $@ -c $< $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:  make_clean
	@rm -f $(NAME)
	@rm -f vgcore*
	@echo -e "$(NAME) \033[01;38;5;220m'.o' Deletion : DONE$(WHITE)"

fclean: clean   make_fclean
	@rm -f $(OBJ)
	@echo -e "'$(NAME)' \033[01;38;5;222mqdeletion : DONE$(WHITE)"
	@echo -e "\033[01;38;5;154m========================== start Compiling :\033[0;0m"

re:     fclean  all

make_all:
	@for makefile in $(_MAKEFILES); do      \
	$(MAKE) --no-print-directory -C lib/$$makefile; \
	done

make_clean:
	@for makefile in $(_MAKEFILES); do      \
	$(MAKE) --no-print-directory -C lib/$$makefile clean;   \
		done

make_fclean:
	@for makefile in $(_MAKEFILES); do      \
	$(MAKE) --no-print-directory -C lib/$$makefile fclean;  \
		done

run: all
	@./$(NAME)

test: re
	@./$(NAME)

val: re
	@valgrind ./$(NAME)

.PHONY: $(NAME) clean fclean re test
