/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqroot3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:58:00 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:58:01 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "sqroot.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const t_v3sf vec)
{
	return (asm_v3sf_sqrtf(vec));
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const t_v3df vec)
{
	return (asm_v3df_sqrt(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
