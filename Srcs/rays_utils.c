#include "../Incs/cub3D.h"

t_coord_f	calculate_hit_mini(t_ray *ray)
{
	t_coord_f	hit;

	hit.x = ray->hit_p.x / 2;
	hit.y = ray->hit_p.y / 2;
	return (hit);
}
