/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i128toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:22:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 11:03:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_utils.h"

char					*ft_i128toa(__int128 n)
{
	char		*out;
	__int128	len;
	bool		sign;

	sign = 0 > n ? true : false;
	len = ft_digits(n);
	if (!(out = ft_strnew(len + sign)))
		return (out);
	while (len--)
	{
		out[len] = (sign ? -(n % 0xA) : n % 0xA) + 0x30;
		n /= 0xA;
	}
	*out = sign ? '-' : *out;
	return (out);
}
