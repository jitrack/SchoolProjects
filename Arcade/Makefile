##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

GAMES		:=	./lib/games
GRAPHICS	:=	./lib/graphicalLibs
CORE		:=	./Core

FILES	:=	$(GAMES)	\
			$(GRAPHICS)	\
			$(CORE)

all:
	@rm -rf vgcore*
	@for folder in $(FILES); do      				\
	$(MAKE) --no-print-directory -C $$folder;	 	\
	done

core:
	@$(MAKE) --no-print-directory -C $(CORE)

games:
	@$(MAKE) --no-print-directory -C $(GAMES)

graphicals:
	@$(MAKE) --no-print-directory -C $(GRAPHICS)

clean:
	@for folder in $(FILES); do      					\
	$(MAKE) --no-print-directory -C $$folder clean; 	\
	done

fclean:
	@for folder in $(FILES); do      					\
	$(MAKE) --no-print-directory -C $$folder fclean; 	\
	done

re:
	@for folder in $(FILES); do      				\
	$(MAKE) --no-print-directory -C $$folder re; 	\
	done
	@rm -rf vgcore*


print-%  : ; @echo $* = $($*)
