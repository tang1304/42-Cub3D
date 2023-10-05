#include "../Incs/cub3D.h"

double	vector_d_len_sq(t_coord center, t_coord map)
{
	float	value_sq;

	value_sq = (center.x - map.x) * (center.x - map.x) + \
			(center.y - map.y) * (center.y - map.y);
	return (value_sq);

}

float	calculate_len_vector(t_data *data, t_coord_f hit)
{
	float	len;

	len = (hit.x - data->player.pos.x) * (hit.x - data->player.pos.x) + \
				(hit.y - data->player.pos.y) * (hit.y - data->player.pos.y);
	return (len);
}
