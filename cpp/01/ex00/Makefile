# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmattos <nmattos@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2025/04/07 11:28:52 by nmattos       #+#    #+#                  #
#    Updated: 2025/04/13 09:52:07 by nmattos       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++11
NAME = BraiiiiiiinnnzzzZ
SRC = 	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp
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
