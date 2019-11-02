/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:07:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 00:50:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalpha_str(char const *const str)
{
	size_t	i;

	i = ~0UL;
	while (str[++i])
		if (!F_ISALPHA(str[i]))
			return (false);
	return (true);
}
