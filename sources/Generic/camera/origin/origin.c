/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:16:58 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:17:00 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "camera_origin.h"
# define TLS_VEC _Thread_local t_v3sf
#endif

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*origin(void)
{
	static TLS_VEC	coord = { 0.0f, 0.0f, 0.0f };

	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*origin(register const t_v3sf vec)
{
	static TLS_VEC	coord;

	coord = vec;
	return (&coord);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
