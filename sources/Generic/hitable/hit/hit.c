#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "hit.h"
#endif

# include "material.h"

static inline _Bool __attribute__((CONST,CLONE,ARCH))
	hit_condition(register const t_record_sf record)
{
	return ((_Bool)((t_record_mask_qi)record)[0]);
}

static inline float __attribute__((CONST,CLONE,ARCH))
	hit_distance(register const t_record_sf record)
{
	return ((record)[1]);
}



struct	s_hlp
{
	const union u_hitables	*restrict	hitables;
	const union u_record_helper			prev_record;
	const t_ray_sf						ray;
	const t_v2sf						time;
	const size_t						i;
};

static t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit_sphere(const struct s_hlp s)
{
	register union u_record_helper	currect_record;

	currect_record.sf = hit(*(s.hitables[s.i].sphere.self),
		s.ray, s.time, s.prev_record.sf);
	if (hit_condition(currect_record.sf)
	&& hit_distance(currect_record.sf) < s.time.y)
	{
		currect_record.qi[1] =
		(char)(type(*(s.hitables[s.i].sphere.material)));
		currect_record.hi[1] = (short)(s.i);
	}
	return (currect_record.sf);
}







t_record_sf __attribute__((CONST,CLONE,ARCH))
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
		if ((hitables[i].generic.type == SPHERE) && (hit_condition(currect_record.sf = hit_sphere((const struct s_hlp){
		hitables, currect_record, ray, vec(t_min, closest_so_far), i }))))
			return_candidate = currect_record.sf;


		else if (hitables[i].generic.type == CONE)
		{
			currect_record.sf = hit(*(hitables[i].cone.self),
					ray, vec(t_min, closest_so_far), currect_record.sf);
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
					ray, vec(t_min, closest_so_far), currect_record.sf);
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
					ray, vec(t_min, closest_so_far), currect_record.sf);
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
					ray, vec(t_min, closest_so_far), currect_record.sf);
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
