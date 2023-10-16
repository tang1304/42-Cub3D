#include "../Incs/cub3D.h"

void	load_sprites(t_data *data)
{
	t_sprite	sprite;

	ft_bzero(&sprite, sizeof(t_sprite));
	sprite = new_sprite("necro", "./textures/necro.xpm", data);
	// data->sprite = &sprite;
}
