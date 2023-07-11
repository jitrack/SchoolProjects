##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

EXT	:=	.cpp

CC	=	g++

SRC		:=	src/
FSRC	:=	NCurses		\

FILES	:=	SRC		\

_FILES  :=  $(foreach FILE, $(FILES), $(addprefix $($(FILE)), $($(addprefix F, $(FILE)))))

_FILES_	:=	$(addsuffix $(EXT), $(_FILES)) \

OBJ     =   $(_FILES_:$(EXT)=.o)

NAME    =   arcade_ncurses.so

CFLAGS	:=	-std=c++14 -Wall -Wextra -g -Wno-unused-label -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable

LDFLAGS	:=	-lncurses -lm

############colors##############
COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K
################################

all:    $(NAME)

$(NAME): $(OBJ)
	@echo -ne "\033[0;33mcompiling $(NAME): \033[0;0m" && \
	$(CC) $(CFLAGS) -shared -o $(NAME) $(OBJ) $(LDFLAGS) && \
	mv $(NAME) ../../ && \
	echo -e "\033[0;32m[OK]\033[0;0m" || \
	echo -e "\033[0;31m[FAILED]\033[0;0m"

%.o:    %.cpp
	@$(CC) -g -o $@ -c $< $(CFLAGS) -fPIC $(LDFLAGS) $(CPP_VERSION) $(VERBOSE)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

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
