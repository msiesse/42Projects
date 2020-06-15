# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiesse <msiesse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 22:26:21 by msiesse           #+#    #+#              #
#    Updated: 2020/02/10 11:37:37 by msiesse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/
SRC_NAME =	main.c\
			init_sdl.c\
			fill_pixel.c\
			good_exit.c\
			error_exit.c\
			read_file.c\
			handler_event.c\
			free_env.c\
			create_scene_test.c\
			init_scene.c\
			get_mat_base.c\
			mat_functions.c\
			translate_objects.c\
			scale_objects.c\
			get_primray.c\
			points_func.c\
			vect_func.c\
			vect_func_2.c\
			intersect.c\
			intersect_sphere.c\
			intersect_plan.c\
			intersect_cylinder.c\
			intersect_cone.c\
			get_nhit.c\
			rotate_objects.c\
			shadow_ray.c\
			get_color_pixel.c\
			quadratic_function.c\
			limit_objects.c\
			limit_sphere.c\
			limit_cylinder.c\
			limit_plan.c\
			limit_cone.c\
			init_env.c\
			move_cam.c\
			render_scene.c\
			get_info_object.c\
			rotation_matrix.c\
			choose_object.c\
			move_select.c\
			color.c

OBJ_PATH = objs/
INC_PATH = includes/
INC_NAME = rtv1.h\
		color.h
LIB_PATH = libft
SDL_PATH = SDL
SDL_INCLUDE = SDL/include
PRINTF_PATH = libft/ft_printf
CPPFLAGS = -I$(INC_PATH) -I$(SDL_INCLUDE) -I$(LIB_PATH) -I$(PRINTF_PATH)
SDL2_CONFIG = sdl2-config
SDL2_FLAGS = --cflags --libs
LDLIBS = -Llibft -lft
NAME = rtv1
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O2
GCOV = -fprofile-arcs -ftest-coverage #--coverage
OBJ_NAME = $(SRC_NAME:.c=.o)
PLIST= $(SRC_NAME:.c=.plist)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

.PHONY: all, clean, fclean, re, norme, cleanlib, analyzer

all: $(NAME)

$(NAME): sdl $(OBJ)
	make -C $(LIB_PATH)
	$(CC) $(LDLIBS) `$(SDL2_CONFIG) $(SDL2_FLAGS)` $(OBJ) -o $@

sdl:
	./script_sdl

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
	$(CC)  $(CPPFLAGS) `$(SDL2_CONFIG) $(SDL2_FLAGS)` $(GCOV) $^ -o $(NAME)

clean_gcov:
	rm -fv *.gcov *.gcda *.gcno

re_gcov: clean_gcov fclean gcov_debug

norme:
	norminette $(SRC)
	norminette $(INC)

cleanlib:
	@make -C $(LIB_PATH) fclean

analyzer:
	$(CC) -fsyntax-only $(CFLAGS) $(CPPFLAGS) `$(SDL2_CONFIG) $(SDL2_FLAGS)` $(SRC)
	$(CC) --analyze $(CFLAGS) $(CPPFLAGS) `$(SDL2_CONFIG) $(SDL2_FLAGS)` $(SRC)

clean_analyzer:
	rm -fv $(PLIST)
