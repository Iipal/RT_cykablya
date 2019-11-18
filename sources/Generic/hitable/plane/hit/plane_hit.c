/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:03:43 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 04:03:44 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "plane_hit.h"
#endif

static _Bool __attribute__((CONST,CLONE,ARCH))
	is_inside(register const t_plane_sf p,
			register const t_v3sf q)
{
	return (
	(dot(cross(plane_b(p) - plane_a(p), q - plane_a(p)), normal(p)) > 0)
	&& (dot(cross(plane_c(p) - plane_b(p), q - plane_b(p)), normal(p)) > 0)
	&& (dot(cross(plane_d(p) - plane_c(p), q - plane_c(p)), normal(p)) > 0)
	&& (dot(cross(plane_a(p) - plane_d(p), q - plane_d(p)), normal(p)) > 0));
}

t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit(register const t_plane_sf plane,
		register const t_ray_sf ray,
		register const t_v2sf time,
		register const t_record_sf current_record)
{
	const t_v3sf	n = normal(plane);
	const t_v3sf	v_dif = plane_a(plane) - origin(ray);
	const float		v_dot_n = dot(direction(ray), n);
	float			t;

	if (__builtin_fabsf(v_dot_n) < 1.e-4f)
		return (record(current_record));
	t = dot(v_dif, n) / v_dot_n;
	if (__builtin_fabsf(t) < 0.0001f)
		return (record(current_record));
	if ((t < time.y) && (t > time.x)
	&& is_inside(plane, point_at_parameter(ray, t)))
		return (record(t, point_at_parameter(ray, t),
			normal(plane)));
	else
		return (record(current_record));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
