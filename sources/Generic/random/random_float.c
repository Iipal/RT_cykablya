/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:22:14 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:22:15 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "random_float.h"
#endif

float __attribute__((ARCH,CLONE,ALIGN))
	random_float(void)
{
	const unsigned	rnd = u32_rand();

	return ((float)rnd / 5e9f);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
