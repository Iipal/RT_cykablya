/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:47:38 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:47:39 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "origin.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	origin(register const t_ray_sf r)
{
	return (r.lo);
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	origin(const t_ray_df r)
{
	return (r.lo);
}

t_v3sf __attribute__((PURE,CLONE,ARCH))
	origin(const struct s_ray_sf *const restrict r)
{
	return (r->a);
}

t_v3df __attribute__((PURE,CLONE,ARCH))
	origin(const struct s_ray_df *const restrict r)
{
	return (r->a);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
