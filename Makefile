# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:06:00 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/21 04:25:18 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Wextra -Werror
UTILS= utils/map_check.c utils/logger.c utils/vector2.c utils/args_checker.c \
	utils/game.c utils/events.c utils/object.c utils/free_mem.c utils/protect.c \
	utils/easy_mlx.c utils/player_mover.c utils/flood_fill.c utils/maps_reader.c \
	utils/renderer.c utils/enemy.c
LIBFT=ft
PWDLIBFT= ./libft_advanced
INC= include
NAME= so_long

all:  $(NAME)

$(NAME): $(PWDLIBFT)
	cd $(PWDLIBFT) && make
	cc $(CFLAGS) so_long.c $(UTILS) -I $(INC) -o $(NAME) -lmlx -framework OpenGL -framework AppKit -L $(PWDLIBFT) -l$(LIBFT)
c:
	rm -f so_long

re: c all

.PHONY: c all 