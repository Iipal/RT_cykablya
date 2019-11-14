/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reduce_add2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:59:49 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:59:50 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vec_reduce_add.h"
#endif

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_reduce_add(register const t_v2sf vec)
{
	return (asm_v2sf_reduce_add(vec));
}

t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_reduce_add(register const t_v2df vec)
{
	return (asm_v2df_reduce_add(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
