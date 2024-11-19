# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:55:55 by mpiantan          #+#    #+#              #
#    Updated: 2024/11/18 15:00:14 by mpiantan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar
ARFLAGS = rcs
RM = rm -f

SRC_FILES = ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_putnbr_base.c \
	    ft_putnbr_unsigned.c ft_putnbr_hexptr.c ft_putptr.c ft_printf.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = libftprintf.a


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_FILES)

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
