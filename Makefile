# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 18:21:32 by mde-figu          #+#    #+#              #
#    Updated: 2021/04/16 13:39:09 by mde-figu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

ENTRIES = entries.a
COMPONENTS = components.a
CANVAS_NAME = canvas.a
PARAMETERS_NAME = parameters.a
MAIN = main.c
FILE = teste.rt

HEADERS = include
SRC_PATH = ./src
LIBFT = libft
LIBFT_PATH = ./libft
GNL = get_next_line
GNL_PATH = ./get_next_line
OBJ_PATH = ./obj
UNIX_FLAG = -D LINUX
MAC_FLAG = -D OSX
MLX_PATH_UNIX = ./minilibx/minilibx_opengl_20191021
MLX_PATH_MAC = ./minilibx/minilibx-linux
MLX_UNIX_FLAGS = -L $(MLX_PATH_MAC) -lXext -lX11 -lm -lz
MLX_MAC_FLAGS = -L $(MLX_PATH_UNIX) -lmlx -framework OpenGL -framework AppKit

COMP = clang
RM	= rm -rf
CFLAGS = -Wall -Wextra -Werror -I $(HEADERS)
FLAGS = -L $(LIBFT) -lft

SRC = $(notdir $(wildcard ./src/*.c))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

USERNAME := $(shell uname -s)
ifeq ($(USERNAME),Linux)
	OSFLAG += -D LINUX
endif
ifeq ($(USERNAME),Darwin)
	OSFLAG += -D OSX
endif
UNAME_P := $(shell uname -p)
ifeq ($(UNAME_P),x86_64)
	OSFLAG += -D AMD64
endif
ifneq ($(filter %86,$(UNAME_P)),)
	OSFLAG += -D IA32
endif
ifneq ($(filter arm%,$(UNAME_P)),)
	OSFLAG += -D ARM
endif
ifneq ($(SANITIZE_A), true)
	CFLAGS += -fsanitize=address
endif
ifneq ($(SANITIZE_L), true)
	CFLAGS += -fsanitize=leak
endif


$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@make -C $(GNL)
		-$(COMP) $(CFLAGS) $(OBJS) $(FLAGS) $(HEADERs) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir -p objs
		@$(COMP) $(CFLAGS) $(HEADERS) -c $< -o $@
		@echo " "$<" was successfully compiled!"

all: $(NAME)

clean:
		make clean -C $(LIBFT)
		make clean -C $(GNL)
		$(RM) $
