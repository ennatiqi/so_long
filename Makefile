CFLAGS = -Wall -Werror -Wextra
CC =cc
NAME = so_long
BNAME = so_long_bonus
RM = rm -rf
SRC = main.c utiles.c utiles1.c result.c utiles_main.c check_maps2.c check_name.c utiles_walk.c  key.c move.c check_maps.c graphice.c   ./get_next_line/get_next_line.c  ./get_next_line/get_next_line_utils.c 
BSRC = bonus/bonus_main.c bonus/utiles2_bonus.c bonus/utiles1_bonus.c bonus/utiles_bonus.c  bonus/result_bonus.c  bonus/check_maps2_bonus.c bonus/check_name_bonus.c bonus/utiles_walk_bonus.c bonus/utiles_monster_bonus.c bonus/move_monstor_bonus.c bonus/key_bonus.c bonus/move_bonus.c bonus/check_maps_bonus.c bonus/graphice_bonus.c ./get_next_line/get_next_line.c  ./get_next_line/get_next_line_utils.c 
OBJ = $(SRC:.c=.o )
BOBJ = $(BSRC:.c=.o )
AR = ar -rc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

bonus: $(BNAME)

$(BNAME): $(BOBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(BNAME) $(BOBJ) 

clean:
	@$(RM) $(BOBJ) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(BNAME)

re: fclean all

bre: fclean bonus

.PHONY : all clean fclean re bonus
