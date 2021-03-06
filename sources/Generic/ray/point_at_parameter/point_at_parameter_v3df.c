/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_at_parameter_v3df.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:48:06 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:48:07 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "point_at_parameter.h"
#endif

t_v3df __attribute__((CONST,CLONE,ARCH))
	point_at_parameter(register const struct s_ray_df *const restrict r,
						register const double t)
{
	return (origin(r) + (t * direction(r)));
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	point_at_parameter(register const struct s_ray_df *const restrict r,
						const t_v3df t)
{
	return (origin(r) + (t * direction(r)));
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	point_at_parameter(const t_ray_df r, register const double t)
{
	return (origin(r) + (t * direction(r)));
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	point_at_parameter(const t_ray_df r, register const t_v3df t)
{
	return (origin(r) + (t * direction(r)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
