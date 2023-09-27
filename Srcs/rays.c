#include "../Incs/cub3D.h"

static double	calculate_len_sq_vector(t_data *data, t_coord_f hit)
{
	double	len;

	len = (hit.x - data->player.pos.x) * (hit.x - data->player.pos.x) + \
				(hit.y - data->player.pos.y) * (hit.y - data->player.pos.y);
	return (len);
}

static t_coord_f	get_dst_coord(t_coord_f pos, double angle, int dist)
{
	t_coord_f	dest;

	dest.x = dist * cos(-angle) + pos.x;
	dest.y = dist * sin(-angle) + pos.y;
	if (dest.x < SQUARE_SIZE)
		dest.x = SQUARE_SIZE;
	if (dest.x >= WIN_WIDTH)
		dest.x = WIN_WIDTH - SQUARE_SIZE;
	if (dest.y < SQUARE_SIZE)
		dest.y = SQUARE_SIZE;
	if (dest.y >= WIN_LEN)
		dest.y = WIN_LEN - SQUARE_SIZE;
// printf("x: %d y:%d\n", dest.x, dest.y);
	return (dest);
}

void	create_cone_multi_rays(t_data *data, t_coord_f left, t_coord_f right)
{
	t_coord_f	hit;
	double		inc;
	double		ang;
	int			i;

	inc = 1.0f / (RAY_NUMBER - 1.0f);
	i = 0;(void)left;
	while (i < RAY_NUMBER)
	{
		data->ray[i].hit_p.x = left.x * inc * i + (1 - (inc * i)) * right.x;
		data->ray[i].hit_p.y = left.y * inc * i + (1 - (inc * i)) * right.y;
		hit = init_data_collision(data, &data->ray[i]);
		if (hit.x != -1 && hit.y != -1)
		{
			data->ray[i].hit_p = hit;
			data->ray[i].len = calculate_len_sq_vector(data, hit);
		}
		else
		{
			data->ray[i].len = -1;
			ang = data->player.angle - data->fov / 2 + (data->fov / RAY_NUMBER) * i;
			data->ray[i].hit_p = get_dst_coord(data->player.pos, ang, VIEW_DIST);
		}
		create_line(data, data->ray[i].hit_p);
		i++;
	}
	// rays_render(data);
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	create_rays(t_data *data)
{
	int	opp_len;
	t_coord_f	left;
	t_coord_f	right;
	t_coord_f	position;

	position = get_dst_coord(data->player.pos, data->player.angle, VIEW_DIST);
	data->player.view_dst_pos.x = position.x;
	data->player.view_dst_pos.y = position.y;
	opp_len = tan(data->fov / 2) * VIEW_DIST;
	left = get_dst_coord(position, data->player.angle + M_PI / 2, opp_len);
	right = get_dst_coord(position, data->player.angle - M_PI / 2, opp_len);

draw_point(data, data->player.view_dst_pos.x, data->player.view_dst_pos.y, RED);
draw_point(data, left.x, left.y, GREEN);
draw_point(data, right.x, right.y, BLUE);
mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

	create_cone_multi_rays(data, left, right);
}
