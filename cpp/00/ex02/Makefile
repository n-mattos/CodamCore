# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmattos- <nmattos-@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/04/07 11:33:22 by nmattos       #+#    #+#                  #
#    Updated: 2025/04/13 08:51:17 by nmattos       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Account
SRC = Account.cpp \
	  tests.cpp
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
