CFLAGS = -Wall -Werror -Wextra
NAME = so_long.a
RM = rm -rf
SRC = main.c utiles.c utiles1.c result.c utiles_main.c check_maps2.c check_name.c utiles_walk.c  key.c move.c check_maps.c graphice.c ./ft_printf/ft_printf.c ./ft_printf/ft_putchar.c ./ft_printf/ft_putstr.c ./ft_printf/ft_putnbr_base.c ./ft_printf/ft_putnbr_pointer.c  ./get_next_line/get_next_line.c  ./get_next_line/get_next_line_utils.c 
BSRC = bonus_main.c utiles.c utiles1.c utiles_bonus.c  result.c  check_maps2.c check_name.c utiles_walk.c utiles_monster.c move_monstor.c key_bonus.c move_bonus.c check_maps.c graphice_bonus.c ./ft_printf/ft_printf.c ./ft_printf/ft_putchar.c ./ft_printf/ft_putstr.c ./ft_printf/ft_putnbr_base.c ./ft_printf/ft_putnbr_pointer.c  ./get_next_line/get_next_line.c  ./get_next_line/get_next_line_utils.c 
OBJ = $(SRC:.c=.o )
BOBJ = $(BSRC:.c=.o )
AR = ar -rc


all: 
	@gcc  $(SRC) -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	@$(AR) $(NAME) $^

bonus:
	@gcc  $(BSRC) -lmlx -framework OpenGL -framework AppKit

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
