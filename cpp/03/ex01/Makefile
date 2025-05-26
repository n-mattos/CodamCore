# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 09:44:47 by nmattos-          #+#    #+#              #
#    Updated: 2025/05/20 09:47:09 by nmattos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

XXFLAGS = -Wall -Wextra -Werror -std=c++11
NAME = a.out
SRC = main.cpp \
	  ClapTrap.cpp \
	  ScavTrap.cpp
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
