# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 07:21:19 by fasare            #+#    #+#              #
#    Updated: 2023/06/23 23:01:41 by fasare           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			= ft_printf.c\
				  ft_printf_unsigned_int.c\
				  ft_printf_ptr_hex.c\
				  ft_printf_int_str.c \
			      ft_printf_hex_len.c
				    
OBJS			= $(SRCS:.c=.o)

CFLAGS			= -Wall -Wextra -Werror

CC				= gcc

RM 				= rm -f

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

%.o: %.c		
				$(CC) $(CFLAGS) -c $< -o $@


all:			$(NAME)
				
clean:			
				$(RM) $(OBJS) 
				
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
