# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/10 16:49:33 by ltomasze          #+#    #+#              #
#    Updated: 2025/05/17 15:22:21 by ltomasze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = noSed
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp replace.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CPPFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re