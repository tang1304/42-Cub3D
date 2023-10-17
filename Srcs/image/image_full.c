#include "../../Incs/cub3D.h"

void	crop_full_img(t_data *data, t_coord start, t_coord size, t_img *img)
{
	int			i;
	int			j;
	t_coord		coord;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			coord.x = i;
			coord.y = j;
			put_pixel_img(*img, coord, \
				get_pixel_img(data->full, start.x + i, start.y + j));
			j++;
		}
		i++;
	}
}

void	create_full_img(t_data *data)
{
	t_coord	coord;
	int		len;

	coord.x = -1;
	while (++coord.x < data->map.height)
	{
		len = ft_strlen(data->map.map[coord.x]);
		coord.y = -1;
		while (++coord.y < len)
			add_squares(coord, data->arr[coord.x][coord.y], &data->full);
	}
	create_rays(data);
}
