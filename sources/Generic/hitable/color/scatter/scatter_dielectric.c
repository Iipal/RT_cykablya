/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter_dielectric.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:36:20 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 03:36:23 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "color.h"
#endif

static float __attribute__((CONST,SMALL_STACK,ARCH))
	schlick(register float cosine, register float ri)
{
	size_t					i;
	register float			r0;
	register float			pow_5;
	const register float	base = (1.0f - cosine);

	r0 = (1.0f - ri) / (1.0f + ri);
	r0 = r0 * r0;
	i = 4UL;
	pow_5 = (1.0f - cosine);
	while (i--)
		pow_5 *= base;
	return (r0 + (1.0f - r0) * pow_5);
}

static t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
	scatter_dielectric_pos(
		register const union u_hitables *restrict hitables,
		register const t_record_sf record,
		register const t_ray_sf r,
		register const size_t depth)
{
	register t_ray_sf	scattered;
	float				refracted;

	refracted = refract_cond(normalize(direction(r)),
		-normal(record), ri(*(hitables[iter(record)].sphere.material)));
	if (refracted >= 0.0f)
		scattered = (random_float()
		< schlick(ri(*(hitables[iter(record)].sphere.material))
		* dot(direction(r), normal(record)) / length(direction(r)),
		ri(*(hitables[iter(record)].sphere.material))))
		? ray(point(record), reflect(normalize(direction(r)), normal(record)))
		: ray(point(record), refract_do(normalize(direction(r)),
		-normal(record),
		ri(*(hitables[iter(record)].sphere.material)), refracted));
	else
		scattered = (random_float() < 1.0f)
		? ray(point(record), reflect(normalize(direction(r)), normal(record)))
		: ray(point(record), refract_do(normalize(direction(r)),
		-normal(record), ri(*(hitables[iter(record)].sphere.material)),
		refracted));
	return ((albedo(*(hitables[iter(record)].sphere.material)))
			* color(scattered, hitables, depth + 1UL));
}

static t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
	scatter_dielectric_neg(
		register const union u_hitables *restrict hitables,
		register const t_record_sf record,
		register const t_ray_sf r,
		register const size_t depth)
{
	register t_ray_sf	scattered;
	float				refracted;

	refracted = refract_cond(normalize(direction(r)),
	normal(record), (1.0f / ri(*(hitables[iter(record)].sphere.material))));
	if (refracted >= 0.0f)
		scattered = (random_float() < schlick(-dot(direction(r),
		normal(record)) / length(direction(r)),
		ri(*(hitables[iter(record)].sphere.material))))
		? ray(point(record), reflect(normalize(direction(r)), normal(record)))
		: ray(point(record), refract_do(normalize(direction(r)),
		normal(record), (1.0f / ri(*(hitables[iter(record)].sphere.material))),
		refracted));
	else
		scattered = (random_float() < 1.0f)
		? ray(point(record), reflect(normalize(direction(r)), normal(record)))
		: ray(point(record), refract_do(normalize(direction(r)),
		normal(record), (1.0f / ri(*(hitables[iter(record)].sphere.material))),
		refracted));
	return ((albedo(*(hitables[iter(record)].sphere.material)))
			* color(scattered, hitables, depth + 1UL));
}

t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
	scatter_dielectric(
		register const union u_hitables *restrict hitables,
		register const t_record_sf record,
		register const t_ray_sf r,
		register const size_t depth)
{
	if (depth < 32UL)
	{
		if (dot(direction(r), normal(record)) > 0.0f)
			return (scatter_dielectric_pos(hitables, record, r, depth));
		else
			return (scatter_dielectric_neg(hitables, record, r, depth));
	}
	return (0);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
