# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 13:53:35 by ltomasze          #+#    #+#              #
#    Updated: 2025/09/09 13:55:34 by ltomasze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BitcoinExchange
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp BitcoinExchange.cpp BitcoinExchange.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
