# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 10:33:37 by nmattos-          #+#    #+#              #
#    Updated: 2025/04/14 11:07:37 by nmattos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++11
NAME = sed
SRC = 	main.cpp \
		sed.cpp
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
