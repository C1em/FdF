# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 18:29:57 by aljacque          #+#    #+#              #
#    Updated: 2019/01/20 18:54:57 by aljacque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
NAME = fdf
FLAGS = -Werror -Wall -Wextra
FLAGSLIBX = -lmlx -framework OpenGL -framework AppKit

### INCLUDES ###
LIB = libft/
INC = includes/fdf.h
LIBA = libft/libft.a

### SOURCES ###
SRC = sources/main.c

### OBJECTS ####
OBJ = $(SRC:.c=.o)

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@gcc -o $(NAME) $(LIBA) $(SRC) $(FLAGS) $(FLAGSLIBX)
	@make clean
	@echo "[ $(GREEN)OK$(NOC) ]\tFDF created."

%.o: %.c
	@gcc  $(FLAGS) -o $@ -c $<

clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ)
	@echo "[ $(GREEN)OK$(NOC) ]\tFiles .o deleted."

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
	@echo "[ $(GREEN)OK$(NOC) ]\tFDF deleted."

re:
	@$(MAKE) fclean
	@$(MAKE) all
