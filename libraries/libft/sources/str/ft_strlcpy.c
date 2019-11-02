/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:20:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/24 15:57:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *const dest,
			char const *const str,
			size_t const dstsize)
{
	size_t const	strsize = ft_strlen(str);

	if (strsize < dstsize)
		ft_memcpy(dest, (void const *const)str, strsize + 1);
	else if (dstsize)
	{
		ft_memcpy(dest, (void const *const)str, dstsize - 1);
		dest[dstsize - 1] = '\0';
	}
	return (strsize);
}
