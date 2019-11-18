/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqroot4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:58:06 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:58:07 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "sqroot.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const t_v4sf vec)
{
	return (asm_v4sf_sqrtf(vec));
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const t_v4df vec)
{
	return (asm_v4df_sqrt(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
