/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:47:49 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:47:50 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "direction.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	direction(register const t_ray_sf r)
{
	return (r.hi);
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	direction(const t_ray_df r)
{
	return (r.hi);
}

t_v3sf __attribute__((PURE,CLONE,ARCH))
	direction(const struct s_ray_sf *const restrict r)
{
	return (r->b);
}

t_v3df __attribute__((PURE,CLONE,ARCH))
	direction(const struct s_ray_df *const restrict r)
{
	return (r->b);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
