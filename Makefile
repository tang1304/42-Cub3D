# --- VARIABLES --- #

CC = cc -g3
CFLAGS = -Wall -Wextra -Werror
SRCS = 
SRCS_DIR = ./Srcs/
OBJ_DIR = objs/
NAME = cub3D
RM = rm -fclean
HEADER = Incs/cub3D.h
LIBFT = libft/libft.a
LIBFT_DIR = libft/
MLX_DIR	=	mlx/
MLX_A	=	${MLX_DIR}libmlx.a
MLX_FLAGS = -lm -L/usr/lib -lXext -lX11

# --- COLORS --- #

_NOC	:=	\033[0m
_RED	:=	\033[1;31m
_GREEN	:=	\033[1;32m

# --- RULES --- #

${NAME} :	${OBJ} ${LIBFT} ${MLX_A}
		${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${MLX_A} ${MLX_FLAGS} -o ${NAME}
		@echo "${_GREEN}### ${NAME} created ###${_NOC}\n"

${OBJ}: ${OBJ_DIR}%.o :	${SRCS_DIR}%.c ${HEADER} ${LIBFT} ${MLX_A}
		@mkdir -p objs
		${CC} ${CFLAGS} -I/usr/include -I${MLX_DIR} -c $< -o $@

${LIBFT}: FORCE
		${MAKE} -sC ${LIBFT_DIR}

${MLX_A}: FORCE
		@${MAKE} -sC ${MLX_DIR}

FORCE:

all :	${NAME}

clean :
		@${MAKE} clean -sC ${LIBFT_DIR}
		@${MAKE} clean -sC ${MLX_DIR}
		rm -rf objs/
		@echo "${_RED}### Removed ${NAME} object files ###${_NOC}"

fclean :	clean
		@${MAKE} fclean -sC ${LIBFT_DIR}
		${RM} ${NAME} ${NAME_BONUS}
		@echo "${_RED}### Removed ${NAME} ###${_NOC}"

re : 	fclean all

.PHONY : all clean fclean re FORCE bonus
