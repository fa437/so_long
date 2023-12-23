# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 14:11:03 by fasare            #+#    #+#              #
#    Updated: 2023/12/06 21:21:13 by fasare           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRC			=	main.c so_long_utils.c checks.c checks2.c launch_graphics.c moves.c
GNL_SRC 	=	./gnl/get_next_line.c ./gnl/get_next_line_utils.c
PRINTF_SRC 	= ./ft_printf/ft_printf.c ./ft_printf/ft_printf_unsigned_int.c\
				./ft_printf/ft_printf_ptr_hex.c ./ft_printf/ft_printf_int_str.c\
				./ft_printf/ft_printf_hex_len.c

OBJS	=	$(SRC:.c=.o) $(GNL_SRC:.c=.o) $(PRINTF_SRC:.c=.o)

CC		=	cc
CFLAGS	= 	-Wall -Werror -Wextra -O3

LIBFT_DIR =		./libft/
LIBFT	  =		$(LIBFT_DIR)/libft.a

MLX_DIR =	./minilibx_macos
MLX		  =	$(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	
$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(NAME)

re: fclean all
