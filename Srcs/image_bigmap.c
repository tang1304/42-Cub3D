#include "../Incs/cub3D.h"

void	init_bigmap_img(t_data *data)
{
	t_img	big;

	if (data->mini.width > 520)
		big.w = 520;
	else
		big.w = data->mini.width;
	if (data->mini.height > 200)
		big.h = 200;
	else
		big.h = data->mini.height;
	big.img = mlx_new_image(data->mlx, big.w, big.h);
	big.addr = mlx_get_data_addr(big.img, &big.bpp, \
					&big.line_l, &big.endian);
	data->bigmap = big;
}