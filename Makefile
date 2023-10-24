# --- VARIABLES --- #

CC		=	cc -g3 -O2 #-fsanitize=address
CFLAGS	=	-Wall -Wextra -Werror

LSTS_SRCS		=	main.c

LSTS_SRCS_HK	=	hooks.c \
					hook_moves.c \
					hook_rotate.c

LSTS_SRCS_IMG	=	image.c \
					image_utils.c

LSTS_SRCS_INIT	=	init_array_map.c \
					init_data_struct.c

LSTS_SRCS_MAP	=	get_map.c \
					map_char_checks.c \
					map_init.c \
					map_parsing.c \
					map_utils.c

LSTS_SRCS_RAYS	=	collision.c \
					collision_utils.c \
					line.c \
					rays.c

LSTS_SRCS_TEXT	=	render.c \
					textures.c \
					textures_extra.c

LSTS_SRCS_U		=	errors.c \
					frees.c \
					utils.c \
					utils2.c \
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

LST_OBJS		=	$(LSTS_SRCS:.c=.o)
LST_OBJS_HK		=	$(LSTS_SRCS_HK:.c=.o)
LST_OBJS_IMG	=	$(LSTS_SRCS_IMG:.c=.o)
LST_OBJS_INIT	=	$(LSTS_SRCS_INIT:.c=.o)
LST_OBJS_MAP	=	$(LSTS_SRCS_MAP:.c=.o)
LST_OBJS_RAYS	=	$(LSTS_SRCS_RAYS:.c=.o)
LST_OBJS_TEXT	=	$(LSTS_SRCS_TEXT:.c=.o)
LST_OBJS_U		=	$(LSTS_SRCS_U:.c=.o)

OBJS			=	$(addprefix $(D_OBJS), $(LST_OBJS))
OBJS_HK			=	$(addprefix $(D_OBJS_HK), $(LST_OBJS_HK))
OBJS_IMG		=	$(addprefix $(D_OBJS_IMG), $(LST_OBJS_IMG))
OBJS_INIT		=	$(addprefix $(D_OBJS_INIT), $(LST_OBJS_INIT))
OBJS_MAP		=	$(addprefix $(D_OBJS_MAP), $(LST_OBJS_MAP))
OBJS_RAYS		=	$(addprefix $(D_OBJS_RAYS), $(LST_OBJS_RAYS))
OBJS_TEXT		=	$(addprefix $(D_OBJS_TEXT), $(LST_OBJS_TEXT))
OBJS_U			=	$(addprefix $(D_OBJS_U), $(LST_OBJS_U))

# BONUS FILES #
LSTS_SRCS_B			=	main_bonus.c

LSTS_SRCS_HK_B		=	hooks_bonus.c \
						hook_moves_bonus.c \
						hook_rotate_bonus.c \
						hook_others_bonus.c

LSTS_SRCS_IMG_B		=	image_bonus.c \
						image_minimap_bonus.c \
						image_bigmap_bonus.c \
						image_full_bonus.c \
						image_utils_bonus.c

LSTS_SRCS_INIT_B	=	init_array_map_bonus.c \
						init_data_struct_bonus.c

LSTS_SRCS_MAP_B		=	get_map_bonus.c \
						map_char_checks_bonus.c \
						map_init_bonus.c \
						map_parsing_bonus.c \
						map_utils_bonus.c \
						map_utils2_bonus.c

LSTS_SRCS_RAYS_B	=	collision_bonus.c \
						collision_door_bonus.c \
						collision_improved_doors_bonus.c \
						collision_improved_doors_utils_bonus.c \
						collision_utils_bonus.c \
						line_bonus.c \
						rays_bonus.c

LSTS_SRCS_TEXT_B	=	render_bonus.c \
						render_utils_bonus.c \
						textures_bonus.c \
						textures_extra_bonus.c

LSTS_SRCS_U_B		=	errors_bonus.c \
						frees_bonus.c \
						utils_bonus.c \
						utils2_bonus.c \
						vector_utils_bonus.c \
						window_bonus.c

LSTS_SRCS_RAYS_B	=	init_animations_bonus.c

D_SRCS_B		=	Srcs_bonus/
D_SRCS_HK_B		=	Srcs_bonus/hooks/
D_SRCS_IMG_B	=	Srcs_bonus/image/
D_SRCS_INIT_B	=	Srcs_bonus/init/
D_SRCS_MAP_B	=	Srcs_bonus/map/
D_SRCS_RAYS_B	=	Srcs_bonus/rays/
D_SRCS_TEXT_B	=	Srcs_bonus/textures/
D_SRCS_U_B		=	Srcs_bonus/utils/
D_SRCS_S_B		=	Srcs_bonus/sprites/

D_OBJS_B		=	objs_bonus/
D_OBJS_HK_B		=	objs_bonus/hooks/
D_OBJS_IMG_B	=	objs_bonus/image/
D_OBJS_INIT_B	=	objs_bonus/init/
D_OBJS_MAP_B	=	objs_bonus/map/
D_OBJS_RAYS_B	=	objs_bonus/rays/
D_OBJS_TEXT_B	=	objs_bonus/textures/
D_OBJS_U_B		=	objs_bonus/utils/
D_OBJS_S_B		=	objs_bonus/sprites/

LST_OBJS_B		=	$(LSTS_SRCS_B:.c=.o)
LST_OBJS_HK_B	=	$(LSTS_SRCS_HK_B:.c=.o)
LST_OBJS_IMG_B	=	$(LSTS_SRCS_IMG_B:.c=.o)
LST_OBJS_INIT_B	=	$(LSTS_SRCS_INIT_B:.c=.o)
LST_OBJS_MAP_B	=	$(LSTS_SRCS_MAP_B:.c=.o)
LST_OBJS_RAYS_B	=	$(LSTS_SRCS_RAYS_B:.c=.o)
LST_OBJS_TEXT_B	=	$(LSTS_SRCS_TEXT_B:.c=.o)
LST_OBJS_U_B	=	$(LSTS_SRCS_U_B:.c=.o)
LST_OBJS_S_B	=	$(LSTS_SRCS_S_B:.c=.o)

OBJS_B			=	$(addprefix $(D_OBJS_B), $(LST_OBJS_B))
OBJS_HK_B		=	$(addprefix $(D_OBJS_HK_B), $(LST_OBJS_HK_B))
OBJS_IMG_B		=	$(addprefix $(D_OBJS_IMG_B), $(LST_OBJS_IMG_B))
OBJS_INIT_B		=	$(addprefix $(D_OBJS_INIT_B), $(LST_OBJS_INIT_B))
OBJS_MAP_B		=	$(addprefix $(D_OBJS_MAP_B), $(LST_OBJS_MAP_B))
OBJS_RAYS_B		=	$(addprefix $(D_OBJS_RAYS_B), $(LST_OBJS_RAYS_B))
OBJS_TEXT_B		=	$(addprefix $(D_OBJS_TEXT_B), $(LST_OBJS_TEXT_B))
OBJS_U_B		=	$(addprefix $(D_OBJS_U_B), $(LST_OBJS_U_B))
OBJS_S_B		=	$(addprefix $(D_OBJS_S_B), $(LST_OBJS_S_B))

NAME		=	cub3D
NAME_B		=	cub3D_bonus
RM			=	rm -rf

HEADER		=	cub3D.h general.h struct.h
D_HEADER	=	Incs/
INCS		=	$(addprefix $(D_HEADER), $(HEADER))

HEADER_B	=	cub3D_bonus.h general_bonus.h struct_bonus.h
D_HEADER_B	=	Incs_bonus/
INCS_B		=	$(addprefix $(D_HEADER_B), $(HEADER_B))

LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft/
MLX_DIR		=	mlx/
MLX_A		=	${MLX_DIR}libmlx.a
MLX_FLAGS	=	-lm -L/usr/lib -lXext -lX11

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

${D_OBJS}%.o		:	${D_SRCS}%.c ${INCS} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER} -c $< -o $@

${D_OBJS_HK}%.o		:	${D_SRCS_HK}%.c ${INCS} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_HK}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER} -c $< -o $@

${D_OBJS_IMG}%.o	:	${D_SRCS_IMG}%.c ${INCS} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_IMG}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER} -c $< -o $@

${D_OBJS_INIT}%.o	:	${D_SRCS_INIT}%.c ${INCS} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_INIT}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER} -c $< -o $@

${D_OBJS_MAP}%.o	:	${D_SRCS_MAP}%.c ${INCS} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_MAP}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER} -c $< -o $@

${D_OBJS_RAYS}%.o	:	${D_SRCS_RAYS}%.c ${INCS} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_RAYS}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER} -c $< -o $@

${D_OBJS_TEXT}%.o	:	${D_SRCS_TEXT}%.c ${INCS} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_TEXT}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER} -c $< -o $@

${D_OBJS_U}%.o		:	${D_SRCS_U}%.c ${INCS} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_U}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER} -c $< -o $@

bonus	:	lib ${OBJS_B} ${OBJS_HK_B} ${OBJS_IMG_B} ${OBJS_INIT_B} ${OBJS_MAP_B} ${OBJS_RAYS_B} ${OBJS_TEXT_B} ${OBJS_U_B} ${OBJS_S_B}
			${CC} ${CFLAGS} ${OBJS_B} ${OBJS_HK_B} ${OBJS_IMG_B} ${OBJS_INIT_B} ${OBJS_MAP_B} ${OBJS_RAYS_B} ${OBJS_TEXT_B} ${OBJS_U_B} ${OBJS_S_B} ${LIBFT} ${MLX_A} ${MLX_FLAGS} -o ${NAME_B}
			@echo "${_GREEN}### ${NAME_B} created ###${_NOC}\n"

${D_OBJS_B}%.o		:	${D_SRCS_B}%.c ${INCS_B} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_B}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER_B} -c $< -o $@

${D_OBJS_HK_B}%.o	:	${D_SRCS_HK_B}%.c ${INCS_B} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_HK_B}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER_B} -c $< -o $@

${D_OBJS_IMG_B}%.o	:	${D_SRCS_IMG_B}%.c ${INCS_B} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_IMG_B}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER_B} -c $< -o $@

${D_OBJS_INIT_B}%.o	:	${D_SRCS_INIT_B}%.c ${INCS_B} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_INIT_B}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER_B} -c $< -o $@

${D_OBJS_MAP_B}%.o	:	${D_SRCS_MAP_B}%.c ${INCS_B} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_MAP_B}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER_B} -c $< -o $@

${D_OBJS_RAYS_B}%.o	:	${D_SRCS_RAYS_B}%.c ${INCS_B} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_RAYS_B}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER_B} -c $< -o $@

${D_OBJS_TEXT_B}%.o	:	${D_SRCS_TEXT_B}%.c ${INCS_B} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_TEXT_B}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER_B} -c $< -o $@

${D_OBJS_U_B}%.o	:	${D_SRCS_U_B}%.c ${INCS_B} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_U_B}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER_B} -c $< -o $@

${D_OBJS_S_B}%.o	:	${D_SRCS_S_B}%.c ${INCS_B} ${LIBFT} ${MLX_A}
						@mkdir -p ${D_OBJS_S_B}
						${CC} ${CFLAGS} -I/usr/include -I ${MLX_DIR} -I ${D_HEADER_B} -c $< -o $@

clean	:
			@${MAKE} clean -C ${LIBFT_DIR}
			@${MAKE} clean -C ${MLX_DIR}
			$(RM) $(D_OBJS) $(D_OBJS_B)
			@echo "${_RED}### Removed ${NAME} object files ###${_NOC}"

fclean	:
			$(MAKE) clean
			@${MAKE} fclean -C ${LIBFT_DIR}
			${RM} ${NAME} ${NAME_B}
			@echo "${_RED}### Removed ${NAME} ###${_NOC}"

re		:	fclean all

.PHONY	:	all clean fclean re FORCE bonus
