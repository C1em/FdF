# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 18:29:57 by aljacque          #+#    #+#              #
#    Updated: 2019/10/31 23:45:09 by coremart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
NAME = fdf
CFLAGS = -g -Werror -Wall -Wextra -std=c99 -pedantic-errors
DFLAGS = -MT $@ -MMD -MP -MF $(DDIR)/$*.d
FLAGSLIBX = -lmlx -framework OpenGL -framework AppKit
ASANFLAGS = -fsanitize=address -fno-omit-frame-pointer -Wno-format-security \
-fsanitize=undefined
AFLAGS =
ASAN =

### INCLUDES ###
LIB = libft
LIBH = $(LIB)/include
HDIR = include
LIBA = $(LIB)/libft.a

### SOURCES ###
SDIR = src
_SRCS = close.c convert_to_vector.c draw.c error.c fill_map.c foreach_vec.c \
free.c ft_color.c main.c menu.c mouse.c move.c reset.c rot_matrix.c
SRCS = $(patsubst %,$(SDIR)/%,$(_SRCS))

### OBJECTS ####
ODIR = obj
_OBJS = $(_SRCS:.c=.o)
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

## DEPENDENCIES ##
DDIR = dep
_DEPS = $(_OBJS:.o=.d)
DEPS = $(patsubst %,$(DDIR)/%,$(_DEPS))

### RULES ###
all: $(NAME)

$(NAME): $(OBJS)
	@if [ "$(AFLAGS)" == "" ];\
	then\
		make -j 4 -C $(LIB);\
	else\
		make -j 4 -C $(LIB) asan;\
	fi
	gcc -o $(NAME) $(LIBA) $(OBJS) $(CFLAGS) $(AFLAGS) $(FLAGSLIBX)

$(ODIR)/%.o: $(SDIR)/%.c
	gcc $(CFLAGS) $(DFLAGS) -o $@ -c $< -I $(HDIR) -I $(LIBH) $(AFLAGS)

-include $(DEPS)

clean:
	@make -j 4 -C $(LIB) clean
	@rm -f $(OBJS)

fclean: clean
	@make -j 4 -C $(LIB) fclean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re: fclean all

asan: AFLAGS = $(ASANFLAGS)
asan: all

reasan: AFLAGS = $(ASANFLAGS)
reasan: re

.PRECIOUS: $(DDIR)/%.d
.PHONY: all clean fclean re
