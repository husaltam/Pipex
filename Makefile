# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husaltam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 20:48:30 by husaltam          #+#    #+#              #
#    Updated: 2025/05/30 20:48:39 by husaltam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================
# Master Makefile for pipex
# ==============================

# ===== Executables =====
NAME        := pipex
BONUS_NAME  := pipex_bonus

# ===== Directory Structure =====
SRC_DIR     := srcs
BONUS_DIR   := src_bonus
OBJ_DIR     := obj
LIBFT_DIR   := lib/libft
PRINTF_DIR  := lib/ft_printf
GNL_DIR     := lib/get_next_line
INC_DIR     := includes

# ===== Compiler & Flags =====
CC      := cc
CFLAGS := -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory

# ===== Sources & Objects =====
SRCS        := $(wildcard $(SRC_DIR)/*.c)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_SRCS  := $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJS  := $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

# ===== Libraries =====
LIB_DIR     := $(OBJ_DIR)/lib
LIBFT_A  := $(LIB_DIR)/libft_objs/libft.a
PRINTF_A := $(LIB_DIR)/ft_printf_objs/libftprintf.a
GNL_A    := $(LIB_DIR)/get_next_line_objs/libgnl.a

RESET           = \033[0m
ORANGE = \033[1;38;5;209m
NEON_PINK       = \033[1;38;5;213m
HOT_PINK        = \033[1;38;5;198m

# ===== Rules =====
all: $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(NAME)

bonus: $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(BONUS_NAME)

# Compile regular program
$(NAME): $(OBJS)
	@echo "$(HOT_PINK)\n• PIPEX ready!$(RESET)"
	@$(CC) $(CFLAGS) $^ -o $@ $(GNL_A) $(PRINTF_A) $(LIBFT_A)


# Compile bonus program
$(BONUS_NAME): $(BONUS_OBJS)
	@echo "$(HOT_PINK)\n• PIPEX BONUS ready!$(RESET)"
	@$(CC) $(CFLAGS) $^ -o $@ $(GNL_A) $(PRINTF_A) $(LIBFT_A)



# Compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Build libraries
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

$(GNL_A):
	@$(MAKE) -C $(GNL_DIR)

# ============================ CLEANING ============================
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
