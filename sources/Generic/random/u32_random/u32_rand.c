/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u32_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:39:15 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:39:27 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "u32_rand.h"
# define TLS_U32 _Thread_local uint32_t
#endif

uint32_t	u32_rand(void)
{
	static TLS_U32	x = 123456789U;
	static TLS_U32	y = 362436069U;
	static TLS_U32	z = 521288629U;
	static TLS_U32	w = 88675123U;
	const uint32_t	t = x ^ (x << 11U);

	x = y;
	y = z;
	z = w;
	return (w = w ^ (w >> 19U) ^ (t ^ (t >> 8U)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
