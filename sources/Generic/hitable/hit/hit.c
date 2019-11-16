/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 01:08:03 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 01:08:07 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "hit.h"
#endif

static inline _Bool __attribute__((CONST,CLONE,ARCH))
	hit_condition(register const t_record_sf record)
{
	return (!!((t_record_mask_qi)record)[0]);
}

static inline float __attribute__((CONST,CLONE,ARCH))
	hit_distance(register const t_record_sf record)
{
	return ((record)[1]);
}

static char __attribute__((CONST,ARCH))
	type_select(register const union u_hitables hitables)
{
	return ((char[]){ 0,
			(char)(type(*(hitables.sphere.material))),
			(char)(type(*(hitables.cone.material))),
			(char)(type(*(hitables.cylinder.material))),
			(char)(type(*(hitables.tetrahedron.material))),
			(char)(type(*(hitables.plane.material))), 0
		}[hitables.generic.type]);
}

static t_record_sf __attribute__((CONST,ARCH))
	record_select(register const union u_hitables hitables,
				register const t_ray_sf ray,
				register const t_v2sf time,
				register const t_record_sf currect_record)
{
	if (hitables.generic.type == SPHERE)
		return (hit(*(hitables.sphere.self), ray, time, currect_record));
	else if (hitables.generic.type == CONE)
		return (hit(*(hitables.cone.self), ray, time, currect_record));
	else if (hitables.generic.type == CYLINDER)
		return (hit(*(hitables.cylinder.self), ray, time, currect_record));
	else if (hitables.generic.type == TETRAHEDRON)
		return (hit(*(hitables.tetrahedron.self), ray, time, currect_record));
	else if (hitables.generic.type == PLANE)
		return (hit(*(hitables.plane.self), ray, time, currect_record));
	return (0);
}

t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit(register const union u_hitables *restrict hitables,
		register const t_ray_sf ray,
		register const float t_min,
		register const float t_max)
{
	register union u_record_helper	currect_record;
	register t_record_sf			return_candidate;
	register size_t					i;
	register float					closest_so_far;

	currect_record.sf = (const t_record_sf){ 0 };
	return_candidate = (const t_record_sf){ 0 };
	closest_so_far = t_max;
	i = ~0UL;
	while (++i < hitables->generic.count)
		if (hitables[i].generic.type != MATERIAL_START)
		{
			currect_record.sf = record_select(hitables[i], ray,
				vec(t_min, closest_so_far), currect_record.sf);
			if (hit_condition(currect_record.sf)
			&& hit_distance(currect_record.sf) < closest_so_far)
			{
				closest_so_far = hit_distance(currect_record.sf);
				currect_record.qi[1] = type_select(hitables[i]);
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
