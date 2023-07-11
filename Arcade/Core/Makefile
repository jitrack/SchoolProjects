##
## EPITECH PROJECT, 2021
## Visual Studio Live Share (Workspace) [WSL: Ubuntu]
## File description:
## Makefile
##

NAME    :=      arcade

CC	:=	g++
CPP	:=	.cpp

CPP_VERSION	:=	-std=c++14

SRC		:=	src/
FSRC	:=	Main		\
			Core

EXCEPTIONS	:=	$(SRC)exceptions/
FEXCEPTIONS	:=	Exceptions

FILES	:=	EXCEPTIONS	\

ifeq ($(TEST), True)
	FILES += TESTS
else
	FILES += SRC
endif

_FILES  :=      $(foreach FILE, $(FILES), $(addprefix $($(FILE)), $($(addprefix F, $(FILE)))))

_FILES_	:=	$(addsuffix $(CPP), $(_FILES))

LIBNAME	:=	dl		\

ifeq ($(TEST), True)
	LIBNAME	+= criterion
endif

LIBS    :=      $(addprefix -l, $(LIBNAME))

LDFLAGS +=	$(LIBS)

CFLAGS	+=	-I./include -I./src/exceptions -Wall -Wextra -g3 -fno-gnu-unique -Wno-unused-label -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable -Wno-switch

VERBOSE=

TEST=	False

COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K

all:    $(NAME)

$(NAME):	$(OBJ)
	@echo -ne "\033[0;33mcompiling $(NAME): \033[0;0m" && \
	g++ $(CFLAGS) -o $(NAME) $(_FILES_) $(LDFLAGS) && \
	mv $(NAME) ../ && \
	echo -e "\033[0;32m[OK]\033[0;0m" || \
	echo -e "\033[0;31m[FAILED]\033[0;0m"

%.o:    %.cpp
	@$(CC) -g -o $@ -c $< $(CFLAGS) $(LDFLAGS) $(CPP_VERSION) $(VERBOSE)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:
	@rm -f vgcore*
	@rm -f ../$(NAME) && \
	echo -e "$(NAME) '.o' Deletion: \033[0;32m[OK]\033[0;0m" || \
	echo -e "$(NAME) '.o' Deletion: \033[0;31m[FAILED]\033[0;0m"

fclean: clean
	@rm -f $(OBJ)
	@echo -e "$(NAME) \033[01;38;5;222m has been deleted : DONE$(WHITE)"

re:     fclean  all

clean_all: fclean

print-%  : ; @echo $* = $($*)

rebuild: fclean all

.PHONY: $(NAME) clean fclean re test
