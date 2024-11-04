# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRC_PATH = ./srcs
SRCS =	srcs/ft_printf.c srcs/flags.c srcs/flag_utils.c srcs/print_char.c \
		srcs/print_decimal.c srcs/print_string.c srcs/print_unsigned.c \
		srcs/print_hex.c srcs/print_pointer.c srcs/print_utils.c \
		srcs/print_decimal_station.c srcs/print_unsigned_station.c \
		srcs/print_hex_station.c

BNS_SRC_PATH = ./bns
BNS_SRCS = bns/ft_printf_bonus.c bns/flags_bonus.c bns/flag_utils_bonus.c \
		bns/print_char_bonus.c bns/print_decimal_bonus.c \
		bns/print_string_bonus.c bns/print_unsigned_bonus.c \
		bns/print_hex_bonus.c bns/print_pointer_bonus.c \
		bns/print_utils_bonus.c bns/print_decimal_station_bonus.c \
		bns/print_unsigned_station_bonus.c bns/print_hex_station_bonus.c

OBJS = $(SRCS:%.c=%.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

# Output library (libftprintf.a)
NAME = libftprintf.a

# Default target
all: $(NAME)

bonus: $(LIBFT) $(BNS_OBJS)
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
	rm -f $(OBJS) $(BNS_OBJS)
	rm -f $(LIBFT_PATH)/*.o

# Clean up object files and library
fclean: clean
	rm -f $(NAME) $(LIBFT)

# Recompile all files
re: clean all

# Phony targets
.PHONY: all clean fclean re
