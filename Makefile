CFLAGS = -Wall -Werror -Wextra
NAME = so_long.a
RM = rm -rf
SRC = ./main.c utiles.c animation/key.c animation/move.c map/check_maps.c map/graphice.c ./ft_printf/ft_printf.c ./ft_printf/ft_putchar.c ./ft_printf/ft_putstr.c ./ft_printf/ft_putnbr_base.c ./ft_printf/ft_putnbr_pointer.c  ./get_next_line/get_next_line.c  ./get_next_line/get_next_line_utils.c 
OBJ = $(SRC:.c=.o )
AR = ar -rc


all: 
	@gcc  $(SRC) -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	@$(AR) $(NAME) $^

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
