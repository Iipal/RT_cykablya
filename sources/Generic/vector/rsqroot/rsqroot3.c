/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsqroot3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:57:26 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:57:27 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "rsqroot.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const t_v3sf x)
{
	return (asm_v3sf_rsqroot(x));
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const t_v3df x)
{
	const t_v4df	one = (const t_v4df){ 1.0, 1.0, 1.0, 1.0 };
	const t_v4df	t = (const t_v4df){ x.x, x.y, x.z };
	const t_v4df	result = one / __builtin_ia32_sqrtpd256(t);

	return (*(const t_v3df*)&result);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
