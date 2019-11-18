/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:08:20 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 04:08:22 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "tetrahedron_constructor.h"
#endif

t_tetrahedron_sf __attribute__((CONST,CLONE,ARCH))
	tetrahedron(register const t_v3sf a,
				register const t_v3sf b,
				register const t_v3sf c)
{
	return ((t_tetrahedron_sf){ a.x, a.y, a.z,
								b.x, b.y, b.z,
								c.x, c.y, c.z });
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
