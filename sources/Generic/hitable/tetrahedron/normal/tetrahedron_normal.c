/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:08:56 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 04:08:58 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "tetrahedron_normal.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_tetrahedron_sf t)
{
	return (normalize(cross(
		plane_b(t) - plane_a(t),
		plane_c(t) - plane_a(t))));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
