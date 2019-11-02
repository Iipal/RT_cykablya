/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:46:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 12:52:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	add_is_valid(char const c, int8_t base, char const valid[])
{
	while (base--)
		if (valid[base] == F_TOLOWER(c))
			return (true);
	return (false);
}

static char	add_value_of(uint8_t c)
{
	char	out;

	out = 0;
	if (F_ISDIGIT(c))
		out = c - 0x30;
	else if (F_ISLOWER(c))
		out = c - 0x61 + 0xA;
	else if (F_ISUPPER(c))
		out = c - 0x41 + 0xA;
	return (out);
}

int32_t		ft_atoi_base(char const *str, int8_t const base)
{
	int32_t		num;
	int8_t		sign;
	char const	valid_hex[] = "0123456789abcdef";

	str += ft_skip_blanks(str);
	num = 0;
	sign = (*str == '-') ? -1 : 1;
	if ('-' == *str || '+' == *str)
		++str;
	while (add_is_valid(*str, base, valid_hex))
		num = num * base + add_value_of(*str++);
	return (num * sign);
}
