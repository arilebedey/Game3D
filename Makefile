NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src
SRC_FILES = main.c \
	init.c \
	input.c \
	parse.c \
	collision.c \
	texture.c \
	error.c \
	debug.c \
	utils.c \
	draw/render.c \
	draw/pixel.c \
	draw/dda.c \
	draw/dda_utils.c \

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC_ALL = $(SRC)

OBJ_DIR = obj

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_ALL))

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	X11_PATH = /opt/X11
	LIBMLX = ./mlx_linux/libmlx_Darwin.a
	CFLAGS += -I$(X11_PATH)/include
	MLXFLAGS = -L$(X11_PATH)/lib -lXext -lX11 -framework OpenGL -framework AppKit
else
	LIBMLX = ./mlx_linux/libmlx_Linux.a
	MLXFLAGS = -lm -lX11 -lXext
endif

RED = \033[31m
GREEN = \033[1;32m
YELLOW = \033[33m
RESET = \033[0m



all : $(NAME)
	@echo "$(GREEN)✨ cub3D ready! ✨$(RESET)"

$(LIBMLX):
	@$(MAKE) -C mlx_linux -f Makefile.mk

$(NAME) : $(LIBFT_A) $(LIBMLX) $(OBJ) 
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $(NAME) $(LIBMLX) -L$(LIBFT_DIR) -lft

$(LIBFT_A):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c -g $< -o $@

clean :
	@echo "$(RED)Cleaning object folder... 🧹$(RESET)"
	@rm -rf $(OBJ_DIR)/*
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean : clean
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(RED)Deleting minishell executable... 🧹⚠️$(RESET)"
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
