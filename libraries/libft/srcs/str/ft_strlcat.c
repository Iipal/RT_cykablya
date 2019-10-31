/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 10:40:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *const dest,
			char const *const src,
			size_t const dstsize)
{
	char	*sc;
	char	*dst;
	size_t	n;
	size_t	dlen;

	dst = dest;
	sc = (char*)src;
	n = dstsize;
	while (n-- && *dst++)
		;
	dlen = dst - dest;
	n = dstsize - dlen;
	NO_R(n, dlen + ft_strlen(sc));
	while (*sc != '\0')
	{
		if (n != 1)
		{
			*dst++ = *sc;
			n--;
		}
		++sc;
	}
	*dst = '\0';
	return (dlen + (sc - src));
}
