#include "../Incs/cub3D.h"

void	create_cone_multi_rays(t_data *data, t_coord_d left, t_coord_d right)
{
	double		inc;(void)inc;
	int			i;

	inc = 1.0f / (RAY_NUMBER - 1.0f);
	i = 0;
	while (i < RAY_NUMBER)
	{
		data->ray[i].hit_p.x = left.x - i * fabs(left.x - right.x) / RAY_NUMBER;
		data->ray[i].hit_p.y = left.x - i * fabs(left.y - right.y) / RAY_NUMBER;

		t_coord_f	test;
		test.x = data->ray[i].hit_p.x;
		test.y = data->ray[i].hit_p.y;
		create_line(data, test);
		i++;
	}
	// rays_render(data);
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static t_coord_d	determine_dst_coord(t_coord_f pos, double angle, int dist)
{
	t_coord_d	dest;

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

void	create_rays(t_data *data)
{
	int	opp_len;
	t_coord_d	left;
	t_coord_d	right;
	t_coord_f	position;

	data->player.view_dst_pos = determine_dst_coord(data->player.pos, data->player.angle, VIEW_DIST);
	opp_len = tan(data->fov / 2) * VIEW_DIST;
	position.x = data->player.view_dst_pos.x;
	position.y = data->player.view_dst_pos.y;
	left = determine_dst_coord(position, data->player.angle + M_PI / 2, opp_len);
	right = determine_dst_coord(position, data->player.angle - M_PI / 2, opp_len);
draw_point(data, data->player.view_dst_pos.x, data->player.view_dst_pos.y, RED);
draw_point(data, left.x, left.y, GREEN);
draw_point(data, right.x, right.y, BLUE);
mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

/*test*/
// data->ray[0].hit_p.x = data->player.view_dst_pos.x;
// 		data->ray[0].hit_p.y = data->player.view_dst_pos.y;
// create_line(data, &data->ray[0]);
	create_cone_multi_rays(data, right, left);


//test
// t_coord_f	test;
// test = init_data_collision(data, &data->ray[0]);
// // test.x = data->player.view_dst_pos.x;
// // test.y = data->player.view_dst_pos.y;
// 	create_line(data, test);//, &data->ray[i]);
// test.x = left.x;
// test.y = left.y;
// 	create_line(data, test);
// test.x = right.x;
// test.y = right.y;
// create_line(data, test);

}
