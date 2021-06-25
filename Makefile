# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 20:08:17 by mde-figu          #+#    #+#              #
#    Updated: 2021/06/25 19:01:36 by mde-figu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src
OBJ_PATH = ./obj
LIB_PATH = ./minilibx
CONFIG_PATH = ./config
LIBFT_PATH = ./libft
GNL_PATH = ./get_next_line
MLX_PATH = ./minilibx/minilibx-linux
MLX_INC_PATH = -I ./minilibx/mlx-linux
MLX_LIBS = -lXext -lX11 -lm -lz


CC = clang
FLAGS = -Wall -Wextra -Werror
LIB_NAME = lib.a
LIBFT_NAME = libft.a
GNL_NAME = get_next_line.a
MLX_NAME = libmlx_Linux.a
NAME = miniRT
MAIN = main.c

LIB = $(LIB_PATH)/$(LIB_NAME)
LIBFT = $(LIBFT_PATH)/$(LIBFT_NAME)
GNL = $(GNL_PATH)/$(GNL_NAME)
SRC = $(notdir $(wildcard ./src/*.c))
OBJ=$(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(GNL_PATH)
	@rm -f $(OBJ_PATH)/*.o

fclean:	clean
	@rm -f $(LIB_PATH)/*.a
	@rm -f $(LIBFT_PATH)/*.a
	@rm -f $(NAME)
	@rm -f *.o
	@rm -fR *.dSYM

re: fclean all

$(NAME):	$(CONFIG_PATH) $(LIBFT) $(LIB)	$(MLX_PATH)/$(MLX_NAME)
	@$(CC) $(FLAGS) $(MAIN) -g $(LIB) $(LIBFT) $(GNL) $(MLX_PATH)/$(MLX_NAME) $(MLX_LIBS) -o $@

$(LIB): $(OBJ)
	@ar rcs $@ $(OBJ)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@$(CC) -g $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(GNL):
	@make -C $(GNL_PATH)

$(MLX_PATH)/%.a:	$(MLX_PATH)/$(MLX_NAME)
	@ar rcs $(MLX_PATH)/$(MLX_NAME) $(OBJ)

$(MLX_PATH)/$(MLX_NAME):
	@$(MAKE) -C $(MLX_PATH)

$(CONFIG_PATH):
	@chmod +x *.sh
	@./*.sh