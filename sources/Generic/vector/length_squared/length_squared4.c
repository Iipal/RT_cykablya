/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_squared4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:50:25 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:50:26 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "length_squared.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	length_squared(register const t_v4sf vec)
{
	return (dot(vec, vec));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	length_squared(register const t_v4df vec)
{
	return (dot(vec, vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
