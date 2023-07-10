##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##



_MAKEFILES	:=	objdump	\
				nm		\

COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K

all:    make_all

nm:
	$(MAKE) --no-print-directory -C ./lib/my_printf
	$(MAKE) --no-print-directory -C nm re

objdump:
	$(MAKE) --no-print-directory -C ./lib/my_printf
	$(MAKE) --no-print-directory -C objdump re

clean:
	@rm -f $(NAME)
	@rm -f vgcore*
	@echo -e "$(NAME) \033[01;38;5;220m'.o' Deletion : DONE$(WHITE)"

fclean: make_fclean
	@rm -f $(OBJ) vgcore.*
	@echo -e "'$(NAME)' \033[01;38;5;222mdeletion : DONE$(WHITE)"

re:     fclean  all

clean_all: fclean

make_all:
	$(MAKE) --no-print-directory -C ./lib/my_printf
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C $$makefile;	\
		done

make_clean:
	@for makefile in $(_MAKEFILES); do      \
	$(MAKE) --no-print-directory -C $$makefile clean;   \
		done

make_fclean:
	@for makefile in $(_MAKEFILES); do      \
	$(MAKE) --no-print-directory -C $$makefile fclean;  \
		done

print-%  : ; @echo $* = $($*)

.PHONY: $(NAME) clean fclean re nm objdump
