/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter_metal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:36:46 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 03:36:47 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "scatter.h"
#endif

static t_v3sf __attribute__((SMALL_STACK,ARCH))
	random_in_unit_sphere(void)
{
	t_v3sf					p;

	while (1.0f <= length_squared(p = 2.0f
		* vec(random_float(), random_float(), random_float()) - 1.0f))
		;
	return (p);
}

t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
	scatter_metal(
		register const union u_hitables *restrict hitables,
		register const t_record_sf record,
		register const t_ray_sf r,
		register const size_t depth)
{
	register t_ray_sf	scattered;

	if (depth < 32UL)
	{
		scattered = ray(point(record),
		reflect(normalize(direction(r)), normal(record))
		+ fuzz(*(hitables[iter(record)].sphere.material))
		* random_in_unit_sphere());
		if (dot(direction(scattered), normal(record)) > 0.0f)
			return (albedo(*(hitables[iter(record)].sphere.material))
			* color(scattered, hitables, depth + 1UL));
		else
			return (albedo(*(hitables[iter(record)].sphere.material)));
	}
	else
		return (vec(0.0f, 0.0f, 0.0f));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
