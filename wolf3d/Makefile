# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiesse <msiesse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 22:26:21 by msiesse           #+#    #+#              #
#    Updated: 2019/09/16 11:55:23 by msiesse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/
SRC_NAME = main.c\
		  open_file.c\
		   parsor.c\
		   parsor_lcol.c\
		   parsor_cam.c\
		   parsor_map.c\
		   parsor_com.c\
		   points.c\
		   env_init.c\
		   wolf3d.c\
		   gere_key.c\
		   good_exit.c\
		   draw.c\
		   draw_2.c\
		   search_wall.c\
		   finding.c\
		   fill_pixel.c\
		   draw_col.c\
		   minimap.c\
		   moove.c\
		   moove2.c\
		   bresenham.c\
		   bresenham3.c\
		   bresenham4.c\
		   bresenham_vert.c\
		   texture.c\
		   fill_texture_floor.c\
		   rain.c\
		   fill_texture_sky.c\
		   math_functions.c\
		   utilities.c

OBJ_PATH = objs/
INC_PATH = includes/
INC_NAME = color.h\
		   keyboard.h\
		   wolf3d.h
LIB_PATH = libft
MLX_PATH = minilibx_macos
PRINTF_PATH = libft/ft_printf
GEN_PATH = generator/
GEN_NAME = gen_map
GEN = $(addprefix $(GEN_PATH),$(GEN_NAME))
CPPFLAGS = -I$(INC_PATH) -I$(LIB_PATH) -I$(PRINTF_PATH) -I$(MLX_PATH)
LDLIBS = -Llibft -lft
LDLIBX = -Lminilibx_macos -lmlx
FRAMEWK = -framework OpenGL -framework AppKit
NAME = wolf3d
CC = clang
CFLAGS = -Wall -Werror -Wextra -O2 -ffreestanding -fno-builtin
SANITIZE= -fsanitize=address -g3
GCOV = -fprofile-arcs -ftest-coverage
OBJ_NAME = $(SRC_NAME:.c=.o)
PLIST= $(SRC_NAME:.c=.plist)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

.PHONY: all, clean, fclean, re, norme, cleanlib, analyzer

all: $(NAME) gen

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)
	$(CC) $(LDFLAGS) $(LDLIBS) $(LDLIBX) $(FRAMEWK) $^ -o $@

$(OBJ): $(INC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean: clean_gcov
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

gcov_debug: $(SRC)
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)
	$(CC) $(LDFLAGS) $(LDLIBS) $(LDLIBX) $(FRAMEWK) $(CPPFLAGS) $(GCOV) $^ -o $(NAME)

clean_gcov:
	rm -fv *.gcov *.gcda *.gcno

re_gcov: clean_gcov fclean gcov_debug

norme:
	norminette $(SRC_PATH)
	norminette $(INC_PATH)
	norminette $(LIB_PATH)

cleanlib:
	@make -C $(LIB_PATH) fclean
	@make -C $(MLX_PATH) clean

analyzer:
	$(CC) -fsyntax-only $(CFLAGS) $(CPPFLAGS) $(SRC)
	$(CC) --analyze $(CFLAGS) $(CPPFLAGS) $(SRC)

clean_analyzer:
	rm -fv $(PLIST)

ifeq (create_map,$(firstword $(MAKECMDGOALS)))
ARGS = $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
$(eval $(ARGS):;@:)
else
ARGS = test
$(eval $(ARGS):;@:)
endif

gen:
	@make -C $(GEN_PATH)

create_map: gen
	@$(GEN) $(ARGS)
	@chmod 700 $(ARGS)

clean_gen:
	@make -C $(GEN_PATH) clean

fclean_gen:
	@make -C $(GEN_PATH) fclean

fclean_all: fclean_gen fclean cleanlib
