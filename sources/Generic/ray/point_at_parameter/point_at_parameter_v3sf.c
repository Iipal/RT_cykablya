/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_at_parameter_v3sf.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:48:23 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:48:24 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "point_at_parameter.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	point_at_parameter(register const struct s_ray_sf *const restrict r,
						register const float t)
{
	return (origin(r) + (t * direction(r)));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	point_at_parameter(register const struct s_ray_sf *const restrict r,
						register const t_v3sf t)
{
	return (origin(r) + (t * direction(r)));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	point_at_parameter(register const t_ray_sf r, register const float t)
{
	return (origin(r) + (t * direction(r)));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	point_at_parameter(register const t_ray_sf r, register const t_v3sf t)
{
	return (origin(r) + (t * direction(r)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
