/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:12:29 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/27 09:04:02 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

int	get_rgb(int *color)
{
	return (1 | color[0] << 16 | color[1] << 8 | color[2]);
}

int	get_texture_x(t_data *data, t_ray *ray, float scale)
{
	double		p_angle;
	double		hit_len;
	int			x_texture;
	t_coord_f	wall_hit;
	float		square_pos;

	p_angle = M_PI_2 - ray->angle + get_angle(data->player.pos, \
			vector_d_to_f(data->player.view_dst_pos));
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
	x_texture = square_pos * data->map.text[ray->side_hit - 1].width;
	return (x_texture);
}

int	get_pixel_from_texture(t_texture *text, int x, int y)
{
	int		color;

	if (x < 0 || x >= text->width)
		return (0);
	if (y < 0 || y >= text->height)
		return (0);
	color = (*(int *)(text->addr + (x * text->bpp / 8) + (y * text->line_l)));
	if (color == BLACK)
		color = LICORICE;
	return (color);
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
			textures_error(data, XPM_OPEN_ERR);
		map->text[i].addr = mlx_get_data_addr(map->text[i].text, \
				&map->text[i].bpp, &map->text[i].line_l, &map->text[i].endian);
		if (!map->text[i].addr)
			textures_error(data, "Error\nProblem saving image address\n");
	}
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
