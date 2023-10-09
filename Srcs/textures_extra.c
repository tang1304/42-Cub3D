#include "../Incs/cub3D.h"

void	load_extra_textures(t_data *data, t_map *map)
{
	map->text[4].path = "./textures/door/door_wall.xpm";
	map->text[4].text = mlx_xpm_file_to_image(data->mlx, map->text[4].path, \
			&map->text[4].width, &map->text[4].height);
	if (!map->text[4].text)
		textures_error(data, "Error\nProblem charging xpm file to image\n");
	map->text[4].addr = mlx_get_data_addr(map->text[4].text, \
			&map->text[4].bpp, &map->text[4].line_l, &map->text[4].endian);
	if (!map->text[4].addr)
		textures_error(data, "Error\nProblem saving image address\n");

	map->text[5].path = "./textures/door/door.xpm";
	map->text[5].text = mlx_xpm_file_to_image(data->mlx, map->text[5].path, \
			&map->text[5].width, &map->text[5].height);
	if (!map->text[5].text)
		textures_error(data, "Error\nProblem charging xpm file to image\n");
	map->text[5].addr = mlx_get_data_addr(map->text[5].text, \
			&map->text[5].bpp, &map->text[5].line_l, &map->text[5].endian);
	if (!map->text[5].addr)
		textures_error(data, "Error\nProblem saving image address\n");
}
