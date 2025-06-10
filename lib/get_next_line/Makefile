# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husaltam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 13:33:45 by husaltam          #+#    #+#              #
#    Updated: 2025/05/21 13:34:47 by husaltam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ../../obj/lib/get_next_line_objs/libgnl.a
TEST = test_gnl

SRCDIR = .
OBJDIR = ../../obj/lib/get_next_line_objs

SRC =	get_next_line.c
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

LIBFT_DIR = ../libft
PRINTF_DIR = ../ft_printf
INCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR)

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

# Silence all possible output
MAKEFLAGS += --no-print-directory --silent

all: $(OBJDIR) libs $(NAME)
	@echo "$(BRIGHT_BLUE)✓ get_next_line library ready...$(RESET)"

libs:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory --silent >/dev/null 2>&1
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory --silent >/dev/null 2>&1

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@$(AR) $@ $^

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: libs $(OBJ) main.c
	@$(CC) $(CFLAGS) $(OBJ) main.c -o $(TEST) $(INCLUDES) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf
	@echo "$(GREEN)✓ Test executable ready$(RESET)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(TEST)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory --silent >/dev/null 2>&1
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory --silent >/dev/null 2>&1

re: fclean all

.PHONY: all libs $(OBJDIR) $(NAME) test clean fclean re
