/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:45:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 11:31:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char const *const str, size_t const len)
{
	size_t	j;
	size_t	i;

	i = 0UL;
	j = ~0UL;
	while (len > i)
		if (!str[i])
			dest[++j] = 0;
		else
			dest[++j] = str[i++];
	return (dest);
}
