# --- VARIABLES --- #

CC = cc -g3
CFLAGS = -Wall -Wextra -Werror# -fsanitize=address
SRCS =	close.c \
		errors.c \
		frees.c \
		get_map.c \
		key_hook.c \
		main.c \
		map_char_checks.c \
		map_init.c \
		map_parsing.c \
		map_utils.c \
		textures.c \
		utils.c
SRCS_DIR = ./Srcs/
OBJ	=	$(SRCS:.c=.o)
OBJ_DIR = objs/
OBJS	=	$(addprefix $(OBJ_DIR), $(OBJ))
NAME = cub3D
RM = rm -rf
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

all		:	lib $(NAME)

lib :
		$(MAKE) -C ${LIBFT_DIR}
		$(MAKE) -C ${MLX_DIR}

${NAME} :	${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLX_A} ${MLX_FLAGS} -o ${NAME}
		@echo "${_GREEN}### ${NAME} created ###${_NOC}\n"

${OBJ_DIR}%.o :	${SRCS_DIR}%.c ${HEADER} ${LIBFT} ${MLX_A}
		@mkdir -p objs/
		${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -c $< -o $@

clean :
		@${MAKE} clean -C ${LIBFT_DIR}
		@${MAKE} clean -C ${MLX_DIR}
		$(RM) objs/
		@echo "${_RED}### Removed ${NAME} object files ###${_NOC}"

fclean :
		$(MAKE) clean
		@${MAKE} fclean -C ${LIBFT_DIR}
		${RM} ${NAME} ${NAME_BONUS}
		@echo "${_RED}### Removed ${NAME} ###${_NOC}"

re : 	fclean all

.PHONY : all clean fclean re bonus