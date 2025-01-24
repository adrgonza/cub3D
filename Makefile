# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 14:59:15 by mcordoba          #+#    #+#              #
#    Updated: 2023/06/21 19:08:34 by adrgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN = 		main.c \
				main_utils/errmanag.c \
				main_utils/error_messages.c \
				main_utils/file_manager.c \
				main_utils/freedom.c

SRC_PARSER =	parser/parser.c \
				parser/utils/read_file.c \
				parser/utils/data_assigner.c \
				parser/utils/assigner_checkers.c \
				parser/utils/parser_err_msg.c \
				parser/utils/find_map.c \
				parser/utils/other_utils.c \
				parser/utils/save_map.c \
				parser/utils/map_checker.c

SRC_RAYCAST =	raycast/raycast.c \
				raycast/tools.c \
				raycast/key_manage.c \
				raycast/draw_game.c \

NAME = cub3D

SEARCH = cub3d.h

OBJ_MAIN = $(SRC_MAIN:%.c=%.o)

OBJ_PARSER = $(SRC_PARSER:%.c=%.o)

OBJ_RAYCAST = $(SRC_RAYCAST:%.c=%.o)

RM = rm -f

CC = gcc

FLAGS_MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra -O3

CFNAME = -o $(NAME)

LIBFT_SRC = libs/libft/libft.a

MLX_DIR = libs/minilibx

all: $(NAME)

#### MACOS COMPILER WITH LIBRARIES

#$(NAME): $(OBJ) $(SEARCH)
#	@make -C libs/Libft
#	@make -C libs/minilibx_macos
#	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_SRC) $(MINILIBX_SRC) -lmlx -framework OpenGL -framework AppKit -L. $(CFNAME)
#
#clean:
#	@make clean -C libs/Libft
#	@make clean -C libs/minilibx_macos
#	$(RM) $(OBJ) $(BONUS_OBJ)
#
#fclean: clean
#	@rm -f libs/Libft/libft.a
#	@rm -f libs/minilibx_macos/libmlx.a
#	$(RM) $(NAME) $(OBJ)

#### LINUX PARSER

$(NAME): $(OBJ_MAIN) $(OBJ_PARSER) $(OBJ_RAYCAST) $(SEARCH)
	@make -C libs/libft
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(FLAGS_MLX) $(CFLAGS) $(OBJ_MAIN) $(OBJ_PARSER) $(OBJ_RAYCAST) $(LIBFT_SRC) $(CFNAME)

clean:
	@make clean -C libs/libft
	$(RM) $(OBJ_MAIN) $(OBJ_PARSER) $(OBJ_RAYCAST)

fclean: clean
	@rm -f libs/libft/libft.a
	$(RM) $(NAME) $(OBJ)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
