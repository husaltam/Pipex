# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husaltam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 16:16:08 by husaltam          #+#    #+#              #
#    Updated: 2025/01/12 18:39:17 by husaltam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../obj/lib/ft_printf_objs/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = .
OBJDIR = ../../obj/lib/ft_printf_objs
SRC =	ft_strcpy.c \
		ft_printf.c \
		ft_puthex.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c \
		ft_putunsigned.c \
		handle_conversion.c
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCLUDES = -I.

# Colors
RESET           = \033[0m
ORANGE = \033[1;38;5;209m
BRIGHT_RED      = \033[1;31m
BRIGHT_GREEN    = \033[1;32m
BRIGHT_YELLOW   = \033[1;33m
BRIGHT_BLUE     = \033[1;34m
BRIGHT_MAGENTA  = \033[1;35m
BRIGHT_CYAN     = \033[1;36m
BRIGHT_WHITE    = \033[1;97m
NEON_PINK       = \033[1;38;5;213m
NEON_ORANGE     = \033[1;38;5;202m
NEON_GREEN      = \033[1;38;5;118m
NEON_BLUE       = \033[1;38;5;81m
ELECTRIC_LIME   = \033[1;38;5;154m
HOT_PINK        = \033[1;38;5;198m
CYBER_PURPLE    = \033[1;38;5;135m
TURQUOISE       = \033[1;38;5;45m
BRIGHT_AQUA     = \033[1;38;5;51m
SOLAR_YELLOW    = \033[1;38;5;226m
FLUORESCENT_RED = \033[1;38;5;196m
BUBBLEGUM       = \033[1;38;5;219m
TANGERINE       = \033[1;38;5;208m
GREEN 			= \033[1;32m

# Silence directory messages
MAKEFLAGS += --no-print-directory

all: $(OBJDIR) $(NAME)
	@echo "$(BRIGHT_BLUE)✓ ft_printf library ready...$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME)
	@echo "$(MAGENTA)Building printf test...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(SRC) main.c -o printf_test
	@echo "$(GREEN)Test executable ready!$(RESET)"

clean:
	@rm -f $(OBJ)
	@rm -f printf_test

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test