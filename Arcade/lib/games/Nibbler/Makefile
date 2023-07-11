##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

EXT	:=	.cpp

CC	=	g++

SRC	:=	src/
FSRC	:=	Nibbler		\

FILES	:=	SRC		\

_FILES  :=  $(foreach FILE, $(FILES), $(addprefix $($(FILE)), $($(addprefix F, $(FILE)))))

_FILES_	:=	$(addsuffix $(EXT), $(_FILES)) \

OBJ     =   $(_FILES_:$(EXT)=.o)

NAME    =   arcade_nibbler.so

CFLAGS	:=	-std=c++14 -Wall -Wextra -g3 -O3 -shared -fPIC -Wno-unused-label -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable

############colors##############
COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K
################################

all:	$(NAME)

$(NAME):
	@echo -ne "\033[0;33mcompiling $(NAME): \033[0;0m" && \
	g++ $(CFLAGS) -o $(NAME) $(_FILES_) && \
	mv $(NAME) ../../ && \
	echo -e "\033[0;32m[OK]\033[0;0m" || \
	echo -e "\033[0;31m[FAILED]\033[0;0m"

clean:
	@rm -f $(OBJ) && \
	echo -e "$(NAME) .o Deletion: \033[0;32m[OK]\033[0;0m" || \
	echo -e "$(NAME) .o Deletion: \033[0;31m[FAILED]\033[0;0m"

fclean: clean
	@rm -f ../../$(NAME) && \
	echo -e "$(NAME) has been deleted: \033[0;32m[OK]\033[0;0m" || \
	echo -e "$(NAME) has been deleted: \033[0;31m[FAILED]\033[0;0m"

re:     fclean all

print-%  : ; @echo $* = $($*)
