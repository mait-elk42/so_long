# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:06:00 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/16 16:49:27 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Wextra -Werror
UTILS= utils/map_check1.c utils/logger.c utils/vector2.c utils/args_checker.c utils/game.c utils/events.c utils/object.c utils/free_mem.c utils/protect.c utils/easy_mlx.c
LIBFT=ft
PWDLIBFT= ./libft_Advanced
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