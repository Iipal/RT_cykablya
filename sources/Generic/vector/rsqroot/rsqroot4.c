/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsqroot4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:57:32 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:57:33 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "rsqroot.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const t_v4sf x)
{
	return (asm_v4sf_rsqroot(x));
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const t_v4df x)
{
	const t_v4df	one = (const t_v4df){ 1.0, 1.0, 1.0, 1.0 };

	return (one / __builtin_ia32_sqrtpd256(x));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
