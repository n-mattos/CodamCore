# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -ggdb

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRC_PATH = ./srcs
SRCS =	srcs/cheapest_operation.c srcs/functions.c srcs/main.c \
		srcs/memory.c srcs/op_push.c srcs/op_rev_rotate.c \
		srcs/op_rotate.c srcs/op_swap.c srcs/sort.c srcs/sort_help.c \
		srcs/setup.c srcs/quicksort.c srcs/operations.c srcs/normalize.c

BNS_SRCS =	bns/checker.c bns/memory.c bns/functions.c bns/setup.c \
			bns/get_next_line.c bns/get_next_line_utils.c \
			bns/op_push.c bns/op_rev_rotate.c bns/op_rotate.c \
			bns/op_swap.c

OBJS = $(SRCS:%.c=%.o)
BNS_OBJS = $(BNS_SRCS:%.c=%.o)

# Output executable
NAME = push_swap

# Default target
all: $(NAME)

# Rule to create executable
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

bonus: $(LIBFT) $(BNS_OBJS)
	$(CC) $(CFLAGS) -o checker $(BNS_OBJS) $(LIBFT)

# Rule to create libft.a
$(LIBFT):
	@make bonus -C $(LIBFT_PATH)
	@cp $(LIBFT) .
	@mv libft.a $(NAME)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)
	rm -f $(BNS_OBJS)
	rm -f $(LIBFT_PATH)/*.o

# Clean up object files, library, and executable(s)
fclean: clean
	rm -f $(NAME) $(LIBFT)
	rm -f checker

# Recompile all files
re: clean all

# Phony targets
.PHONY: all clean fclean re
