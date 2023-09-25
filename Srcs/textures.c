/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:25:07 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/25 16:03:05 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static double	get_angle(t_coord_f start, t_coord_f dest)
{
	double	delta_x;
	double	delta_y;

	delta_x = (double)(dest.x - start.x);
	delta_y = (double)(dest.y - start.y);
	if (delta_x < 0 && delta_y < 0)
		return (atan(delta_x / delta_y) + M_PI / 2);
	else if (delta_x < 0 && delta_y > 0)
		return (atan(-delta_y / delta_x) + M_PI);
	else if (delta_x >= 0 && delta_y < 0)
		return (atan(-delta_y / delta_x));
	else
		return (atan (delta_x / delta_y) + M_PI + M_PI_2);
}

int	get_texture_x(t_data *data, t_ray *ray)
{
	double	p_angle;
	double	hit_len;

	p_angle = M_PI_2 - ray->angle + get_angle(data->player.pos, data->player.);
}

int	get_pixel_from_texture(t_texture *text, int x, int y, double ratio)
{
	int		color;
	(void)ratio;

	if (x < 0 || x >= text->width)
		return (0);
	if (y < 0 || y >= text->height)
		return (0);
	color = (*(int *)text->addr + (y * text->line_l) + (x * text->bpp / 8));
	return (color);
}

void	load_textures(t_data *data, t_map *map)
{
printf("path:%s\n", map->text[3].path);
	map->text[3].text = mlx_xpm_file_to_image(data->mlx, map->text[3].path, \
						&map->text[3].width, &map->text[3].height);
	map->text[3].addr = mlx_get_data_addr(map->text[3].text, &map->text[3].bpp \
						, &map->text[3].line_l, &map->text[3].endian);
	map->text[2].text = mlx_xpm_file_to_image(data->mlx, map->text[2].path, \
						&map->text[2].width, &map->text[2].height);
	map->text[2].addr = mlx_get_data_addr(map->text[2].text, &map->text[2].bpp \
						, &map->text[2].line_l, &map->text[2].endian);
	map->text[1].text = mlx_xpm_file_to_image(data->mlx, map->text[1].path, \
						&map->text[1].width, &map->text[1].height);
	map->text[1].addr = mlx_get_data_addr(map->text[1].text, &map->text[1].bpp \
						, &map->text[1].line_l, &map->text[1].endian);
	map->text[0].text = mlx_xpm_file_to_image(data->mlx, map->text[0].path, \
						&map->text[0].width, &map->text[0].height);
	map->text[0].addr = mlx_get_data_addr(map->text[0].text, &map->text[0].bpp \
						, &map->text[0].line_l, &map->text[0].endian);
}
