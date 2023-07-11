##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MY      :=      lib/my

ROOT	:=	src/

PROCESS :=      $(ROOT)process/

INIT    :=      $(ROOT)initialisation/

DISP    :=      $(ROOT)display/

ERROR   :=      $(ROOT)error/

GET_CMD	:=	get_cmd/

BUILTIN	:=	$(ROOT)builtin/

LINE_INT	:=	line_interpreter/

OPERATORS	:=	$(ROOT)operators/

UTILITIES	:=	$(ROOT)utilities/

42SHRC	:=	$(ROOT)42shrc/

ALIAS	:=	alias/

EXPORT	:=	export/

SRC	=	$(PROCESS)main.c				\
	        $(PROCESS)check_if_exit.c               	\
		$(PROCESS)signal.c				\
		$(PROCESS)$(GET_CMD)clean_input.c		\
		$(PROCESS)$(GET_CMD)clean_input_utilities.c	\
		$(PROCESS)$(GET_CMD)get_cmd.c			\
		$(PROCESS)$(GET_CMD)get_cmd_between_redirection.c\
		$(PROCESS)$(GET_CMD)check_redirection_operators_syntaxe.c\
		$(PROCESS)$(GET_CMD)create_3d_array.c		\
		$(PROCESS)$(GET_CMD)init_3d_array.c		\
		$(PROCESS)$(LINE_INT)line_interpreter.c		\
		$(PROCESS)$(LINE_INT)create_new_process.c	\
		$(OPERATORS)redirection_handling.c		\
		$(OPERATORS)double_left_chevron.c		\
		$(UTILITIES)utilities_1.c			\
		$(UTILITIES)utilities_2.c			\
		$(UTILITIES)pipe_handling.c			\
		$(BUILTIN)environment.c				\
		$(BUILTIN)setenv.c				\
		$(BUILTIN)check_setenv.c			\
		$(BUILTIN)unsetenv.c				\
		$(BUILTIN)cd.c					\
		$(BUILTIN)echo.c				\
		$(INIT)struct_shell.c              		\
		$(INIT)block_linked_list.c             		\
		$(42SHRC)parse_42shrc.c				\
		$(42SHRC)$(ALIAS)get_alias.c			\
		$(42SHRC)$(ALIAS)fill_allias_in_input.c		\
		$(42SHRC)$(EXPORT)get_export.c			\
		$(ERROR)error_handling.c	        	\
		$(ERROR)check_if_access.c	        	\

NAME    :=      42sh

OBJ     :=      $(SRC:.c=.o)

_MAKEFILES      :=      my      \

LIBS    :=      $(addprefix -l, $(_MAKEFILES))

LDFLAGS +=      -Llib $(LIBS) -lprintf

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
	@find ./$(FSRC) -name "*.o" -delete
	@rm -f vgcore*
	@echo -e "$(NAME) \033[01;38;5;220m'.o' Deletion : DONE$(WHITE)"

fclean: clean   make_fclean
	@rm -f log*
	@rm -f $(NAME)
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
