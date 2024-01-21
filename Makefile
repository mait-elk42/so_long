# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:06:00 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/21 23:12:26 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Wextra -Werror
UTILS= utils/map_check.c utils/logger.c utils/vector2.c utils/args_checker.c \
	utils/game.c utils/events.c utils/object.c utils/free_mem.c utils/protect.c \
	utils/easy_mlx.c utils/player_mover.c utils/flood_fill.c utils/maps_reader.c \
	utils/renderer.c utils/enemy.c

B_UTILS= utils_bonus/map_check_bonus.c utils_bonus/logger_bonus.c utils_bonus/vector2_bonus.c utils_bonus/args_checker_bonus.c \
	utils_bonus/game_bonus.c utils_bonus/events_bonus.c utils_bonus/object_bonus.c utils_bonus/free_mem_bonus.c utils_bonus/protect_bonus.c \
	utils_bonus/easy_mlx_bonus.c utils_bonus/player_mover_bonus.c utils_bonus/flood_fill_bonus.c utils_bonus/maps_reader_bonus.c \
	utils_bonus/renderer_bonus.c utils_bonus/enemy_bonus.c

UTILS_O=$(UTILS:.c=.o)
B_UTILS_O=$(B_UTILS:.c=.o)
LIBFT= ./libft_advanced/libft.a
PATH_LIBFT= ./libft_advanced/
INC= include
CC= cc
NAME= so_long
BONUS= so_long_bonus

all:  $(NAME)
	@echo "SO_LONG IS READY"

bonus: $(BONUS)
	@echo "SO_LONG_BONUS IS READY"

$(NAME): $(LIBFT) $(UTILS_O) so_long.o
	$(CC) $(CFLAGS) so_long.o $(UTILS_O) $(LIBFT) -I $(INC) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

$(BONUS): $(LIBFT) $(B_UTILS_O) so_long_bonus.o
	$(CC) $(CFLAGS) so_long_bonus.o $(B_UTILS_O) $(LIBFT) -I $(INC) -o $(BONUS) -lmlx -framework OpenGL -framework AppKit

so_long.o: so_long.c $(INC)/so_long.h
	$(CC) -c $(CFLAGS) -I $(INC) $< -o $@

so_long_bonus.o: so_long_bonus.c $(INC)/so_long_bonus.h
	$(CC) -c $(CFLAGS) -I $(INC) $< -o $@

utils/%.o : utils/%.c $(INC)/so_long.h
	$(CC) -c $(CFLAGS) -I $(INC) $< -o $@

utils_bonus/%.o : utils_bonus/%.c $(INC)/so_long_bonus.h
	$(CC) -c $(CFLAGS) -I $(INC) $< -o $@

$(LIBFT):
	make -C $(PATH_LIBFT)
clean:
	make -C $(PATH_LIBFT) clean
	rm -f $(UTILS_O) $(B_UTILS_O) so_long_bonus.o so_long.o

fclean: clean
	make -C $(PATH_LIBFT) fclean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus