/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:45:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/09/02 21:52:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int32_t n, int32_t const fd)
{
	size_t	n_len;
	char	tmp[24];
	bool	is_neg;

	is_neg = false;
	n_len = ft_digits(n);
	ft_bzero(tmp, sizeof(tmp));
	if (0L > n)
	{
		tmp[is_neg] = '-';
		is_neg = true;
		n = -n;
	}
	while (is_neg != n_len--)
	{
		tmp[n_len] = (n % 10L) + 0x30L;
		if (n)
			n /= 10L;
	}
	ft_putstr_fd(tmp, fd);
}
