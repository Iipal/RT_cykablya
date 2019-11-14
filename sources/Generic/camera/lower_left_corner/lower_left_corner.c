/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_left_corner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:16:43 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:16:44 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "lower_left_corner.h"
# define TLS_VEC _Thread_local t_v3sf
#endif

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*lower_left_corner(void)
{
	static TLS_VEC	coord = { -2.0f, -1.0f, -1.0f };

	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*lower_left_corner(register const float half_width,
						register const float half_height)
{
	static TLS_VEC	coord;

	coord = vec(-half_width, -half_height, -1.0f);
	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*lower_left_corner(register const t_v3sf vec)
{
	static TLS_VEC	coord;

	coord = vec;
	return (&coord);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
