/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one_of_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:08:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/15 21:11:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_is_one_of_str(char const *cmp, size_t const n, ...)
{
	char	*temp;
	va_list	ap;
	size_t	i;
	bool	is_one_of;

	i = ~0UL;
	va_start(ap, n);
	is_one_of = false;
	while (!is_one_of && n > ++i)
	{
		temp = va_arg(ap, char*);
		if (!ft_strcmp(cmp, temp))
			is_one_of = true;
	}
	va_end(ap);
	return (is_one_of ? (i + 1UL) : 0UL);
}
