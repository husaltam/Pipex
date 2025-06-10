# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husaltam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 16:41:08 by husaltam          #+#    #+#              #
#    Updated: 2025/05/21 13:24:13 by husaltam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

ROOT_OBJ_PATH = ../../obj
LIB_OUTPUT_DIR = $(ROOT_OBJ_PATH)/lib
OBJ_OUTPUT_DIR = $(LIB_OUTPUT_DIR)/libft_objs
NAME = $(OBJ_OUTPUT_DIR)/libft.a

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_strcmp.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strjoin_free.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_free_split.c ft_strndup.c

OBJECTS = $(patsubst %.c,$(OBJ_OUTPUT_DIR)/%.o,$(SRCS))

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(patsubst %.c,$(OBJ_OUTPUT_DIR)/%.o,$(BONUS))

# Silence directory messages
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


all: $(NAME)
	@echo "$(BRIGHT_BLUE)✓ libft library ready...$(RESET)"

$(OBJ_OUTPUT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS) 
	@mkdir -p $(LIB_OUTPUT_DIR)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) $(BONUS_OBJS)
	@-rmdir $(OBJ_OUTPUT_DIR) 2>/dev/null || true
	@/bin/rm -f .ft_* .*.swp

fclean: clean
	@/bin/rm -f $(NAME)
	@-rmdir $(LIB_OUTPUT_DIR) 2>/dev/null || true

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJS)
	@mkdir -p $(LIB_OUTPUT_DIR)
	@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
