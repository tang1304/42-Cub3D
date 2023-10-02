/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:12:29 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/02 14:53:43 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	get_texture_x(t_data *data, t_ray *ray)
{
	double		p_angle;
	double		hit_len;
	int			x_texture;
	t_coord_f	wall_hit;
	float		square_pos;

	p_angle = M_PI_2 - ray->angle + get_angle(data->player.pos, \
			vector_d_to_f(data->player.view_dst_pos));
// printf("ray_angle:%f\n", ray->angle / (M_PI/180));
// printf("p_angle:%f\n", p_angle / (M_PI/180));
	hit_len = ray->correction * 0.5f * SQUARE_SIZE / sin(p_angle);
	wall_hit = calculate_vector(data->player.pos, ray->angle, hit_len);
// printf("wall_hit_x: %f\n", wall_hit.x);
// printf("wall_hit_y: %f\n", wall_hit.y);
	if (ray->side_hit == 1 || ray->side_hit == 2)
		square_pos = wall_hit.y - ((int)wall_hit.y / SQUARE_SIZE) * SQUARE_SIZE;
	else
		square_pos = wall_hit.x - ((int)wall_hit.x / SQUARE_SIZE) * SQUARE_SIZE;
	if (ray->side_hit == 1 || ray->side_hit == 4)
		square_pos /= SQUARE_SIZE;
	else
		square_pos = 1.0f - square_pos / SQUARE_SIZE;
	x_texture = square_pos * data->map.text[ray->side_hit - 1].width;
	return (x_texture);
}

int	get_pixel_from_texture(t_texture *text, int x, int y)
{
	int		color;

	if (x < 0 || x >= text->width)
		return (0);
	if (y < 0 || y >= text->height)// always return here
		return (0);
	color = (*(int *)(text->addr + (y * text->line_l) + (x * text->bpp / 8)));
	return (color);
}

void	load_textures(t_data *data, t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		map->text[i].text = mlx_xpm_file_to_image(data->mlx, map->text[i].path, \
				&map->text[i].width, &map->text[i].height);
		if (!map->text[i].text)
			textures_error(data, "Error\nProblem changing xpm file to image\n");
		map->text[i].addr = mlx_get_data_addr(map->text[i].text, \
				&map->text[i].bpp, &map->text[i].line_l, &map->text[i].endian);
		if (!map->text[i].addr)
			textures_error(data, "Error\nProblem saving image address\n");
		// mlx_destroy_image(data->mlx, map->text[i].text);
	}
}
