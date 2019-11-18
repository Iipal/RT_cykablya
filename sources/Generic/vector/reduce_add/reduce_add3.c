/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_add3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:53:40 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:53:41 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "reduce_add.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reduce_add(register const t_v3sf vec)
{
	return (asm_reduce_add_v3sf(vec));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reduce_add(register const t_v3df vec)
{
	return (asm_reduce_add_v3df(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
