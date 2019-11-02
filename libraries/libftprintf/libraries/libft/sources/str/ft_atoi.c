/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:11:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 10:21:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_atoi(char const *str)
{
	int32_t	num;
	int32_t	sign;

	str += ft_skip_blanks(str);
	num = 0;
	sign = ('-' == *str) ? -1 : 1;
	if ('-' == *str || '+' == *str)
		++str;
	while (F_ISDIGIT(*str))
		num = num * 0xA + *(str++) - 0x30;
	return (num * sign);
}
