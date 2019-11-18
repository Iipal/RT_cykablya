/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsqroot1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:57:01 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:57:02 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "rsqroot.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const float x)
{
	return (1.0f / asm_sqrtf(x));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const double x)
{
	return (1.0 / asm_sqrt(x));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
