# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 05:40:09 by zael-mab          #+#    #+#              #
#    Updated: 2020/02/14 05:40:13 by zael-mab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zael-mab.filler

SRC = main.c\
		filler.c\
		rp_ps.c
OBJ = $(SRC:.c=.o)

HEADER = filler.h
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

# =========================================================================== #

all: depbuild $(NAME)

depbuild:
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(HEADER) 
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "done\033[0m"

re: fclean all
