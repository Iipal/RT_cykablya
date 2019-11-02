/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:04:50 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/11 01:21:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *const src, size_t const n)
{
	int8_t *const		dst = (int8_t *const)dest;
	int8_t const *const	sc = (int8_t const *const)src;
	size_t				i;

	i = ~0UL;
	while (++i < n)
		dst[i] = sc[i];
	return (dest);
}
