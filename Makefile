# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 18:29:57 by aljacque          #+#    #+#              #
#    Updated: 2019/01/25 23:03:47 by aljacque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
NAME = fdf
FLAGS = -Werror -Wall -Wextra
FLAGSLIBX = -lmlx -framework OpenGL -framework AppKit

### INCLUDES ###
LIB = libft/
INC = includes/*.h
LIBA = libft/libft.a

### SOURCES ###
SRC = sources/*.c

### OBJECTS ####
OBJ = $(SRC:.c=.o)

### COLORS ###
RESET       = \033[0m
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

$(NAME):
	@sh loading.sh
	@clear
	@make -C $(LIB)
	@gcc -o $(NAME) $(LIBA) $(SRC) $(FLAGS) $(FLAGSLIBX)
	@clear

%.o: %.c
	@gcc  $(FLAGS) -o $@ -c $<

clean:
	@sh delete.sh
	@make -C $(LIB) clean
	@rm -f $(OBJ)

fclean: clean
	@sh delete.sh
	@make -C $(LIB) fclean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
