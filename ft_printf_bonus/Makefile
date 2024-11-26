# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:55:55 by mpiantan          #+#    #+#              #
#    Updated: 2024/11/21 15:05:35 by mpiantan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar
ARFLAGS = rcs
RM = rm -f

SRC_FILES = ft_flags.c ft_format_char.c ft_format_nbr.c ft_format_str.c \
	    ft_strlen.c ft_format_hexa.c ft_format_ptr.c ft_format_unsigned.c \
	    ft_putnchar.c ft_putstr.c ft_printf.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

BONUS_SRC_FILES = ft_flags.c ft_format_char.c ft_format_nbr.c ft_format_str.c \
		  ft_strlen.c ft_format_hexa.c ft_format_ptr.c ft_format_unsigned.c \
		  ft_putnchar.c ft_putstr.c ft_printf.c \

BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)

NAME = libftprintf.a


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_FILES) $(BONUS_OBJ_FILES)

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ_FILES) $(BONUS_OBJ_FILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_FILES) $(BONUS_OBJ_FILES)

.PHONY: all clean fclean re bonus
