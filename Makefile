NAME = fdf
FLAGS = -Werror -Wall -Wextra
FLAGSLIBX = -lmlx -framework OpenGL -framework AppKit
LIB = includes/libft/
INC = includes/fdf.h
LIBA = includes/libft/libft.a
SRC = src/main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@gcc -o $(NAME) $(LIBA) $(SRC) $(FLAGS) $(FLAGSLIBX)
	@make clean

%.o: %.c
	@gcc  $(FLAGS) -o $@ -c $<

clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)

re: fclean all
