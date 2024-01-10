# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:06:00 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/10 16:40:18 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Wextra -Werror
UTILS= _errors/map_check1.c _errors/logger.c vectors/vector2.c
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