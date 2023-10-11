#include "../Incs/cub3D.h"

void	map_zoom(t_data *data, int keycode)
{
	if (keycode == PLUS && !data->player.zoom_in)
	{
		data->player.zoom_in = 1;
		data->player.zoom_out = 0;
	}
	if (keycode == MINUS && !data->player.zoom_out)
	{
		data->player.zoom_in = 0;
		data->player.zoom_out = 1;
	}
	create_full_img(data);
	create_rays(data);
}

void	change_board(t_data *data, int keycode)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	x /= SQUARE_SIZE;
	y /= SQUARE_SIZE;
	if (x < 0 || y < 0 || x > data->mini.width || y > data->mini.height)
		return ;
	if (keycode == Z)
		data->arr[y][x] = '0';
	else if (keycode == X)
		data->arr[y][x] = '1';
	// create_minimap_img(data);
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static void	update_infos(int *action, t_coord *change, t_ray ray, int i)
{
	*action = i;
	(*change).x = ray.cell.y;
	(*change).y = ray.cell.x;
	if (i == 0)
	{
		if (ray.side_hit == 1)
			(*change).y--;
		if (ray.side_hit == 2)
			(*change).y++;
		if (ray.side_hit == 3)
			(*change).x--;
		if (ray.side_hit == 4)
			(*change).x++;
	}
}

static int	check_bug(t_data *data, t_coord change)
{
	t_coord	player;

	player.y = data->player.pos.x / SQUARE_SIZE;
	player.x = data->player.pos.y / SQUARE_SIZE;
	if (player.x == change.x && player.y == change.y)
		return (1);
	return (0);
}

void	open_close_doors(t_data *data)
{
	int		i;
	int		action;
	t_coord	change;

	i = -1;
	action = 0;
	change.x = -1;
	change.y = -1;
	while (++i < RAY_NUMBER)
	{
		if (data->arr[data->ray[i].cell.y][data->ray[i].cell.x] == 'D' && \
			data->ray[i].len <= DOOR_OPEN_DST && action == 0)
			update_infos(&action, &change, data->ray[i], 1);
		else if (data->ray[i].wall_door == 1 && \
			data->ray[i].len <= DOOR_CLOSE_DST && action == 0)
			update_infos(&action, &change, data->ray[i], 0);
	}
	if (action == 1)
		data->arr[change.x][change.y] = 'O';
	else if (action == 0 && change.x != -1 && \
		data->arr[change.x][change.y] == 'O' && !check_bug(data, change))
		data->arr[change.x][change.y] = 'D';
	create_full_img(data);
	create_rays(data);
}
