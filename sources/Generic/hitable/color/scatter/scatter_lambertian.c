/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter_lambertian.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:36:35 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 03:36:36 by sshevchu         ###   ########.fr       */
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
	register t_v3sf		p;

	while (1.0f <= length_squared(p = 2.0f
		* vec(random_float(), random_float(), random_float()) - 1.0f))
		;
	return (p);
}

t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
	scatter_labmbertian(
		register const union u_hitables *restrict hitables,
		register const t_record_sf record,
		register const t_v3sf attenuation,
		register const size_t depth)
{
	if (depth < 32UL)
		return (attenuation * color(ray(point(record),
		point(record) + normal(record)
		+ random_in_unit_sphere() - point(record)),
		hitables, depth + 1UL));
	else
		return (vec(0.0f, 0.0f, 0.0f));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
