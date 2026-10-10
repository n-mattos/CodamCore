# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmattos- <nmattos-@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/09/10 10:54:31 by nmattos-      #+#    #+#                  #
#    Updated: 2026/10/10 11:42:11 by nmattos       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++11
NAME = a.out
SRC = main.cpp
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
