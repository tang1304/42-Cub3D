/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:12:29 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/16 12:02:22 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	get_texture_x(t_data *data, t_ray *ray, float scale)
{
	double		p_angle;
	double		hit_len;
	int			x_texture;
	t_coord_f	wall_hit;
	float		square_pos;

	p_angle = M_PI_2 - ray->angle + get_angle(data->player.pos, \
			vector_d_to_f(data->player.view_dst_pos));
	x_texture = 0;
	if (ray->side_hit == 1 || ray->side_hit == 2)
		hit_len = ray->correction * -scale * (SQUARE_SIZE / sin(p_angle));
	else
		hit_len = ray->correction * scale * (SQUARE_SIZE / sin(p_angle));
	wall_hit = calculate_vector(data->player.pos, ray->angle, hit_len);
	if (ray->side_hit == 1 || ray->side_hit == 2)
		square_pos = wall_hit.y - ((int)wall_hit.y / SQUARE_SIZE) * SQUARE_SIZE;
	else
		square_pos = wall_hit.x - ((int)wall_hit.x / SQUARE_SIZE) * SQUARE_SIZE;
	if (ray->side_hit == 1 || ray->side_hit == 4)
		square_pos /= SQUARE_SIZE;
	else
		square_pos = 1.0f - (square_pos / SQUARE_SIZE);
	if (!ray->wall_door && !ray->door)
		x_texture = square_pos * data->map.text[ray->side_hit - 1].width;
	else if (ray->wall_door)
		x_texture = square_pos * data->map.text[4].width;
	else if (ray->door)
		x_texture = square_pos * data->map.text[5].width;
	return (x_texture);
}

void	load_textures(t_data *data, t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		map->text[i].text = mlx_xpm_file_to_image(data->mlx, \
			map->text[i].path, &map->text[i].width, &map->text[i].height);
		if (!map->text[i].text)
			textures_error(data, "Error\nProblem changing xpm file to image\n");
		map->text[i].addr = mlx_get_data_addr(map->text[i].text, \
				&map->text[i].bpp, &map->text[i].line_l, &map->text[i].endian);
		if (!map->text[i].addr)
			textures_error(data, "Error\nProblem saving image address\n");
	}
	load_extra_textures(data, map);
}

static void	doors_texture_init()
{
	t_texture	wall_door;
	t_texture	door;

	ft_bzero(&wall_door, sizeof(t_texture));
	data->map.text[4] = wall_door;
	ft_bzero(&door, sizeof(t_texture));
	data->map.text[5] = door;
}

void	texture_init(t_data *data)
{
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;

	ft_bzero(&no, sizeof(t_texture));
	data->map.text[3] = no;
	ft_bzero(&so, sizeof(t_texture));
	data->map.text[2] = so;
	ft_bzero(&we, sizeof(t_texture));
	data->map.text[1] = we;
	ft_bzero(&ea, sizeof(t_texture));
	data->map.text[0] = ea;
}
