/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:36:02 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 03:36:06 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "color.h"
#endif

static _Bool __attribute__((CONST,SMALL_STACK,ARCH))
	gi(register const union u_hitables *restrict hitables)
{
	return (!!(hitables->generic.self));
}

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	color(register const t_ray_sf r,
		register const union u_hitables *restrict hitables,
		register const size_t depth)
{
	register const t_record_sf	record = hit(hitables, r, 0.001f, __FLT_MAX__);
	const t_v3sf				f = (normalize(direction(r)).y + 1.0f) * 0.5f;

	if (condition(record) && material(record) == EMITTER)
		return (albedo(*(hitables[iter(record)].sphere.material)));
	else if (condition(record) && (material(record) == NORMAL))
		return (normal(record) * (normal(record) + normal(record)));
	else if (condition(record) && (material(record) == COLOR))
		return (albedo(*(hitables[iter(record)].sphere.material)));
	else if (condition(record) && (material(record) == LAMBERTIAN))
		return (scatter_labmbertian(hitables, record,
			albedo(*(hitables[iter(record)].sphere.material)), depth));
	else if (condition(record) && (material(record) == METAL))
		return (scatter_metal(hitables, record, r, depth));
	else if (condition(record) && (material(record) == DIELECTRIC))
		return (scatter_dielectric(hitables, record, r, depth));
	else if (gi(hitables))
		return (1.0f - f + vec(0.5f, 0.7f, 1.0f) * f);
	else
		return (0);
}

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	color(register const t_ray_sf r,
		register const union u_hitables *restrict hitables)
{
	register const t_record_sf	record = hit(hitables, r, 0.0f, __FLT_MAX__);
	const t_v3sf				normal_direction = normalize(direction(r));
	const t_v3sf				factor = (normal_direction.y + 1.0f) * 0.5f;
	const _Bool					condition = ((t_record_mask_qi)record)[0];

	if (condition)
		return (0.5f * (1.0f + vec(record[5], record[6], record[7])));
	else
		return (1.0f - factor + vec(0.5f, 0.7f, 1.0f) * factor);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
