/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_add4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:53:31 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:53:35 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "reduce_add.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reduce_add(register const t_v4sf vec)
{
	return (asm_reduce_add_v4sf(vec));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reduce_add(register const t_v4df vec)
{
	return (asm_reduce_add_v4df(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
