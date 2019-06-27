# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:32:32 by sgusache          #+#    #+#              #
#    Updated: 2019/06/27 05:50:11 by sgusache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ssl
SRC	=			dispatch.c\
				main.c\
				md5.c\
				resolve.c\
				shatfs.c\
				utils.c


HEADER	= -I ./includes/header.h
LIB		= ./includes/libftprintf.a

$(NAME): $(SRC)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(HEADER) $(LIB)

all: $(NAME)

clean:
	@rm -rf $(NAME)*

fclean: clean

re: fclean $(NAME)
