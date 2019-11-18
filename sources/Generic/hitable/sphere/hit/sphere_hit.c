/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:47:26 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/17 04:08:09 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "sphere_hit.h"
#endif

t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit(register const t_sphere_sf sphere,
		register const t_ray_sf ray,
		register const t_v2sf time,
		register const t_record_sf current_record)
{
	const t_v3sf	oc = origin(ray) - center(sphere);
	const float		a = length_squared(direction(ray));
	const float		b = dot(oc, direction(ray));
	const float		d = discriminant(a, b, oc, radius(sphere));
	float			solution;

	if (d > 0.0f)
	{
		solution = (-b - sqroot(d)) / a;
		if ((solution < time.y)
		&& (solution > time.x))
		{
			return (record(solution, point_at_parameter(ray, solution),
					center(sphere), radius(sphere)));
		}
		solution = (-b + sqroot(d)) / a;
		if ((solution < time.y)
		&& (solution > time.x))
			return (record(solution, point_at_parameter(ray, solution),
							center(sphere), radius(sphere)));
	}
	return (record(current_record));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
