##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

all:
	@$(MAKE) --no-print-directory -C ./ncurses
	@$(MAKE) --no-print-directory -C ./sfml
	@$(MAKE) --no-print-directory -C ./sdl

clean:
	@$(MAKE) --no-print-directory -C ./ncurses clean
	@$(MAKE) --no-print-directory -C ./sfml clean
	@$(MAKE) --no-print-directory -C ./sdl clean

fclean:
	@$(MAKE) --no-print-directory -C ./ncurses fclean
	@$(MAKE) --no-print-directory -C ./sfml fclean
	@$(MAKE) --no-print-directory -C ./sdl fclean

re:
	@$(MAKE) --no-print-directory -C ./ncurses re
	@$(MAKE) --no-print-directory -C ./sfml re
	@$(MAKE) --no-print-directory -C ./sdl re

print-%  : ; @echo $* = $($*)
