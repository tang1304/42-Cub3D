#include "../Incs/cub3D.h"

void	add_player_arrow(t_data *data, t_coord_d p)
{
	//for now just a square
	t_coord_d	player;(void)p;

	player.x = data->player.pos.x / MINI_SQ_SIZE;
	player.y = data->player.pos.y / MINI_SQ_SIZE;
	draw_point(data, player.x, player.y, BLUE);
}
