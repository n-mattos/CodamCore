# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH	= ../libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRC_PATH = ./srcs
SRCS =	srcs/ft_printf.c srcs/flags.c srcs/flag_utils.c srcs/print_char.c \
		srcs/print_decimal.c srcs/print_string.c srcs/print_unsigned.c \
		srcs/print_hex.c srcs/print_pointer.c srcs/print_utils.c \
		srcs/print_decimal_station.c srcs/print_unsigned_station.c \
		srcs/print_hex_station.c

OBJS = $(SRCS:%.c=%.o)

# Output library (libftprintf.a)
NAME = libftprintf.a

# Default target
all: $(NAME)

bonus: $(LIBFT)
	ar rcs $(NAME) $^

# Rule to create libftprintf.a
$(NAME): $(LIBFT) $(OBJS)
	ar rcs $@ $^

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
	rm -f $(LIBFT_PATH)/*.o

# Clean up object files and library
fclean: clean
	rm -f $(NAME) $(LIBFT)

# Recompile all files
re: clean all

# Phony targets
.PHONY: all clean fclean re
