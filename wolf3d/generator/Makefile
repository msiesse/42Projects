# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiesse <msiesse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 22:26:21 by msiesse           #+#    #+#              #
#    Updated: 2019/08/27 15:09:46 by msiesse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/
SRC_NAME = main.c\
		   get_data.c\
		   printing.c\
		   get_data_2.c\
		   create_map.c\
		   create_map_2.c

OBJ_PATH = objs/
INC_PATH = includes/
INC_NAME = gen.h

LIB_PATH = ../libft
PRINTF_PATH = ../libft/ft_printf
CPPFLAGS = -I$(INC_PATH) -I$(LIB_PATH) -I$(PRINTF_PATH)
LDLIBS = -L$(LIB_PATH) -lft
NAME = gen_map
CC = clang
CFLAGS = -Wall -Werror -Wextra -O2 -ffreestanding -fno-builtin
GCOV = -fprofile-arcs -ftest-coverage #--coverage
OBJ_NAME = $(SRC_NAME:.c=.o)
PLIST= $(SRC_NAME:.c=.plist)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

.PHONY: all, clean, fclean, re, norme, cleanlib, analyzer

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

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
	$(CC) $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) $(GCOV) $^ -o $(NAME)

clean_gcov:
	rm -fv *.gcov *.gcda *.gcno

re_gcov: clean_gcov fclean gcov_debug

norme:
	norminette $(SRC)
	norminette $(INC)

cleanlib:
	@make -C $(LIB_PATH) fclean

analyzer:
	$(CC) -fsyntax-only $(CFLAGS) $(CPPFLAGS) $(SRC)
	$(CC) --analyze $(CFLAGS) $(CPPFLAGS) $(SRC)

clean_analyzer:
	rm -fv $(PLIST)
