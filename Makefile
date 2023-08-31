# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 18:07:11 by ancolmen          #+#    #+#              #
#    Updated: 2023/02/25 17:07:13 by ancolmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######	VARIABLES

NAME		= so_long
LIBFT		= libft.a
MLX			= libmlx.a

LFT_PATH	= ./libft/
MLX_PATH	= ./mlx/
INC_PATH	= ./include
SRC_PATH	= ./src/

SRC			= ${SRC_PATH}main.c \
				${SRC_PATH}map_check.c \
				${SRC_PATH}path_check.c \
				${SRC_PATH}init.c \
				${SRC_PATH}init_anim.c \
				${SRC_PATH}utils.c \
				${SRC_PATH}start_game.c \
				${SRC_PATH}events.c \
				${SRC_PATH}render_fix.c \
				${SRC_PATH}render_p_anim.c \
				${SRC_PATH}render_e_anim.c \
				${SRC_PATH}render_utils.c \
				${SRC_PATH}free_anim.c \
				${SRC_PATH}free_and_exit.c

OBJ			= ${notdir ${SRC:.c=.o}}

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_CF 		= -lm -lbsd -lmlx -lXext -lX11
CFI 		= -I${INC_PATH}

LEAKS 		= valgrind ./so_long

LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \

RM			= rm -rf

#######	RULES

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT} ${MLX}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} -L ${LFT_PATH} -L ${MLX_PATH} -lft ${MLX_CF}

${OBJ}: ${SRC}
	${CC} ${CFLAGS} -g3 -c -I${INC_PATH} ${SRC}

$(MLX):
	@make -C ${MLX_PATH}

$(LIBFT):
	@make -C ${LFT_PATH}

bonus: all

leaks:
	${LEAKS} ${LF}

clean:
	@make clean -C ${LFT_PATH}
	@make clean -C ${MLX_PATH}
	${RM} ${OBJ}

fclean: clean
	@make fclean -C ${LFT_PATH}
	${RM} ${NAME}

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
