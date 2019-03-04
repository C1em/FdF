# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 18:29:57 by aljacque          #+#    #+#              #
#    Updated: 2019/03/04 07:08:27 by coremart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
NAME = fdf
FLAGS = -Werror -Wall -Wextra
FLAGSLIBX = -lmlx -framework OpenGL -framework AppKit

### INCLUDES ###
LIB = libft
LIBH = $(LIB)/include
HDIR = includes
LIBA = $(LIB)/libft.a

### SOURCES ###
SDIR = sources
_SRCS = close.c convert_to_vector.c draw.c error.c fill_map.c foreach_vec.c \
free.c ft_color.c main.c menu.c mouse.c move.c reset.c rot_matrix.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRCS))

### OBJECTS ####
ODIR = objects
_OBJ = $(_SRCS:.c=.o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

### RULES ###
all: $(NAME)

$(NAME): $(OBJ)
#	@sh loading.sh
#	@clear
	make -C $(LIB)
	gcc -o $(NAME) $(LIBA) $(OBJ) $(FLAGS) $(FLAGSLIBX)
#	@clear

$(ODIR)/%.o: $(SDIR)/%.c
	gcc $(FLAGS) -o $@ -c $^ -I $(HDIR) -I $(LIBH)
	
clean:
#	@sh delete.sh
	@make -C $(LIB) clean
	@rm -f $(OBJ)

fclean: clean
#	@sh delete.sh
	@make -C $(LIB) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
