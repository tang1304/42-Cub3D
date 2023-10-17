#include "../../Incs/cub3D.h"

void	transparency_img(t_img *img, t_coord size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			my_mlx_pixel_put(img, x, y, TRANS);
			y++;
		}
		x++;
	}
}
