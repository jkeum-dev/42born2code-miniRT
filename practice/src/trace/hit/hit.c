#include "trace.h"

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	/* To initialize the tmin and tmax values of temp_rec.	*/
	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

/*	hit_obj() is a gateway
	to connect with the hit() appropriate to the object type	*/
t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec);
	else if (world->type == PL)
		hit_result = hit_plane(world, ray, rec);
	else if (world->type == TR)
		hit_result = hit_triangle(world, ray, rec);
	else if (world->type == CY)
		hit_result = hit_cylinder(world, ray, rec);
	else if (world->type == SQ)
		hit_result = hit_square(world, ray, rec);
	return (hit_result);
}
