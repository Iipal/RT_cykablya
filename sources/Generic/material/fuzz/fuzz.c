/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuzz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:18:12 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:18:14 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "fuzz.h"
#endif

float __attribute__((CONST,SMALL_STACK,ARCH))
	fuzz(register const t_material_sf material)
{
	return (material[5]);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
