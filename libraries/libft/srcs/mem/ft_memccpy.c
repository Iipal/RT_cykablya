/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 02:13:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *const dest,
			void const *const src,
			uint8_t const c,
			size_t const n)
{
	uint8_t	*const	dst = (uint8_t *const)dest;
	uint8_t	*const	sc = (uint8_t *const)src;
	size_t			i;

	i = ~0UL;
	while (n > ++i)
	{
		dst[i] = sc[i];
		if (sc[i] == c)
			return (dst + i + 1);
	}
	return (NULL);
}
