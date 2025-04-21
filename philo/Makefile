# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=thread

# Source files and object files
SRC_DIR = sources
SRCS =	main.c \
		clean.c \
		utils.c \
		checks.c \
		init.c \
		actions.c \
		routine.c \
		forks.c \
		monitor.c \
		start_philos.c

OBJ_DIR = objects
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Output executable
NAME = philo

# Default target
all: $(NAME)

# Name rule to create executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create "objects" folder
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up object files
clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

# Clean up object files and executable(s)
fclean: clean
	rm -f $(NAME)

# Recompile all files
re: fclean all

# Phony targets
.PHONY: all clean fclean re
