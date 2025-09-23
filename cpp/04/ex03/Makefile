# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 15:28:26 by nmattos-          #+#    #+#              #
#    Updated: 2025/09/23 11:13:58 by nmattos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

XXFLAGS = -Wall -Wextra -Werror -std=c++11 -g
NAME = a.out
SRC = main.cpp \
	  AMateria.cpp \
	  Character.cpp \
	  MateriaSource.cpp

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
