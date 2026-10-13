# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/12 11:19:20 by nmattos-          #+#    #+#              #
#    Updated: 2026/10/13 10:34:36 by nmattos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++17
NAME = btc
SRC = main.cpp \
	  BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
