/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:23:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 13:17:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_ishex_str(char *str)
{
	size_t		i;
	char const	valid_hex[] = "0123456789abcdef";

	i = 0UL;
	while (str && *str)
	{
		i = ~0UL;
		while (valid_hex[++i])
			if (F_TOLOWER(*str) == valid_hex[i])
				break ;
		if (F_TOLOWER(*str) != valid_hex[i])
			return (false);
		++str;
	}
	return (true);
}
