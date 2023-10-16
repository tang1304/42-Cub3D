#include "../Incs/cub3D.h"

t_sprite	new_sprite(char *name, char *file_path, t_data *data)
{
	t_sprite	sprite;

	ft_bzero(&sprite, sizeof(t_sprite));
	data->torch.img = mlx_xpm_file_to_image(data->mlx, file_path, &data->torch.w, &data->torch.h);
	if (data->torch.img == NULL)
		exit_cub_error(data, "Error\nProblem changing xpm file to image\n");
	mlx_xpm_file_to_image(data->mlx, file_path, &data->torch.w, &data->torch.h);
	// data->torch.w = 2720;
	// data->torch.h = 896;
	data->torch.addr = mlx_get_data_addr(data->torch.img, &data->torch.bpp, \
						&data->torch.line_l, &data->torch.endian);
	data->sprite.name = ft_strdup(name);//free
	data->sprite.file_path = ft_strdup(file_path);//free
	data->sprite.sprite_img = data->torch;
	data->sprite.width = data->torch.w;
	data->sprite.height = data->torch.h;
	data->sprite.z_index = 0;
	t_coord	coord;
	coord.x = 150;
	coord.y = 150;
	put_pixel_img(data->torch, coord, 0x00FFFFFF);
	// mlx_put_image_to_window (data->mlx, data->win, data->torch.img, 0, 0);
	// mlx_put_image_to_window (data->mlx, data->win, data->torch.img, 0, 0);
	return (sprite);
}
