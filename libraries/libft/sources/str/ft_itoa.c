/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:33:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 11:02:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_utils.h"

char	*ft_itoa(int32_t n)
{
	char	*out;
	int32_t	len;
	bool	sign;

	sign = 0 > n ? true : false;
	len = ft_digits(n);
	if (!(out = ft_strnew(len)))
		return (out);
	while (len--)
	{
		out[len] = (sign ? -(n % 0xA) : n % 0xA) + 0x30;
		n /= 0xA;
	}
	*out = sign ? '-' : *out;
	return (out);
}