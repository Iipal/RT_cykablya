/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:03:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 12:49:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double_t	add_mnt_delimeter(size_t mnt_digits)
{
	double_t	out;

	out = 1.0f;
	while (mnt_digits--)
		out *= 10.0f;
	return (out);
}

double_t		ft_atof(char const *str)
{
	const int64_t	exp = ft_atol(str);
	int64_t			mnt;
	size_t			mnt_digits;
	size_t			i;
	double			s;

	i = ~0UL;
	mnt = 0;
	mnt_digits = 0;
	s = ('-' == *str) ? -1.0 : 1.0;
	((!exp) && (-1 == s)) ? ++str : str;
	str += ft_digits(exp);
	if ('.' == *str++)
	{
		while (str[++i] && F_ISDIGIT(str[i]))
			++mnt_digits;
		mnt = ft_atol(str);
		if (ft_digits(mnt) > mnt_digits)
			mnt_digits = 0;
		else
			mnt_digits -= ft_digits(mnt);
	}
	return (exp + (mnt / add_mnt_delimeter(ft_digits(mnt) + mnt_digits) * s));
}
