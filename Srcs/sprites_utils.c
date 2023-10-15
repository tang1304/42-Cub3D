#include "../Incs/cub3D.h"

t_sprite	new_sprite(char *name, char *file_path, t_data *data)
{
	t_sprite	sprite;

	data->test.img = mlx_new_image(data->mlx, 100, 100);
	if (data->test.img == NULL)
		exit_cub_error(data, "Error\nProblem changing xpm file to image\n");
	data->test.addr = mlx_get_data_addr(data->test.img, &data->test.bpp, \
						&data->test.line_l, &data->test.endian);
	sprite.name = ft_strdup(name);
	sprite.file_path = ft_strdup(file_path);
	sprite.sprite_img = img;
	sprite.width = img.w;
	sprite.height = img.h;
	sprite.z_index = 0;
	return (sprite);
}
