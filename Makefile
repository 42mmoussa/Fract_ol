# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/03 13:31:03 by mmoussa           #+#    #+#              #
#    Updated: 2019/01/03 13:31:06 by mmoussa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS_LIBS = ./srcs/ft_error.c \
			./srcs/main.c \
			./srcs/ft_draw_julia_mandelbrot.c \
			./srcs/ft_key.c \
			./srcs/move_mouse.c \
			./srcs/put_pixel.c \
			./srcs/init.c \
			./srcs/ft_draw_frac.c \
			./srcs/star.c \
			./srcs/phoenix.c \
			./srcs/ship.c

CC = cc
INC_LIBS = ./include
INC_LIBX = ./minilibx_macos
INC_MINILIBX = ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
OBJS = $(SRCS_LIBS:.c=.o)
FLAGS = -Werror -Wextra -Wall


all: $(NAME)

$(NAME): $(OBJS)
		@make -C libft
		@$(CC) -I $(INC_LIBX) -I $(INC_LIBS) -L libft/ -lft $(OBJS) -L $(INC_MINILIBX) -o $(NAME)
		@echo '\033[32m[ ✔ ] FRACT_OL\033[0m' ""

%.o: $(SRCS)%.c
	@$(CC) $(FLAGS) -o $@ -c $^

clean:
		@make clean -C libft
		@rm -f $(OBJS)
		@echo '\033[32m[ ✔ ] CLEAN\033[0m' ""

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
		@echo '\033[32m[ ✔ ] FCLEAN\033[0m' ""

re: fclean all

.PHONY: re all clean fclean
