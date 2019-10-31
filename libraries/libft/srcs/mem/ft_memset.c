/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:17:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 02:06:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *const dest, int32_t const c, size_t len)
{
	uint8_t	*out;

	out = (uint8_t*)dest;
	while (len--)
		*out++ = c;
	return (dest);
}
