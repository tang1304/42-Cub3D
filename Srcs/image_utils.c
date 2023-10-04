#include "../Incs/cub3D.h"

void	add_squares(t_coord_d coord, int num, t_img *img)
{
	int	i;
	int	j;
	int	s;

	s = SQUARE_SIZE;
	i = coord.y * s;
	while (i < (coord.y * s) + s)
	{
		j = coord.x * s;
		while (j < (coord.x * s) + s)
		{
			if (num == '1')
				my_mlx_pixel_put(img, i, j, 0x00C4C4C4); // wall
			else if (num == '0' || num == 69 || num == 78 || num == 83 \
					|| num == 87)
				my_mlx_pixel_put(img, i, j, 0x00FFFFFF); // floor
			else if (num == 32)
				my_mlx_pixel_put(img, i, j, 0xFF000000); // empty space
			j++;
		}
		i++;
	}
}
