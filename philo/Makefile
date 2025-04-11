# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread -pthread

# Source files and object files
SRC_DIR = sources
SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/clean.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/checks.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/actions.c \
		$(SRC_DIR)/routine.c \
		$(SRC_DIR)/forks.c \
		$(SRC_DIR)/monitor.c \

BNS_DIR = bonus
BNS =	$(BNS_DIR)/bonus_main.c \
		$(BNS_DIR)/bonus_clean.c \
		$(BNS_DIR)/bonus_monitor.c \
		$(BNS_DIR)/bonus_utils.c \
		$(BNS_DIR)/bonus_init.c \
		$(BNS_DIR)/bonus_actions.c \
		$(BNS_DIR)/bonus_routine.c \
		$(BNS_DIR)/bonus_forks.c \
		$(BNS_DIR)/bonus_checks.c

OBJ_DIR = objects
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BNS_OBJS = $(BNS:$(BNS_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output executable
NAME = philo

# Default target
all: $(NAME)

# Name rule to create executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus target
bonus: $(BNS_OBJS)
	$(CC) $(CFLAGS) $(BNS_OBJS) -o $(NAME)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(BNS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)
	rm -f $(BNS_OBJS)
	rm -rf $(OBJ_DIR)

# Clean up object files and executable(s)
fclean: clean
	rm -f $(NAME)

# Recompile all files
re: fclean all

# Phony targets
.PHONY: all clean fclean re
