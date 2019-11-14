/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:51:14 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:51:15 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "normalize.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	normalize(register const t_v3sf x)
{
	return (x * rsqroot(vec_length_squared(x)));
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	normalize(register const t_v3df x)
{
	return (x * rsqroot(vec_length_squared(x)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
