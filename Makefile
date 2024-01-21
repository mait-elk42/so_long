# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:06:00 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/21 18:53:22 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Wextra -Werror
UTILS= so_long.c utils/map_check.c utils/logger.c utils/vector2.c utils/args_checker.c \
	utils/game.c utils/events.c utils/object.c utils/free_mem.c utils/protect.c \
	utils/easy_mlx.c utils/player_mover.c utils/flood_fill.c utils/maps_reader.c \
	utils/renderer.c utils/enemy.c
UTILS_O=$(UTILS:.c=.o)
LIBFT= ./libft_advanced/libft.a
PATH_LIBFT= ./libft_advanced/
INC= include
CC= cc
NAME= so_long

all:  $(NAME)
	@echo "SO_LONG IS READY"

$(NAME): $(LIBFT) $(UTILS_O)
	$(CC) $(CFLAGS) $(UTILS_O) $(LIBFT) -I $(INC) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

%.o : %.c $(INC)/so_long.h
	$(CC) -c $(CFLAGS) -I $(INC) $< -o $@

$(LIBFT):
	make -C $(PATH_LIBFT)
clean:
	make -C $(PATH_LIBFT) clean
	rm -f $(UTILS_O)

fclean: clean
	make -C $(PATH_LIBFT) fclean
	rm -f $(NAME)

bonus: all

re: fclean all

.PHONY: all clean fclean re