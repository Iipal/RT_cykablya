#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "hit.h"
#endif

#include "material.h"
# include "cone_constructor.h"
# include "cylinder_constructor.h"
# include "tetrahedron_constructor.h"
# include "plane_constructor.h"

typedef short __attribute__((__ext_vector_type__(16),__aligned__(32)))	t_record_mask_hi;
typedef char __attribute__((__ext_vector_type__(32),__aligned__(32)))	t_record_mask_qi;

union	u_record_helper
{
	t_record_sf			sf;
	t_record_mask_qi	qi;
	t_record_mask_hi	hi;
} __attribute__((__aligned__(32)));

static inline _Bool __attribute__((__overloadable__,__target__("avx"),__const__))
	hit_condition(register const t_record_sf record)
{
	return ((_Bool)((t_record_mask_qi)record)[0]);
}

static inline float __attribute__((__overloadable__,__target__("avx"),__const__))
	hit_distance(register const t_record_sf record)
{
	return ((record)[1]);
}

t_record_sf __attribute__((__overloadable__,__target__("avx")))
	hit(register const union u_hitables * restrict hitables,
		register const t_ray_sf ray,
		register const float t_min,
		register const float t_max)
{
	register union u_record_helper	currect_record;
	register t_record_sf			return_candidate;
	register size_t					i;
	register float					closest_so_far;

	currect_record.sf = __extension__((typeof(currect_record.sf)){});
	return_candidate = __extension__((typeof(return_candidate)){});
	closest_so_far = t_max;
	i = ~0UL;
	while (++i < hitables->generic.count)
		if (hitables[i].generic.type == SPHERE)
		{
			currect_record.sf = hit(*(hitables[i].sphere.self),
					ray, t_min, closest_so_far, currect_record.sf);
			if (hit_condition(currect_record.sf)
			&& hit_distance(currect_record.sf) < closest_so_far)
			{
				closest_so_far = hit_distance(currect_record.sf);
				currect_record.qi[1] = (char)(type(*(hitables[i].sphere.material)));
				currect_record.hi[1] = (short)(i);
				return_candidate = currect_record.sf;
			}
		}
		else if (hitables[i].generic.type == CONE)
		{
			currect_record.sf = hit(*(hitables[i].cone.self),
					ray, t_min, closest_so_far, currect_record.sf);
			if (hit_condition(currect_record.sf)
			&& hit_distance(currect_record.sf) < closest_so_far)
			{
				closest_so_far = hit_distance(currect_record.sf);
				currect_record.qi[1] = (char)(type(*(hitables[i].cone.material)));
				currect_record.hi[1] = (short)(i);
				return_candidate = currect_record.sf;
			}
		}
		else if (hitables[i].generic.type == CYLINDER)
		{
			currect_record.sf = hit(*(hitables[i].cylinder.self),
					ray, t_min, closest_so_far, currect_record.sf);
			if (hit_condition(currect_record.sf)
			&& hit_distance(currect_record.sf) < closest_so_far)
			{
				closest_so_far = hit_distance(currect_record.sf);
				currect_record.qi[1] = (char)(type(*(hitables[i].cylinder.material)));
				currect_record.hi[1] = (short)(i);
				return_candidate = currect_record.sf;
			}
		}
		else if (hitables[i].generic.type == TETRAHEDRON)
		{
			currect_record.sf = hit(*(hitables[i].tetrahedron.self),
					ray, t_min, closest_so_far, currect_record.sf);
			if (hit_condition(currect_record.sf)
			&& hit_distance(currect_record.sf) < closest_so_far)
			{
				closest_so_far = hit_distance(currect_record.sf);
				currect_record.qi[1] = (char)(type(*(hitables[i].tetrahedron.material)));
				currect_record.hi[1] = (short)(i);
				return_candidate = currect_record.sf;
			}
		}
		else if (hitables[i].generic.type == PLANE)
		{
			currect_record.sf = hit(*(hitables[i].plane.self),
					ray, t_min, closest_so_far, currect_record.sf);
			if (hit_condition(currect_record.sf)
			&& hit_distance(currect_record.sf) < closest_so_far)
			{
				closest_so_far = hit_distance(currect_record.sf);
				currect_record.qi[1] = (char)(type(*(hitables[i].plane.material)));
				currect_record.hi[1] = (short)(i);
				return_candidate = currect_record.sf;
			}
		}
	return (return_candidate);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
