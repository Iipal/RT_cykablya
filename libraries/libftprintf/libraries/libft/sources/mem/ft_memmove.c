/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:43:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/05 16:07:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *const dest, void const *const src, size_t len)
{
	uint8_t *const	dst = (uint8_t *const)dest;
	uint8_t *const	sc = (uint8_t *const)src;
	size_t			i;

	i = ~0UL;
	if (sc < dst)
		while (--len)
			dst[len] = sc[len];
	else
		while (++i < len)
			dst[i] = sc[i];
	return (dest);
}
