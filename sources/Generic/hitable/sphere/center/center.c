/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:06:14 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 04:06:15 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "center.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	center(register const t_sphere_sf s)
{
	return (s.lo);
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	center(register const t_sphere_df s)
{
	return (s.lo);
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	center(const struct s_sphere_sf *const restrict s)
{
	return (s->center);
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	center(const struct s_sphere_df *const restrict s)
{
	return (s->center);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
