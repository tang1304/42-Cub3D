# --- VARIABLES --- #

CC		=	cc -g3 -O2 #-fsanitize=address
CFLAGS	=	-Wall -Wextra -Werror
LSTS_SRCS		=	main.c

LSTS_SRCS_HK	=	hooks.c \
					hook_moves.c \
					hook_rotate.c \
					hook_others.c

LSTS_SRCS_IMG	=	image.c \
					image_minimap.c \
					image_bigmap.c \
					image_full.c \
					image_utils.c

LSTS_SRCS_INIT	=	init_array_map.c \
					init_data_struct.c

LSTS_SRCS_MAP	=	get_map.c \
					map_char_checks.c \
					map_init.c \
					map_parsing.c \
					map_utils.c \
					map_utils2.c

LSTS_SRCS_RAYS	=	collision.c \
					line.c \
					line_utils.c \
					rays.c

LSTS_SRCS_TEXT	=	render.c \
					textures.c \
					textures_extra.c

LSTS_SRCS_U		=	errors.c \
					frees.c \
					utils.c \
					vector_utils.c \
					window.c

D_SRCS			=	Srcs/
D_SRCS_HK		=	Srcs/hooks/
D_SRCS_IMG		=	Srcs/image/
D_SRCS_INIT		=	Srcs/init/
D_SRCS_MAP		=	Srcs/map/
D_SRCS_RAYS		=	Srcs/rays/
D_SRCS_TEXT		=	Srcs/textures/
D_SRCS_U		=	Srcs/utils/

D_OBJS			=	objs/
D_OBJS_HK		=	objs/hooks/
D_OBJS_IMG		=	objs/image/
D_OBJS_INIT		=	objs/init/
D_OBJS_MAP		=	objs/map/
D_OBJS_RAYS		=	objs/rays/
D_OBJS_TEXT		=	objs/textures/
D_OBJS_U		=	objs/utils/

LST_OBJS		=	$(LST_SRCS:.c=.o)
LST_OBJS_HK		=	$(LST_SRCS_HK:.c=.o)
LST_OBJS_IMG	=	$(LST_SRCS_IMG:.c=.o)
LST_OBJS_INIT	=	$(LST_SRCS_INIT.c=.o)
LST_OBJS_MAP	=	$(LST_SRCS_MAP.c=.o)
LST_OBJS_RAYS	=	$(LST_SRCS_RAYS.c=.o)
LST_OBJS_TEXT	=	$(LST_SRCS_TEXT.c=.o)
LST_OBJS_U		=	$(LST_SRCS_U:.c=.o)

OBJS			=	$(addprefix $(D_OBJS), $(LST_OBJS))
OBJS_HK			=	$(addprefix $(D_OBJS_HK), $(LST_OBJS_HK))
OBJS_IMG		=	$(addprefix $(D_OBJS_IMG), $(LST_OBJS_IMG))
OBJS_INIT		=	$(addprefix $(D_OBJS_INIT), $(LST_OBJS_INIT))
OBJS_MAP		=	$(addprefix $(D_OBJS_MAP), $(LST_OBJS_MAP))
OBJS_RAYS		=	$(addprefix $(D_OBJS_RAYS), $(LST_OBJS_RAYS))
OBJS_TEXT		=	$(addprefix $(D_OBJS_TEXT), $(LST_OBJS_TEXT))
OBJS_U			=	$(addprefix $(D_OBJS_U), $(LST_OBJS_U))

NAME = cub3D
RM = rm -rf
HEADER = Incs/cub3D.h Incs/general.h Incs/struct.h
D_HEADER = Incs/
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

${NAME}	:	${OBJS} ${OBJS_HK} ${OBJS_IMG} ${OBJS_INIT} ${OBJS_MAP} ${OBJS_RAYS} ${OBJS_TEXT} ${OBJS_U}
			${CC} ${CFLAGS} ${OBJS} ${OBJS_HK} ${OBJS_IMG} ${OBJS_INIT} ${OBJS_MAP} ${OBJS_RAYS} ${OBJS_TEXT} ${OBJS_U} ${LIBFT} ${MLX_A} ${MLX_FLAGS} -o ${NAME}
			@echo "${_GREEN}### ${NAME} created ###${_NOC}\n"

${D_OBJS}%.o		:	${D_SRCS}%.c ${D_HEADER} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I$(D_HEADER) -c $< -o $@

${D_OBJS_HK}%.o		:	${D_SRCS_HK}%.c ${D_HEADER} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_HK}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I$(D_HEADER) -c $< -o $@

${D_OBJS_IMG}%.o	:	${D_SRCS_IMG}%.c ${D_HEADER} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_IMG}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I$(D_HEADER) -c $< -o $@

${D_OBJS_INIT}%.o	:	${D_SRCS_INIT}%.c ${D_HEADER} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_INIT}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I$(D_HEADER) -c $< -o $@

${D_OBJS_MAP}%.o	:	${D_SRCS_MAP}%.c ${D_HEADER} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_MAP}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I$(D_HEADER) -c $< -o $@

${D_OBJS_RAYS}%.o	:	${D_SRCS_RAYS}%.c ${D_HEADER} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_RAYS}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I$(D_HEADER) -c $< -o $@

${D_OBJS_TEXT}%.o	:	${D_SRCS_TEXT}%.c ${D_HEADER} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_TEXT}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I$(D_HEADER) -c $< -o $@

${D_OBJS_U}%.o		:	${D_SRCS_U}%.c ${D_HEADER} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_U}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I$(D_HEADER) -c $< -o $@
clean :
		@${MAKE} clean -C ${LIBFT_DIR}
		@${MAKE} clean -C ${MLX_DIR}
		$(RM) $(D_OBJS)
		@echo "${_RED}### Removed ${NAME} object files ###${_NOC}"

fclean :
		$(MAKE) clean
		@${MAKE} fclean -C ${LIBFT_DIR}
		${RM} ${NAME} ${NAME_BONUS}
		@echo "${_RED}### Removed ${NAME} ###${_NOC}"

re : 	fclean all

.PHONY : all clean fclean re FORCE bonus
