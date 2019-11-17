/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:08:02 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 04:08:06 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "radius.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	radius(const t_sphere_sf s)
{
	return (s.hi);
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	radius(const t_sphere_df s)
{
	return (s.hi);
}

t_v3sf __attribute__((PURE,CLONE,ARCH))
	radius(const struct s_sphere_sf *const restrict s)
{
	return (s->radius);
}

t_v3df __attribute__((PURE,CLONE,ARCH))
	radius(const struct s_sphere_df *const restrict s)
{
	return (s->radius);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
