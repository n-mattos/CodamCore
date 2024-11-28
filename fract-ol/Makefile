# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -ggdb

MLX_PATH = ./mlx-linux
MLX = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

FTPRINTF_PATH = ./ft_printf
FTPRINTF = $(FTPRINTF_PATH)/libftprintf.a

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRC_DIR = srcs
SRCS =	$(SRC_DIR)/main.c $(SRC_DIR)/init.c $(SRC_DIR)/get_next_line.c \
		$(SRC_DIR)/get_next_line_utils.c $(SRC_DIR)/parse_arguments.c \
		$(SRC_DIR)/print.c $(SRC_DIR)/mandelbrot.c $(SRC_DIR)/draw.c \
		$(SRC_DIR)/colour.c $(SRC_DIR)/hookfunctions.c \
		$(SRC_DIR)/julia.c $(SRC_DIR)/hook.c $(SRC_DIR)/burningship.c \
		$(SRC_DIR)/clean.c $(SRC_DIR)/parse_command_line.c

OBJ_DIR = objs
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output executable
NAME = fractol

# Default target
all: $(NAME)

# Rule to create executable
$(NAME): $(FTPRINTF) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) $(LIBFT) $(MLX) -o $(NAME)

# Rule to create libftprintf.a
$(FTPRINTF):
	@make -C $(FTPRINTF_PATH)

# Rule to create libft.a
$(LIBFT):
	@make bonus -C $(LIBFT_PATH)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(MLX_PATH) -I $(LIBFT_PATH) -I $(FTPRINTF_PATH) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)
	rm -f $(LIBFT_PATH)/*.o
	rm -f $(FTPRINTF_PATH)/srcs/*.o
	rm -rf $(OBJ_DIR)

# Clean up object files, library, and executable(s)
fclean: clean
	rm -f $(NAME) $(LIBFT) $(FTPRINTF)

# Recompile all files
re: clean all

# Phony targets
.PHONY: all clean fclean re
