/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one_of_strn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:08:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 09:47:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_is_one_of_strn(const char *restrict cmp, size_t n, ...)
{
	char	*temp;
	va_list	ap;
	size_t	i;

	i = ~0UL;
	va_start(ap, n);
	while (n > ++i)
	{
		temp = va_arg(ap, char*);
		if (!ft_strncmp(cmp, temp, ft_strlen(temp)))
		{
			va_end(ap);
			return (i + 1UL);
		}
	}
	return (0UL);
}
