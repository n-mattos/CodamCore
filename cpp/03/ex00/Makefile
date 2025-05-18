# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmattos <nmattos@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2025/05/18 13:33:41 by nmattos       #+#    #+#                  #
#    Updated: 2025/05/18 13:33:53 by nmattos       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++11
NAME = a.out
SRC = main.cpp \
	  ClapTrap.cpp
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
